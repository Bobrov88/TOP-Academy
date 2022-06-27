#include "Prototypes.h"
#include "Functions.cpp"

int main()
{
	setlocale(0, "");
	int** int_array = nullptr;
	double** double_array = nullptr;
	char** char_array = nullptr;
	int rows{ 0 }, cols{ 0 }, key{ 0 };
	_DATATYPE; cin >> key;
	switch (key)
	{
	case 1: while ((key = _call_menu(int_array, rows, cols)) != 0)		_operation(int_array, rows, cols, key);			_delete(int_array, rows);		break;
	case 2: while ((key = _call_menu(double_array, rows, cols)) != 0)		_operation(double_array, rows, cols, key);		_delete(double_array, rows);	break;
	case 3: while ((key = _call_menu(char_array, rows, cols)) != 0)		_operation(char_array, rows, cols, key);		_delete(char_array, rows);		break;
	default: break;
	}
	return 0;
}