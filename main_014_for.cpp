#include <iostream>
#include <vector>
#include "myUtil.h"

// to modify value, use `auto &`
void first() {
	std::vector<int> l = {1, 2, 3};
	printIterable(l);

	for (auto &it:l) {
		it = it + 10;
	}

	printIterable(l);
}

#include <map>

void for_map() {
	std::map<std::string, int> mm = {
			{"1", 1},
			{"2", 2},
			{"3", 3}
	};
	for (const auto &val:mm) {
		std::cout << val.first << "->" << val.second << std::endl;
	}
}


/*
 * be careful
 * the element of std::set is immutable
 */
#include <set>

void for_set() {
	std::set<int> set = {1, 2, 3};
	for (auto &val:set) {
//		val++;// const int&
	}
}

int main() {
	first();
	for_map();
	return 0;
}