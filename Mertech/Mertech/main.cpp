#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <map>
#include <string>
#include <sstream>
#include <functional>
#include <algorithm>
#include <regex>
#include <fstream>
#include <ctime>

constexpr auto SPACE = ' ';
constexpr auto tab = '\t';

class Task;
template <typename IS>
class TaskManager;

class Task {
	std::string title;
	std::string description;
	std::string date;
	std::string category;
	std::string status;
public:
	Task(std::vector<std::string>& parameters) {
		title = parameters[0];
		description = parameters[1];
		date = parameters[2];
		category = parameters[3];
		status = "new";
		std::cout << "Task " << title << " successfully added" << std::endl;
	}

	Task() = default;
	Task& operator=(const Task&) = delete;
	Task& operator=(Task&&) noexcept = delete;

	Task(const Task& tempTask) :
		title{ tempTask.title },
		description{ tempTask.description },
		date{ tempTask.date },
		category{ tempTask.category } {	}

	Task(Task&& tempTask) noexcept :
		title{ tempTask.title },
		description{ tempTask.description },
		date{ tempTask.date },
		category{ tempTask.category } {	}

	const std::string& getTitle() const {
		return title;
	}
	const std::string& getDescription() const {
		return description;
	}
	const std::string& getDate() const {
		return date;
	}
	const std::string& getCategory() const {
		return category;
	}
	const std::string& getStatus() const {
		return status;
	}

	void setTitle(const std::string& title) {
		this->title = title;
		std::cout << "New title : " << title << std::endl;
	}
	void setDescription(const std::string& description) {
		this->description = description;
		std::cout << "New description : " << description << std::endl;
	}
	void setDate(const std::string& date) {
		this->date = date;
		std::cout << "New date : " << date << std::endl;
	}
	void setCategory(const std::string& category) {
		this->category = category;
		std::cout << "New category: " << category << std::endl;
	}
	void setStatus(const std::string& status) {
		this->status = status;
		std::cout << "New status : " << status << std::endl;
	}

	std::string operator()(const std::string& field) const {
		if (field == "title") return this->getTitle();
		if (field == "description") return this->getDescription();
		if (field == "date") return this->getDate();
		if (field == "category") return this->getCategory();
		if (field == "status") return this->getStatus();
		return std::string("Unknown field");
	}

	~Task() {}
};

std::ostream& operator<<(std::ostream& os, const Task& task) {
	os << "Title: " << task.getTitle()
		<< " Description: " << task.getDescription()
		<< " Date: " << task.getDate()
		<< " Category: " << task.getCategory()
		<< " Status: " << task.getStatus();
	return os;
}

template <typename IS>
class TaskManager {
	std::map<std::string, std::function<void()>> command;
	std::map<std::string, Task> tasks;
	std::vector<std::string> parameters;
public:
	TaskManager()
	{
		command["add"] = std::bind(&TaskManager::addTask, this);
		command["done"] = std::bind(&TaskManager::doneTask, this);
		command["update"] = std::bind(&TaskManager::updateTask, this);
		command["delete"] = std::bind(&TaskManager::deleteTask, this);
		command["select*"] = std::bind(&TaskManager::selectTask, this);
		parameters.reserve(4);
	}

	void ReadingData(IS& is) {
		for (std::string line; getline(is, line);) {
			if (isStringValid(line)) {
				stringToLowerCase(line);
				std::istringstream iss{ line };
				std::istream_iterator<std::string> _begin{ iss };
				std::istream_iterator<std::string> _end{ };
				std::string comm{ selectHelper(*_begin) };
				if (command.count(comm)) {
					for (auto&& it = std::next(_begin); it != _end; ++it)
						parameters.push_back(*it);
					command[comm]();
					parameters.clear();
				}
				else if (*_begin == "exit") break;
				else std::cout << "Unknown command : " << selectHelper(*_begin) << std::endl;
			}
		}
	}

	void ReadingConsole() {
		ReadingData(std::cin);
	}

	void ReadingFile(const char* file_) {
		IS file(file_);
		if (!file.is_open()) {
			std::cout << "File " << file_ << " not found!" << std::endl;
			this->~TaskManager();
		}
		ReadingData(file);
		file.close();
	}

	bool isStringValid(const std::string& str) const {
		return (!str.empty() && str.find_first_not_of(SPACE) != std::string::npos);
	}

	bool isParameterValid(const size_t n) const {
		if (parameters.size() < n)
		{
			std::cout << "Too few parameters" << std::endl;
			return false;
		}
		if (parameters.size() > n) {
			std::cout << "Too many parameters" << std::endl;
			return false;
		}
		return true;
	}

	void printAll() const {
		for (const auto&& t : tasks) {
			std::cout << t.second;
		}
	}

	void stringToLowerCase(std::string& str) {
		std::transform(std::begin(str),
			std::end(str),
			std::begin(str),
			::tolower);
	}

	void addTask() {
		if (isParameterValid(4)) {
			if (tasks.find(parameters[0]) == tasks.end())
				tasks.emplace(parameters[0], parameters);
			else std::cout << "Task " << parameters[0] << " already exists" << std::endl;
		}
	}

