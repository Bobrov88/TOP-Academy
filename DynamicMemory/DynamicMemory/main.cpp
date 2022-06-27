#include <iostream>
#include <conio.h>
using namespace std;

#define EVEN_ODD
#define DYNAMIC_MEMORY

bool _if_even(int&);
void _print_array(const int*, const int&, const char*);
int* push_back(int*, int&, int&);
int* push_front(int*, int&, int&);
int* insert(int*, int&, int, int&);
int* pop_back(int*, int&);
int* pop_front(int*, int&);
int* erase(int*, int, int&);
int _call_menu(int*, int&);
int* _operation(int*, int& size, int&);

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
	int* array = nullptr;
	int size = 0;
	int key;
	while ((key = _call_menu(array, size)) != 27)
	{
		array = _operation(array, size, key);
	}
	delete[]array;
#endif // DYNAMIC_MEMORY
	return 0;
}

bool _if_even(int& number)
{
	return (number % 2 == 0);
}
void _print_array(const int* array, const int& size, const char* _string)
{
	cout << "\n " << _string << " -> ";
	if (size == 0) cout << "empty";
	else
		for (int i = 0; i < size; ++i)
			cout << array[i] << "  ";
}
int* push_back(int* array, int& value, int& size)
{
	return insert(array, value, size, size);
}
int* push_front(int* array, int& value, int& size)
{
	return	insert(array, value, 0, size);
}
int* insert(int* array, int& value, int position, int& size)
{
	if (position <= size)
	{
		int* temp = new int[++size];
		for (int i = 0; i < position; ++i)
		{
			temp[i] = array[i];
		}
		temp[position] = value;
		for (int i = position + 1; i < size; ++i)
		{
			temp[i] = array[i - 1];
		}
		delete[]array;
		return temp;
	}
	else return array;
}
int* erase(int* array, int position, int& size)
{
	if ((size != 0) && (position < size))
	{
		int* temp = new int[--size];
		for (int i = 0; i < position; i++)
		{
			temp[i] = array[i];
		}
		for (int i = position; i < size; i++)
		{
			temp[i] = array[i + 1];
		}
		delete[]array;
		array = temp;
	}
	return array;
}
int* pop_back(int* array, int& size)
{
	return erase(array, size - 1, size);
}
int* pop_front(int* array, int& size)
{
	return erase(array, 0, size);
}
int _call_menu(int* array, int& size)
{
	system("cls");
	_print_array(array, size, "Now your array is");
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
int* _operation(int* array, int& size, int& key)
{
	int value = 0, position = 0;
	switch (key)
	{
	case '1':
	{
		cout << "\n Enter a value to push back -> "; cin >> value;
		array = push_back(array, value, size);
		break;
	}
	case '2':
	{
		cout << "\n Enter a value to push front -> "; cin >> value;
		array = push_front(array, value, size);
		break;
	}
	case '3':
	{
		cout << "\n Enter a value to insert -> "; cin >> value;
		cout << "\n Enter a position -> "; cin >> position;
		array = insert(array, value, position, size);
		break;
	}
	case '4':
	{
		array = pop_back(array, size);
		break;
	}
	case '5':
	{
		array = pop_front(array, size);
		break;
	}
	case '6':
	{
		cout << "\n Enter a position -> "; cin >> position;
		array = erase(array, position, size);
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
	return array;
}