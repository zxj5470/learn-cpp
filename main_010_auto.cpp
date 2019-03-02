#include <iostream>
#include "myUtil.h"

void first() {
	auto i = new auto(1);// i is an `int*`
	printType(i); // Pi means `pointer to int`, so i is `int*`

	auto d = new auto(1.0);// d is a `double*`
	printType(d); // Pd means `pointer to int`, so i is `int*`

	auto x = 5;
	const auto *v = &x, u = 6;
	printType(v);// PKi means `pointer to const int`
	// if `u` is 6.0, it'll become error
	// because `v` is int* and the `auto` is `int`
}

void second() {
	int x = 0;
	auto *a = &x;// auto -> int
	printType(a);// Pi => int*
	auto b = &x;// auto -> int*
	printType(b);// Pi => int*

	auto &c = x;// auto -> int
	printType(c);// i => int&
	auto d = c;// auto -> int
	printType(d);// i => int
}

#include <map>
#include <unordered_map>

void third() {
	std::map<double, double> resultmap;
	/// 1
	// before
	std::map<double, double>::iterator it = resultmap.begin();
	for (; it != resultmap.end(); ++it) {};

	// use auto
	for (auto it = resultmap.begin(); it != resultmap.end(); ++it) {

	}

	/// 2
	int key = 0;
	std::unordered_multimap<int, int> um;
	// before
	std::pair<
			std::unordered_multimap<int, int>::iterator,
			std::unordered_multimap<int, int>::iterator> range = um.equal_range(key);

	// after
	auto range2 = um.equal_range(key);
}


class Foo {
public:
	static int get() { return 0; }
};

class Bar {
public:
	static const char *get() { return "zero"; }
};

template<class A>
void func() {
	auto val = A::get();
	std::cout << val << std::endl;
}

int main() {
//	first();
//	second();
//	third();
	func<Foo>();// int 0
	func<Bar>();// string `zero`
	return 0;
}

