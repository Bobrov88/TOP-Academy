#include <iostream>
using namespace std;
long steps{ 0 };

void move_(size_t plate_number, size_t from, size_t dest)
{
    cout << ++steps << ": plate #" << plate_number << " moved from " << from << " to " << dest << endl;
}

void hanoiTower(size_t n, size_t col1, size_t col2, size_t col3)
{
    if (n == 0) return;
    hanoiTower(n - 1, col1, col3, col2);
    move_(n, col1, col3);
    hanoiTower(n - 1, col2, col1, col3);
}

int main()
{
    size_t n{ 0 };
    cout << "Enter number of plates: ";
    cin >> n;
    hanoiTower(n, 1, 2, 3);
    return 0;
}