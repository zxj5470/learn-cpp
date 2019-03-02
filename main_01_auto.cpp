#include <iostream>

template<typename T>
void printType(const T& a) {
	std::cout << typeid(a).name() << std::endl;
}

int main() {

	auto i = new auto(1);// i is an `int*`
	printType(i); // Pi means `pointer to int`, so i is `int*`

	auto d = new auto(1.0);// d is a `double*`
	printType(d); // Pd means `pointer to int`, so i is `int*`

	return 0;
}