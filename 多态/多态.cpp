#include <iostream>
using namespace std;

// 静态多态 : 函数重载,运算符重载,复用函数名
// 动态多态: 派生类和虚函数实现运行时多态

// 区别:
// 静态多态函数地址早绑定 - 编译阶段确定函数地址
// 动态多态函数地址玩绑定 - 运行阶段确定函数地址

class Animal {
public:
	// 1. 在父类中用virtual标记父类的函数
	// 不加virtual关键字,永远调用的是父类的方法
	virtual void Speak() {
		cout << "动物在叫." << endl;
	}
};

class Cat : public Animal {
public:
	// 2. 重写父类的被标记为virtual的函数
	// 重写: 返回值,函数名,参数列表和父类一摸一样
	/*void Speak() {
		cout << "小猫在叫." << endl;
	}*/
private:
	void Speak() {
		cout << "private小猫在叫." << endl;
	}
};

// 3. 父类的指针或者引用指向子类的对象
void DoSpeak(Animal& animal) {
	animal.Speak();
}

//void Test1() {
//	Cat cat;
//	DoSpeak(cat);
//}

//int main() {
//
//	Test1();
//
//	system("pause");
//	return 1;
//}