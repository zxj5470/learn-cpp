//
// Created by zh on 2019-03-03.
//

#ifndef CPP11_MYUTIL_H
#define CPP11_MYUTIL_H

template<typename T>
void printType(const T &a) {
	std::cout << typeid(a).name() << std::endl;
}


template<typename T>
void printIterable(const T &iterable) {
	for(const auto& it:iterable){
		std::cout << it << std::endl;
	}
}
#endif //CPP11_MYUTIL_H
