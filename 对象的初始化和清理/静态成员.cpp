#include <iostream>
using namespace std;

// 静态成员分为静态成员变量和静态成员函数
// 静态成员变量
// 1. 在编译阶段已经分配内存;
// 2. 所有该类型对象公用同一份数据;
// 3. 类内声明类外初始化;
// 4. 有作用域;




// 静态成员函数
// 1. 所有该类型对象公用同一个函数;
// 2. 静态函数里只能用静态成员变量;
// 3. 有作用域

class Person {
public:
	static int m_A;
	int static m_B;
	int m_C;

	static void Test1() {
		//int result = m_A + m_C;// m_C不是静态变量;非静态成员引用必须与特定对象相对.
	}

private:
	static int m_D;
};

int Person::m_A = 10; // 类内声明类外初始化

int main() {



	system("pause");
	return 0;
}