	void doneTask() {
		if (isParameterValid(1)) {
			if (tasks.find(parameters[0]) != tasks.end()) {
				tasks[parameters[0]].setStatus("done");
			}
			else std::cout << "Task " << parameters[0] << " not found" << std::endl;
		}
	};

	bool updateHelper(const char* field) {
		std::cout << tab << field << ": ";
		getline(std::cin, parameters[0]);
		if (isStringValid(parameters[0]))
			return true;
		return false;
	}

	void updateTask() {
		if (isParameterValid(1)) {
			std::string updatetask{ parameters[0] };
			if (tasks.find(parameters[0]) != tasks.end())
			{
				std::cout << parameters[0] << " -> ";
				if (updateHelper("Title")) {
					auto _temp{ tasks.extract(updatetask) };
					_temp.key() = parameters[0];
					tasks.insert(std::move(_temp));
					std::cout << tab;
					tasks[parameters[0]].setTitle(parameters[0]);
				}
				if (updateHelper("Description")) {
					std::cout << tab;
					tasks[parameters[0]].setDescription(parameters[0]);
				}
				if (updateHelper("Date")) {
					std::cout << tab;
					tasks[parameters[0]].setDate(parameters[0]);
				}
				if (updateHelper("Category")) {
					std::cout << tab;
					tasks[parameters[0]].setCategory(parameters[0]);
				}
				if (updateHelper("Status")) {
					std::cout << tab;
					tasks[parameters[0]].setStatus(parameters[0]);
				}
			}
			else std::cout << "Task " << updatetask << " not found" << std::endl;
		}
	};

	void deleteTask() {
		if (isParameterValid(1)) {
			if (tasks.find(parameters[0]) != tasks.end()) {
				tasks.erase(parameters[0]);
				std::cout << "Task \'" << parameters[0] << "\' successfully terminated" << std::endl;
			}
			else std::cout << "Task " << parameters[0] << " not found" << std::endl;
		}
	};

	std::string selectHelper(const std::string& str) const {
		if ((str.find("select") != std::string::npos &&
			str.find('*') != std::string::npos &&
			str.find('*') < str.find("where")) ||
			str.find("select") != std::string::npos)
			return std::string{ "select*" };
		return str;
	}

	void selectTask() {

		std::string condition;
		std::vector<std::string> fields, ops, datas, ands;

		for (auto& i : parameters)
			condition += i;

		std::regex field{ "(title|description|date|category|status)" };
		for (std::sregex_iterator iBegin{ condition.begin(),condition.end(),field }, iEnd;
			iBegin != iEnd;
			++iBegin)
			fields.push_back(iBegin->str());

		std::regex op{ "(<=|>=|!=|<|>|=|like)" };
		for (std::sregex_iterator iBegin{ condition.begin(),condition.end(),op }, iEnd;
			iBegin != iEnd;
			++iBegin)
			ops.push_back(iBegin->str());

		std::regex data{ "\"[0-9a-z :_-]+\"" };
		for (std::sregex_iterator iBegin{ condition.begin(),condition.end(),data }, iEnd;
			iBegin != iEnd;
			++iBegin) {
			datas.push_back(iBegin->str().substr(
				iBegin->str().find_first_not_of('\"'),
				iBegin->str().find_last_not_of('\"') -
				iBegin->str().find_first_not_of('\"') + 1));
		}

		std::regex and_{ "\"[ ]?(and)[ ]?(title|description|date|category|status)" };
		for (std::sregex_iterator iBegin{ condition.begin(),condition.end(),and_ }, iEnd;
			iBegin != iEnd;
			++iBegin)
			ands.push_back(iBegin->str());

		if (((fields.size() != ops.size() ||
			fields.size() != datas.size() ||
			ops.size() != datas.size()) ||
			ands.size() != fields.size() - 1) &&
			condition.length() != 1) {
			std::cout << "Invalid parameters" << std::endl;
			return;
		}

		if (fields.size() == 0)
		{
			for (auto& task : tasks)
				std::cout << task.second << std::endl;
			return;
		}

		bool isSatisfiesToConditions{ 0 };
		for (auto& task : tasks) {
			isSatisfiesToConditions = true;
			for (size_t i{ 0 }; i < fields.size(); ++i) {
				if (!comparator(task.second, fields[i], ops[i], datas[i])) {
					isSatisfiesToConditions = false;
					break;
				}
			}
			if (isSatisfiesToConditions)
				std::cout << task.second << std::endl;
		}
	}

	bool comparator(const Task& task,
		const std::string& field,
		const std::string& ops,
		const std::string& data) {
		if (ops == "<=") return task(field) <= data;
		if (ops == "!=") return task(field) != data;
		if (ops == ">=") return task(field) >= data;
		if (ops == "=") return task(field) == data;
		if (ops == "<") return task(field) < data;
		if (ops == ">") return task(field) > data;
		if (ops == "like") return (task(field).find(data) != std::string::npos);
		return false;
	}

	~TaskManager() {}
};

int main() {
	std::cout << "Reading from file or console?" << std::endl;
	std::cout << "File - 0, console - 1  --> ";
	if (_getch() == '0') {
		std::cout << std::endl;
		TaskManager <std::fstream>TM;
		TM.ReadingFile("example.txt");
	}
	else {
		std::cout << std::endl;
		TaskManager <std::istream>TM;
		TM.ReadingConsole();
	}
	return 0;
}
