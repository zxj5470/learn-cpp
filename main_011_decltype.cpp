#include <iostream>

void first() {
	int x = 0;
	decltype(x) y = 1;// y -> int
	decltype(x + y) z = 0; // y -> int

	const int& i = x;
	decltype(i) j = y;// j -> const int &

	// z is an `int`
	const decltype(z) *p = &z; // *p -> const int; p -> const int *
	decltype(z) *pi = &z; // *pi ->  int; pi -> int *
	decltype(pi) *pp = &pi; // *pp -> int* ; pp -> int **
}

class Foo011{
public:
	static const int Number = 0;
	int x;
};

void second(){
	int n=0;
	decltype(n) a = n;// a -> int

	volatile const int&x = n;
	decltype(x) b = n;// b -> volatile const int&

	Foo011 foo;
	decltype(foo.x) d = 0;// d -> int
}

int main() {
	return 0;
}