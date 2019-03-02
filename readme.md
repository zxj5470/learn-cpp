# Learn C++ (C++11)
<!-- vscode-markdown-toc -->
* 1. [C++ 11](#C11)
	* 1.1. [ auto 关键字](#auto)
	* 1.2. [ decltype 关键字](#decltype)
	* 1.3. [ template default value 模板默认值](#templatedefaultvalue)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->


##  1. <a name='C11'></a>C++ 11
###  1.1. <a name='auto'></a> auto 关键字
- 类型推导
```cpp
auto i = 0;
```
- 对于STL中迭代器的类型书写简化
```cpp
map<int,int> m;
auto it = m.begin();

std::unordered_multimap<int, int> um;
// before
std::pair<
    std::unordered_multimap<int, int>::iterator,
    std::unordered_multimap<int, int>::iterator> range = um.equal_range(key);

// after
auto range2 = um.equal_range(key);
```

例: [main_010_auto.cpp](./main_010_auto.cpp)

###  1.2. <a name='decltype'></a> decltype 关键字
- 获知表达式类型
```cpp
int x = 0;
decltype(x) y = 1;// y -> int
```
例: [main_011_decltype.cpp](./main_011_decltype.cpp)
###  1.3. <a name='templatedefaultvalue'></a> template default value 模板默认值
```cpp
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
```
例: [main_012_template_default_value.cpp](./main_012_template_default_value.cpp)
