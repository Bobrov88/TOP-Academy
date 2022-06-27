#include <iostream>
#include <conio.h>
using namespace std;

#define EVEN_ODD
#define DYNAMIC_MEMORY

bool _if_even(int&);
template<typename T> void _print_array(const T*, const int&, const char*);
template<typename T> T* push_back(T*, T&, int&);
template<typename T> T* push_front(T*, T&, int&);
template<typename T> T* insert(T*, T&, int, int&);
template<typename T> T* erase(T*, int, int&);
template<typename T> T* pop_back(T*, int&);
template<typename T> T* pop_front(T*, int&);
template<typename T> int _call_menu(T*, const int&);
template<typename T> T* _operation(T*, int&, int&);

int main()
{
	setlocale(0, "");

#ifdef  EVEN_ODD
	const unsigned int SIZE = 10;
	unsigned int _EVEN = 0;
	int rand_array[SIZE]{ 0 };
	/*-------------Defining arrays' size and allocating memory--------------*/
	for (int i = 0; i < SIZE; ++i)
	{
		(_if_even(rand_array[i] = rand() % 100)) ? ++_EVEN : _EVEN;
	}
	int* even = new int[_EVEN];
	int* odd = new int[SIZE - _EVEN];
	/*------------Copying even and odd elements accordingly-----------------*/
	for (int i = 0, j = 0; i + j < SIZE;)
	{
		(_if_even(rand_array[i + j])) ? even[i++] = rand_array[i + j] : odd[j++] = rand_array[i + j];
	}
	_print_array(even, _EVEN, "EVEN");
	_print_array(odd, SIZE - _EVEN, "_ODD");
	delete[]even;
	delete[]odd;
	cout << "\n Press ENTER to continue... "; _getch();
#endif //  EVEN_ODD

#ifdef DYNAMIC_MEMORY
	int* _array = nullptr;
	int size = 0;
	int key;
	while ((key = _call_menu(_array, size)) != 27)
	{
		_array = _operation(_array, size, key);
	}
	delete[]_array;
#endif // DYNAMIC_MEMORY
	return 0;
}

bool _if_even(int& number)
{
	return (number % 2 == 0);
}

template<typename T>
void _print_array(const T* _array, const int& size, const char* _string) {
	cout << "\n " << _string << " -> ";
	if (size == 0) cout << "empty";
	else
		for (int i = 0; i < size; ++i)
			cout << _array[i] << "  ";
}

template<typename T>
T* push_back(T* _array, T& value, int& size) {
	return insert(_array, value, size, size);
}

template<typename T>
T* push_front(T* _array, T& value, int& size) {
	return	insert(_array, value, 0, size);
}

template<typename T>
T* insert(T* _array, T& value, int position, int& size) {
	if (position <= size)
	{
		int* temp = new int[++size];
		for (int i = 0; i < position; ++i)
		{
			temp[i] = _array[i];
		}
		temp[position] = value;
		for (int i = position + 1; i < size; ++i)
		{
			temp[i] = _array[i - 1];
		}
		delete[]_array;
		return temp;
	}
	else return _array;
}

template<typename T>
T* erase(T* _array, int position, int& size) {
	if ((size != 0) && (position < size))
	{
		int* temp = new int[--size];
		for (int i = 0; i < position; i++)
		{
			temp[i] = _array[i];
		}
		for (int i = position; i < size; i++)
		{
			temp[i] = _array[i + 1];
		}
		delete[]_array;
		_array = temp;
	}
	return _array;
}

template<typename T>
T* pop_back(T* _array, int& size) {
	return erase(_array, size - 1, size);
}

template<typename T>
T* pop_front(T* _array, int& size) {
	return erase(_array, 0, size);
}

template<typename T>
int _call_menu(T* _array, const int& size) {
	system("cls");
	_print_array(_array, size, "Now your array is");
	cout << "\n Choose an operation:";
	cout << "\n 1. Push_back";
	cout << "\n 2. Push_front";
	cout << "\n 3. Insert";
	cout << "\n 4. Pop_back";
	cout << "\n 5. Pop_front";
	cout << "\n 6. Erase";
	cout << "\n ESC to quit ";
	return _getch();
}

template<typename T>
T* _operation(T* _array, int& size, int& key) {
	int value = 0, position = 0;
	switch (key)
	{
	case '1':
	{
		cout << "\n Enter a value to push back -> "; cin >> value;
		_array = push_back(_array, value, size);
		break;
	}
	case '2':
	{
		cout << "\n Enter a value to push front -> "; cin >> value;
		_array = push_front(_array, value, size);
		break;
	}
	case '3':
	{
		cout << "\n Enter a value to insert -> "; cin >> value;
		cout << "\n Enter a position -> "; cin >> position;
		_array = insert(_array, value, position, size);
		break;
	}
	case '4':
	{
		_array = pop_back(_array, size);
		break;
	}
	case '5':
	{
		_array = pop_front(_array, size);
		break;
	}
	case '6':
	{
		cout << "\n Enter a position -> "; cin >> position;
		_array = erase(_array, position, size);
		break;
	}
	case 27:
		break;
	default:
	{
		cout << "\n Unknows operation. Re-choose..." << endl;
		break;
	}
	}
	return _array;
}