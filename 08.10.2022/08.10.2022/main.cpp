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
	printArray(_arr, N, "After sorting by Max");
	sortArray(_arr, N, Max<int>);
	printArray(_arr, N, "After sorting by Min");
	sortArray(_arr, N, Min<int>);
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
	cout << msg << " -> ";
	while (_begin != _end) {
		std::cout << "\t" << *_begin;
		++_begin;
	}
	cout << endl;
}

template<typename T>
void deleteDublicate(T*& _arr, size_t& _s)
{
	auto _begin{ _arr };
	auto _end{ _arr + _s };
	auto it{ _arr };
	while (_begin != _end) {
		it = next(_begin);
		while (it != _end) {
			if (*it == *_begin) {
				while (*it == *(_end - 1))
					--_end;
				std::swap(*it, *_end);
			}
			++it;
		}
		++_begin;
	}
	_s = _end - _arr;
	T* newArr{ new T[_s] };
	_begin = _arr;
	it = newArr;
	while (_begin != _end) {
		*it = *_begin;
		++it;
		++_begin;
	}
	delete[] _arr;
	_arr = newArr;
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