#include "Interface.h"
#include "Reservoir.h"
#include <string>

int main()
{
	Interface R(1);
	Reservoir test("test", 3.5, 4.5, 3, true);
	R.push_back(Reservoir{ "First",3.0,0.3,5.5,false });
	R.push_front(Reservoir{ "Second",3.1,4.13,9.2,true });
	R.push_back(test);
	R.pop_back();
	R.print_all();
	R.clear();
	return 0;
}