#include <iostream>
template <typename T>
void print(T* begin, T* end, char delimiter = ' ')
{
	while (begin != end)
	{
		std::cout << *begin++ << delimiter;
	}
	std::cout << '\n';
}
template <typename T, typename Predicate>
int copy_if(T* srcB, T* srcE, T* destB, T* destE,
	Predicate pred)
{
	int copyCount{ 0 };
	while (destB != destE and srcB != srcE)
	{
		if (pred(*srcB))
		{
			*destB++ = *srcB;
			++copyCount;
		}
		++srcB;
	}
	return copyCount;
}
class NoSequence
{
	bool init;
	int prevEl;
	int ignore_;
	int ignore_until{ 0 };
public:
	NoSequence(int ign) : init{ false }, prevEl{ 0 }, ignore_{ ign } {}
	bool operator()(int el)
	{
		if (init)
		{
			bool result{ prevEl != el };
			if (result)
			{
				prevEl = el;
				ignore_until = 0;
			}
			else {
				++ignore_until;
				if (ignore_until < ignore_) {
					return true;
				}
			}
			return result;
		}
		init = true;
		prevEl = el;
		return true;
	}
};
int main()
{
	const int size{ 15 };
	int arr1[size]{ 1,1,1,1,4,5,5,5,7,8,9,9,9,9,9 };
	int arr2[size]{};
	int* const arr1Begin{ arr1 };
	int* const arr1End{ arr1 + size };
	int* const arr2Begin{ arr2 };
	int* const arr2End{ arr2 + size };
	int* arr2NewEnd{};
	std::cout << "Original arr1:\n";
	print(arr1, arr1 + size);
	std::cout << "Original arr2:\n";
	print(arr2, arr2 + size);
	std::cout << '\n';
	std::cout << "arr2 copy of arr1 without sequencing "
		"duplicates:\n";
	arr2NewEnd = arr2Begin + copy_if(arr1Begin, arr1End,
		arr2Begin, arr2End, NoSequence{3});
	print(arr2, arr2NewEnd);
	std::cout << '\n';
	return 0;
}
		