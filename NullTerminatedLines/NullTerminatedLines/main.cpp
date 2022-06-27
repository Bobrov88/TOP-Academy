#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;

size_t _stringLength(const char*);
void to_upper(char*);
void to_lower(char*);
void to_shrink(char*);
bool is_palindrom(const char*);
bool is_int_number(const char*);
bool is_bin_number(const char*);
bool is_hex_number(const char*);
int to_int_number(const char*);
int bin_to_dec(const char*);
int hex_to_dec(const char*);
int converter(const char&);
void numberSystems(const char*);

int main() {
	setlocale(0, "");
	const size_t _size = 256;
	char _str[_size];

	cout << "Enter a string "; cin.getline(_str, _size);
	cout << "String length: " << _stringLength(_str) << endl; 	to_upper(_str);
	cout << "String to upper: " << _str << endl; to_lower(_str);
	cout << "String to lower: " << _str << endl; to_shrink(_str);
	cout << "String to shrink: " << _str << endl;
	cout << "String length: " << _stringLength(_str) << endl;
	cout << "String is "; if (is_palindrom(_str) == false) cout << "not "; cout << "a palindrom" << endl;

	numberSystems(_str);

	return 0;
}

size_t _stringLength(const char* _str)
{
	size_t i = 0;
	while (_str[i++] != 0) {}
	return --i;
}

void to_upper(char* _str) {
	size_t i = 0;
	while (_str[i] != 0) {
		if (_str[i] >= 97 && _str[i] <= 122)
			_str[i] -= 32;
		++i;
	}
}

void to_lower(char* _str) {
	size_t i = 0;
	while (_str[i] != 0) {
		if (_str[i] >= 65 && _str[i] <= 90)
			_str[i] += 32;
		++i;
	}
}

void to_shrink(char* _str) {
	size_t i = 0;
	size_t _spaceShift = 0;
	if (_stringLength(_str) == 0) return;
	while (_str[i] != 0) {
		if (_str[i] == 32) {
			_spaceShift = 0;
			while (_str[i + _spaceShift + 1] == 32) ++_spaceShift;
		}
		++i;
		if (_spaceShift != 0) {
			_str[i] = _str[i + _spaceShift];
			if (_str[i + _spaceShift] != 0)
				_str[i + _spaceShift] = 32;
		}
	}
	if (_str[--i] == 32) _str[i] = 0;
	i = 0;
	if (_str[i] == 32) {
		while (true) {
			_str[i] = _str[i + 1];
			if (_str[i] == 0) break;
			++i;
		}
	}
}

bool is_palindrom(const char* _str) {
	size_t i = 0;
	size_t _size = _stringLength(_str);
	while (i < _size / 2) {
		if (_str[i] != _str[_size - i - 1]) {
			return false;
		}
		++i;
	}
	return true;
}

bool is_int_number(const char* _str) {
	size_t i = 0;
	while (_str[i] != 0) {
		if (_str[i] < 48 || _str[i] > 57)
			return false;
		++i;
	}
	return true;
}

bool is_bin_number(const char* _str) {
	size_t i = 0;
	while (_str[i] != 0) {
		if (_str[i] < 48 || _str[i] > 49)
			return false;
		++i;
	}
	return true;
}

bool is_hex_number(const char* _str) {
	if (_str[0] == 48 && _str[1] == 'x') {
		size_t i = 2;
		while (_str[i] != 0) {
			if ((_str[i] < 48 && _str[i] > 57) ||
				((_str[i] < 65 && _str[i]>70) ||
					(_str[i] < 97 && _str[i]>102)))
				return false;
			++i;
		}
	}
	else return false;
	return true;
}

int to_int_number(const char* _str)
{
	int decimal = 0;
	size_t i = 0;
	while (_str[i] != 0) {
		decimal = decimal * 10 + converter(_str[i]);
		++i;
	}
	return decimal;
}

int bin_to_dec(const char* _str)
{
	int decimal = 0;
	size_t size = _stringLength(_str);
	size_t i = size - 1;
	while (i != -1) {
		decimal = decimal + converter(_str[i]) * pow(2, size - i - 1);
		--i;
	}
	return decimal;
}

int hex_to_dec(const char* _str) {
	int decimal = 0;
	size_t size = _stringLength(_str);
	size_t i = size - 1;
	while (i != 1) {
		decimal = decimal + converter(_str[i]) * pow(16, size - i - 1);
		--i;
	}
	return decimal;
}

int converter(const char& Char) {
	switch ((int)Char)
	{
	case 48: return 0;
	case 49: return 1;
	case 50: return 2;
	case 51: return 3;
	case 52: return 4;
	case 53: return 5;
	case 54: return 6;
	case 55: return 7;
	case 56: return 8;
	case 57: return 9;
	case 65: return 10;
	case 66: return 11;
	case 67: return 12;
	case 68: return 13;
	case 69: return 14;
	case 70: return 15;
	case 97: return 10;
	case 98: return 11;
	case 99: return 12;
	case 100: return 13;
	case 101: return 14;
	case 102: return 15;
	default:break;
	}
}

void numberSystems(const char* _str)
{
	if (is_int_number(_str) == true) cout << "String is a integer decimal number -> " << to_int_number(_str) << endl;
	else cout << "String is not a integer decimal number" << endl;

	if (is_bin_number(_str) == true) {
		cout << "String is a binary number -> " << bin_to_dec(_str) << endl;
		cout << "[Notice that a binary number looks like a decimal one so the decimal above was also converted]" << endl;
	}
	else cout << "String is not a binary number" << endl;

	if (is_hex_number(_str) == true) cout << "String is a hexadecimal number -> " << hex_to_dec(_str) << endl;
	else cout << "String is not a hexadecimal number" << endl;
}
