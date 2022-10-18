#include <iostream>
#include <string>

using namespace std;

template <typename T> T* enterArray(const size_t&);
template <typename T> T* randomArray(const size_t&);
template <typename T, typename Predicate> void sortArray(T*&, const size_t&, Predicate pred);
template <typename T> void printArray(T*&, const size_t&, string);
template <typename T> void deleteDublicate(T*&, size_t&);
template <typename T> T maxSum(T*&, size_t&);
template <typename T> bool Max(T*&, T*&);
template <typename T> bool Min(T*&, T*&);

int main() {
	size_t N{ 0 };
	std::cout << "Enter size of array -> ";
	cin >> N;
	auto _arr{ randomArray<int>(N) };
	printArray(_arr, N, "Random filled array<int>");
	deleteDublicate(_arr, N);
	printArray(_arr, N, "After deleting dublicate");
	std::cout << "Max sum = " << maxSum(_arr, N)<<endl;
	sortArray(_arr, N, Max<int>);
	printArray(_arr, N, "After sorting by Max");
	sortArray(_arr, N, Min<int>);
	printArray(_arr, N, "After sorting by Min");
	return 0;
}

template<typename T>
T enterArray(const size_t&_s)
{
	T* _arr{ new T[_s] };
	auto _begin{ _arr };
	auto _end{ _begin + _s };
	while (_begin != _end) {
		cout << "Enter a number -> ";
		cin >> (*_begin);
	}
	return _arr;
}

template<typename T>
T* randomArray(const size_t&_s)
{
	T* _arr{ new T[_s] };
	auto _begin{ _arr };
	auto _end{ _begin + _s };
	while (_begin != _end) {
		*_begin = rand() % 20;
		++_begin;
	}
	return _arr;
}

template<typename T, typename Predicate>
void sortArray(T*& _arr, const size_t& _s, Predicate pred)
{
	auto _begin{ _arr };
	auto _end{ _begin + _s };
	auto max{ *_begin };
	while (_begin != _end - 1) {
		max = *_begin;
		auto it = _begin + 1;
		while (it != _end) {
			if (pred(it, _begin))
				std::swap(*it, *_begin);
			++it;
		}
		++_begin;
	}
}

template<typename T>
void printArray(T*& _arr, const size_t& _s, string msg)
{
	auto _begin{ _arr };
	auto _end{ _arr + _s };
	cout << msg << " ->\t";
	while (_begin != _end) {
		std::cout << "  " << *_begin;
		++_begin;
	}
	cout << endl;
}

template<typename T>
void deleteDublicate(T*& _arr, size_t& _s)
{
	T* newArr{ new T[_s] };
	size_t newArrSize{ 0 };
	auto it_new{ newArr };
	auto it{ _arr };
	if (_s) {
		*it_new = *it;
		++it;
		++newArrSize;
	}
	while (it != _arr + _s) {
		it_new = newArr;
		while (it_new != newArr + newArrSize) {
			if (*it_new == *it) break; 
			++it_new;
		}
		if (it_new == newArr + newArrSize) {
			*it_new = *it;
			++newArrSize;
		}
		++it;
	}
	delete[] _arr;
	_s = newArrSize;
	_arr = new T[_s];
	it_new = newArr;
	it = _arr;
	while (it_new != newArr + _s) {
		*it = *it_new;
		++it;
		++it_new;
	}
	delete[] newArr;
	newArr = nullptr;
}

template<typename T>
T maxSum(T*& _arr, size_t& _s)
{
	auto _begin{ _arr };
	auto _end{ _arr + _s };
	T sum{ 0 };
	while (_begin != _end) {
		if (*_begin > 0)
			sum += *_begin;
		++_begin;
	}
	return sum;
}

template<typename T>
bool Max(T*& it1, T*& it2)
{
	if (*it1 > *it2) return true;
	else return false;
}

template<typename T>
bool Min(T*& it1, T*& it2)
{
	if (*it1 < *it2) return true;
	else return false;
}