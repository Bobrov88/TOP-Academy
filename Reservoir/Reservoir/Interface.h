#include "includes.h"

class Interface {
	int size;
	Reservoir *_arr = nullptr;
public:
	explicit Interface(int&&);
	void push_back(Reservoir&);
	void pop_back();
	~Interface();
};