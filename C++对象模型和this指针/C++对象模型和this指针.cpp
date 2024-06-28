#include <iostream>
using namespace std;

// 成员变量 和 成员函数是分开存储的
// 只有非静态成员变量和该对象绑定

class Person1 {

};


void Test1(){
	Person1 p;
	// 空对象占用的内存空间为1;
	// 每个对象都应该占用不一样的内存空间,即使是空对象
	cout << "空对象站哟个的内存空间为: " << sizeof(p) << endl; // 1
}

class Person2 {
	int m_A; // Person2的内存空间为 int = 4;
	static int m_B; // Person2的内存空间还为4 ,静态成员连变量不占用该类的内存空间;
	void func1(){} //  函数不占用该类的内存空间
	static void func2() {} // 静态函数也不占用该类的内存空间
};

void Test2() {
	Person2 p2;
	cout << "Person2对象占用的内存空间为: " << sizeof(p2) << endl; // 4
}


class Person3 {

	// 每一个非静态成员函数只会诞生一份函数实例,也就是说多个同类型的对象会公用一段代码
	// 那么问题是: 这一块代码是如何区分哪个对象调用自己呢?
	// C++通过提供特殊的对象指针,this指针,解决上述问题.
	// this 指针指向被调用的成员函数所属的对象,,,谁调用它,this就指向谁
	// this 指针是隐含每一个非静态成员函数的一种指针
	// this 指针不需要定义,可直接调用.

	// this指针用途:
	// 当形参和成员变量同名时,可用this指针来区分
public:
	Person3(int age) {
		//age = age; // 会导致成员age不会被赋值
		this->age = age; // 正确写法
	}
	int age;
	// 在类的非静态成员函数中返回对象本身,可使用return *this
	Person3& AgeAdd(Person3 p) {
		this->age = this->age + p.age;
		return *this;
	}
};

void Test3() {
	Person3 p1(10);
	Person3 p2(11);
	p1.AgeAdd(p2).AgeAdd(p2);
	cout << "P1的年龄为: " << p1.age << endl;
}


class Person4 {
	// const
public:
	void ShowPerson4() const {
		//m_A = 100;  常函数体内不可以修改成员属性
		// this指针的本质时指针常量:值可以变但是指针的指向不可以改变
		// 如果给指针加上const就会变成cont Person4* const this,值和指向都不可以改变
		//this->m_A = 100;
		this->m_B = 1000; // 成员属性声明时加关键字mutable后,在常函数中依然可以修改
	}

	void Func() 
	{
		this->m_A = 100;
	}
	int m_A;
	mutable int m_B;
};

void Test4() {
	// const修饰成员函数
	// 常函数
	// 成员函数后加const我们称这个函数为常函数
	// 常函数内不可以修改成员属性
	// 成员属性声明时加关键字mutable后,在常函数中依然可以修改
	Person4 p4;
	// 常对象
	// 声明对象前加const称该对象为长对象
	// 常对象只能调用常函数
}


void Test5() {
	const Person4 p;
	//p.m_A = 100;  常对象不能修改普通成员
	p.m_B = 1000;

	p.ShowPerson4();
	//p.Func();  常对象只能调用常函数
}
int main() {

	Test1();
	Test2();
	Test3();
	system("pause");
	return 1;
}