#include <iostream>
using namespace std;

class Person {
public:
	int age;
	Person operator+ (Person& p) {
		Person temp;
		temp.age = this->age + p.age;
		return temp;
	}
};

class MyAdd {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};
int main() {

	// 运算符重载不允许重载内置的运算符
	Person p1;
	Person p2;
	p1.age = 10;
	p2.age = 100;
	Person p3 = p1 + p2;

	cout << "p1 + p2 = " << p3.age << endl;
	cout << MyAdd()(100, 200) << endl;

	system("pause");
	return 1;
}