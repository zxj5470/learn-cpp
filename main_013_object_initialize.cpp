#include <iostream>

/**
 * aggregate
 * - array : int[10], char[] ...
 * - class/union/struct
 *    1. no custom constructor
 *    2. no private and protected non-static member
 *    3. no base class
 *    4. no virtual function
 *    5. no non-static member which has been initialized by `{}` and `=`
 */
void first() {
	int x[] = {1, 3, 5};
	float y[4][3] = {
			{1, 3, 5},
			{2, 4, 6},
			{3, 5, 7}
	};
	char cv[4] = {'a', 's', 'd', 'f'};
	std::string sa[3] = {"123", "321", "312"};
}

void second() {
	struct Foo1 {
		int x;
		double y;
		int z;

		Foo1(int, int) {}
	};
//	Foo1 foo1{1,2,3};// Error, but if no `Foo1(int,int)`, it'll be OK. (legacy)
	Foo1 foo12{1, 2};// ok
}

// 5. no non-static member which has been initialized by `{}` and `=`.
void five() {
	struct ST {
		int x;
		double y = 0.0;
	};
//	ST s{1,2};// error
//	ST s{1};// error
}

#include <map>
#include <set>
#include <vector>

void list() {
	int arr[]{1, 2, 3};// OK
	int arr1[] = {1, 2, 3};// OK

	std::map<std::string, int> mm = {
			{"1", 1},
			{"2", 2},
			{"3", 3}
	};

	std::set<int> ss = {1, 2, 3};
	std::vector<int> arrv = {1, 2, 3, 4, 5};
	// How do they work?
	class Foo {
	public:
		Foo(std::initializer_list<int>) {}
	};
	Foo list = {1, 2, 3, 4};// nice!

	// custom container
	class FooVector {
		std::vector<int> _content;
	public:
		FooVector(std::initializer_list<int> list) {
//			for (auto it = list.begin(); it != list.end(); ++it) {
//				_content.push_back(*it);
//			}
			for (int it : list) {
				_content.push_back(it);
			}
		}
	};

	class FooMap {
		std::map<int, int> _content;
		using pair_t = std::map<int, int>::value_type;
	public:
		FooMap(std::initializer_list<pair_t> list) {
			for (auto it:list) {
				_content.insert(it);
			}
		}
	};
	FooVector fooVector = {1, 2, 3, 4, 5};
	FooMap fooMap = {{1, 2},
	                 {3, 4},
	                 {5, 6}};
}

void func(std::initializer_list<int> l) {
	for (auto &it:l) {
		std::cout << it << std::endl;
	}
}

void list_pass_param() {
	func({});
	func({1, 2, 3});
}

/*
 * initializer_list's each element cannot be modified,
 * but you can modified all of them:
 */
void initializer_list() {
	std::initializer_list<int> lst = {1, 2, 3};
	lst.size();// 3
	lst = {2, 3};
	lst.size();// 2
}

/*
 * return type should not be `initializer_list`
 */
std::initializer_list<int> il_func() {
	int a = 1, b = 2;
	return {a, b, 2, 3};
}

// use this
std::vector<int> v_func() {
	int a = 1, b = 2;
	return {a, b, 3, 4};
}


int main() {
	auto il = il_func();
	auto v = v_func();
	for (auto it:il) {
		std::cout << it << std::endl;// wrong value;
	}

	for (auto it:v) {
		std::cout << it << std::endl;
	}
	return 0;
}