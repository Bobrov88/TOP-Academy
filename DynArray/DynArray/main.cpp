#include<iostream>
using namespace std;
class DynArray
{
	int* arr;
	int size;
public:

	DynArray(int sizeP) :arr{ new int [sizeP] {} }, size{ sizeP }
	{
		cout << "DynArr constructed for " << size << " elemnts, for " << this << '\n';
	}
	DynArray() :DynArray(5) {}
	//DynArray(const DynArray& object) = delete;
	DynArray(const DynArray& object) : size{ object.size }, arr{ new int[object.size] } {
		for (int i = 0; i < size; i++)
			arr[i] = object.arr[i];
	}
	DynArray& operator=(DynArray& object) = delete;
	DynArray(DynArray&& object) noexcept :arr{ object.arr }, size{ object.size }
	{
		object.arr = nullptr;
		object.size = 0;
		cout << "DynArr move constructed for " << size << " elments, for " << this << '\n';
	}
	DynArray& operator=(DynArray&& object) noexcept//����������� ��������
	{
		if (!(this == &object))
		{
			delete arr;
			arr = object.arr;
			size = object.size;
			object.arr = nullptr;
			object.size = 0;
		}
		cout << "DynArr move assigned for " << size << " elments, for " << this << '\n';
		return *this;
	}
	int getElem(int idx)const { return arr[idx]; }//���������� �������� �� �������
	void setElem(int idx, int val) { arr[idx] = val; }//��������� �������� �������� ������� �� �������
	void print()const;
	void randomize();
	~DynArray()//����������
	{
		cout << "Try to free memory from DynArray for " << arr << " pointer\n";
		delete[] arr;
		cout << "DynArr destructed for " << size << " elments, for " << this << '\n';
	}
};
void DynArray::print()const//����� ������ �������� ���������� � ������� � �������
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << '\n';
}
void DynArray::randomize()//����� ���������� ������� ���������� �������
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 10;
}
DynArray arrayFactory(int arrSize)//����� �������� ������� ������ � ��� ��������� �������������
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}
int main()
{
	DynArray ar1{ arrayFactory(10) };
	cout << "ar1 elements: ";
	ar1.print();
	// DynArray ar2{ ar1 }; - ����� ���� ������, ������� - �������� ���������� �����������
	// ������ ������� ����������� - �������� �������� ar1 ��� rvalue&, ������������ ������� move
	// ��� ��� ������ ar1 ��������, � ��� ����� ������ ������������, ��� �����������

	// ������ ������� ����������� - ����������� ���������� �����������
	// ����������� ���� � ������

	DynArray ar2{ move(ar1) };
	cout << "ar2 elements: ";
	ar2.print();
	return 0;
}