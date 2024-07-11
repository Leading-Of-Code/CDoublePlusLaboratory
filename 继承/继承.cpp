#include <iostream>
using namespace std;



// 1. 语法
// class 子类: 继承方式 父类
// class dog : public/protected/private animal; 
// 父类中的private成员不可继承
// public: 父类中的作用域不变
// protected: 父类中的作用域变为protected
// private: 父类中的作用域变为private



// 2. 继承中的对象模型
// 在父类中所有的非静态成员都会被子类继承,父类中的私有成员属性是被编译器隐藏了,因此访问不到,但是确实被继承下去了.


// 3. 顺序
// 父类构造 > 子类构造 > 子类析构 > 父类析构

// 4. 同名成员处理方式
// 子类.父类::成员
// 子类会隐藏父类中同名的成员函数,即使是被重载的函数.需要加作用域才能访问父类的函数
class Base {
public:
	int m_A = 100;
	void func() {
		cout << "Base的函数." << endl;
	}
};
class Son1 : public Base {
public :
	int m_A = 200;
	void func() {
		cout << "Son1的函数." << endl;
	}
};
void Test1() {
	Son1 s;
	cout << "Son1.m_A = " << s.m_A << endl;
	cout << "Base.m_A = " << s.Base::m_A << endl;
	s.func();
	s.Base::func();
}


// 5. 继承中的同名静态成员处理方式
class Base2 {
public:
	static int m_A;
	static void func(){}
};
int Base2::m_A = 100;

class Son2 : public Base2 {
public:
	static int m_A;
	static void func() {}
};
int Son2::m_A = 200;

void Test5(){
	// 通过对象访问静态成员
	Son2 s2;
	cout << "Son2.m_A = " << s2.m_A << endl;
	cout << "Base2.m_A = " << s2.Base2::m_A << endl;

	// 通过类名访问静态成员
	cout << "Son2.m_A = " << Son2::m_A << endl;
	cout << "Base2.m_A = " << Son2::Base2::m_A << endl;
}

// 6. 多继承
// 子类:继承方式 父类1, 继承方式 父类2...



// 7. 菱形继承
// 利用虚继承解决菱形继承
// 在继承之前加上关键字 virtual 变为虚继承
// 被virtual的类称为虚基类
// 这样可以使用同一份数据

class Animal {
public :
	int m_Age;
};
// 里用虚继承解决菱形继承问题.
// 在继承之前加virtual关键字
class Yang : virtual public  Animal {};
class Tuo : virtual public Animal{};
class YangTuo : public Yang, public Tuo {};


void Test07()
{
	YangTuo yt;
	//yt.m_Age = 18; // Yang有一份,Tuo有一份,继承不明确
	yt.Yang::m_Age = 10;
	yt.Tuo::m_Age = 20;
	// 当出现菱形继承的时候,两个父类拥有相同数据的时候需要加作用域
	cout << "Yang的年龄: " << yt.Yang::m_Age << endl;
	cout << "Tuo的年龄: " << yt.Tuo::m_Age << endl;
	cout << "Animal的年龄: " << yt.Yang::Animal::m_Age << endl;
	// 这份数据只有一份就行了.菱形继承导致这份数据具有两份,造成资源浪费
	cout << "YangTuo的年龄: " << yt.m_Age << endl;

}
//
//int main() {
//
//	Test07();
//
//	system("pause");
//	return 1;
//}