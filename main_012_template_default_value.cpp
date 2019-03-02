#include <iostream>
#include "myUtil.h"

template <typename R = int, typename U>
R func(U val){
	return val;
}

int main(){
	auto ret1 = func(123);// return `int`
	printType(ret1);// i

	auto ret2 = func<long>(123);// return `long`
	printType(ret2);// l

}