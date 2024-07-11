#include <iostream>
using namespace std;

template<class Name, class Age>
class Person {
public:
	Person(Name n, Age a) {
		this->name = n;
		this->age = a;
	}
	Name name;
	Age age;
};

void test01(){
	Person<string, int> p("A", 1);
}

// 类模板和函数模板的区别
// 1. 类模板没有自动推导,函数模板有
// 2. 类模板的参数可以有默认类型



// 类模板中成员函数创建时机
// 1. 普通类一开始就会创建
// 2. 类模板只有在使用的时候创建

int main() {

	test01();

	system("pause");
	return 1;
}