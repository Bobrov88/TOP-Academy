#include <iostream>
using namespace std;
#define BORDER "\n=================================================================\n"

template <typename T>
class Array2D {
	size_t rows;
	size_t cols;
	T** arr;
//	static size_t number_of_elements;
public:
	Array2D() = default;										// default constructor
	Array2D(size_t) = delete;									// deleted constructor with one parameter
	Array2D(size_t, size_t);									// valid constructor with two parameters
	Array2D(const Array2D&);									// copy-constructor
	Array2D(Array2D&&) noexcept;								// move-constructor
	~Array2D();													// destructor

	Array2D& operator=(const Array2D&);							// copy-assigment operator
	Array2D& operator=(Array2D&&) noexcept;						// move-assigment operator

	void randomValues(T*, const size_t&);						// filling rows with random values

	T& operator()(const size_t, const size_t);					// access to any element

	void insertRow(const size_t);								// rows insertion function
	void insertCol(const size_t);								// columns insertion function
	void deleteRow(const size_t);								// rows deleting function
	void deleteCol(const size_t);								// colums deleting function

	void print() const;											// printing all elements of object
	void clear();												// deleting array
};

//====================================================

int main() {
	Array2D<int> A(3, 4);
	A.print();
	cout << BORDER;

	Array2D<int> B(4, 2);
	B.print();
	cout << BORDER;

	Array2D<int> C(A);
	C.print();
	cout << BORDER;

	Array2D<int> D (Array2D<int>(3,4));
	D.print();
	cout << BORDER;

	A(1, 1) = 11111;
	cout << "Set A[1][1] as 11111 \n";
	A.print();
	cout << BORDER;

	A.insertCol(3);
	A.print();
	cout << BORDER;

	B.insertRow(1);
	B.print();
	cout << BORDER;

	A.deleteRow(0);
	A.print();
	cout << BORDER;

	C.deleteRow(1);
	C.print();
	cout << BORDER;

	cout<<"Element B[1][0] is "<<B(1, 0)<<endl;
	cout << BORDER;

	C = D;
	C.print();
	cout << BORDER;

	D = Array2D<int>(5, 3);
	D.print();
	cout << BORDER;

	return 0;
}

//====================================================

template<typename T>
Array2D<T>::Array2D(size_t _rows, size_t _cols) : rows{ _rows }, cols{ _cols }, arr{ new T * [_rows] }
{
	for (size_t i{ 0 }; i < _rows; ++i) {
		arr[i] = new T[_cols];
		randomValues(arr[i], _cols);
	}
}

template<typename T>
Array2D<T>::Array2D(const Array2D& obj) : rows{ obj.rows }, cols{ obj.cols }, arr{ new T * [obj.rows] }
{
	if (this != &obj) {
		for (size_t i{ 0 }; i < obj.rows; ++i) {
			arr[i] = new T[obj.cols];
			for (size_t j{ 0 }; j < obj.cols; ++j)
				arr[i][j] = obj.arr[i][j];
		}
	}
}

template<typename T>
Array2D<T>::Array2D(Array2D&& obj) noexcept : rows{ obj.rows }, cols{ obj.cols }, arr{ obj.arr }
{
	obj.arr = nullptr;
	obj.rows = obj.cols = 0;
}

template<typename T>
Array2D<T>::~Array2D()
{
	clear();
}

template<typename T>
Array2D<T>& Array2D<T>::operator=(const Array2D<T>& obj)
{
	if (this != &obj) {
		clear();
		rows = obj.rows;
		cols = obj.cols;
		arr = new T * [rows];
		for (size_t i{ 0 }; i < rows; ++i) {
			arr[i] = new T[cols];
			for (size_t j{ 0 }; j < cols; ++j)
				arr[i][j] = obj.arr[i][j];
		}
	}
	return *this;
}

template<typename T>
Array2D<T>& Array2D<T>::operator=(Array2D<T>&& obj) noexcept
{
	clear();
	arr = obj.arr;
	rows = obj.rows;
	cols = obj.cols;
	obj.arr = nullptr;
	obj.rows = obj.cols = 0;
	return *this;
}

template<typename T>
void Array2D<T>::randomValues(T* arr, const size_t& cols) {
	for (size_t i{ 0 }; i < cols; ++i)
		arr[i] = T(rand() % 20);
}

template<typename T>
T& Array2D<T>::operator()(const size_t rows, const size_t cols)
{
	return arr[rows][cols];
}

template<typename T>
void Array2D<T>::insertRow(const size_t rows_idx)
{
	if (0 <= rows_idx && rows_idx <= rows) {
		++rows;
		T** _arr = new T * [rows];
		for (size_t i{ 0 }; i < rows-1; ++i)
			_arr[i + (i >= rows_idx)] = arr[i];
		_arr[rows_idx] = new T[cols];
		randomValues(_arr[rows_idx], cols);
		delete[]arr;
		arr = _arr;
		_arr = nullptr;
	}
}

template<typename T>
void Array2D<T>::insertCol(const size_t cols_idx)
{
	if (0 <= cols_idx && cols_idx <= cols) {
		++cols;
		T* _arr = nullptr;
		for (size_t i{ 0 }; i < rows; ++i) {
			_arr = new T[cols];
			for (size_t j{ 0 }; j < cols-1; ++j)
				_arr[j + (j >= cols_idx)] = arr[i][j];
			_arr[cols_idx] = (T)(rand() % 20);
			delete[]arr[i];
			arr[i] = _arr;
			_arr = nullptr;
		}
	}
}

template<typename T>
void Array2D<T>::deleteRow(const size_t rows_idx)
{
	if (0 <= rows_idx && rows_idx <= rows) {
		--rows;
		T** _arr = new T * [rows];
		for (size_t i{ 0 }; i < rows; ++i)
			_arr[i] = arr[i + (i >= rows_idx)];
		delete[]arr[rows_idx];
		arr = _arr;
		_arr = nullptr;
	}
}

template<typename T>
void Array2D<T>::deleteCol(const size_t cols_idx)
{
	if (0 <= cols_idx && cols_idx <= cols) {
		++cols;
		T* _arr = nullptr;
		for (size_t i{ 0 }; i < rows; ++i) {
			_arr = new T[cols];
			for (size_t j{ 0 }; j < cols; ++j)
				_arr[i][j] = arr[i][j + (j >= cols_idx)];
			_arr[i][cols_idx] = (T)rand() % 20;
			delete[]arr[i];
			arr[i] = _arr[i];
			_arr[i] = nullptr;
		}
	}
}

template<typename T>
void Array2D<T>::print() const
{
	for (size_t i{ 0 }; i < rows; ++i) {
		for (size_t j{ 0 }; j < cols; ++j)
			cout << arr[i][j] << '\t';
		cout << endl;
	}
}

template<typename T>
void Array2D<T>::clear()
{
	for (size_t i{ 0 }; i < rows; ++i)
		delete[]arr[i];
	delete[] arr;
	arr = nullptr;
	rows = cols = 0;
}