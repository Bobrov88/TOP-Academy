#pragma once
#pragma once
#include <iostream>
#include <conio.h>
#define _MSG cout<<" Now your _array is -> ";
#define _EMPTY cout<<" empty ";
#define OPERATION_LIST cout<<"\n Choose an operation:\n 1. Push_back\n 2. Push_front\n 3. Insert\n 4. Pop_back\n 5. Pop_front\n 6. Erase\n\n 0. to quit\t";
#define _DATATYPE cout << "\n Choose datatype: 1 - int  2 - double  3 - char  "

using namespace std;

template<typename T> int _call_menu(T**&, const int&, const int&);
template<typename T> void _print_array(T**&, const int&, const int&);
template<typename T> void _operation(T**&, int&, int&, int&);
template<typename T> void insert(T**&, int&, int&, bool, int);
template<typename T> void push_back(T**&, int&, int&, bool);
template<typename T> void push_front(T**&, int&, int&, bool);
template<typename T> void erase(T**&, int&, int&, bool, int);
template<typename T> void pop_back(T**&, int&, int&, bool);
template<typename T> void pop_front(T**&, int&, int&, bool);
template<typename T> void _delete(T**&, int& rows);