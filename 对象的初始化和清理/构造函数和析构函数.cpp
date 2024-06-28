//#include <iostream>
//using namespace std;
//
//
//class Person
//{
//public:
//	// 无返回值且不能写void
//	// 可以带参数被重载
//	// 可以省略,会被编译器自动创建无方法体的空函数
//	// 在对象被创建的时候只会被调用一次.
//	Person() {
//		cout << "构造函数Person()已经被调用." << age << endl;
//	}
//	Person(int a) {
//		age = a;
//		cout << "构造函数Person(int a)已经被调用." << age << endl;
//	}
//
//	// 拷贝构造函数
//	Person(const Person &p) {
//		age = p.age;
//		cout << "构造函数Person(const Person &p)已经被调用." << age << endl;
//	}
//	int age;
//
//	// 无返回值且不能写void
//	// 没有参数
//	// 对象被销毁前被系统自动调用一次
//	~Person() {
//		cout << "析构函数~Person已经被调用" << age << endl;
//	}
//};
//
//
//void Test1() {
//	Person person;
//}
//
//void Test2(Person p) {
//	cout << "Test2已经执行." << endl;
//}
//
//Person DoWork() {
//	cout << "DoWork已经执行." << endl;
//
//	Person p(10);
//	cout << (int*)&p << endl;
//	return p;
//}
//
//void Test3() {
//	cout << "Test3已经执行." << endl;
//
//	Person p10 = DoWork();
//	cout << (int*)&p10 << endl;
//
//
//}
//
//class Student {
//public:
//	// 初始化列表
//	Student(int a, int b, int c) : m_A(a), m_B(b), m_C(c) {
//
//	}
//	int m_A;
//	int m_B;
//	int m_C;
//};
//
//
//int main() {
//	Test1(); // 会调用析构函数
//
//	Person p;// 不会调用析构函数
//	Person p1;
//	Person p2;
//	Person p3(3);
//
//	Person p4(p3);
//	cout << "p3.age = " << p3.age << endl;
//	cout << "p4.age = " << p4.age << endl;
//	p4.age = 11;
//	cout << "p4.age(changed) = " << p4.age << endl;
//
//	//Person p1();// 这个被认为是函数的声明
//
//
//	// 显示创建对象
//	Person p5 = Person(5);
//	Person p6 = Person(p5);
//
//	Person(10);// 匿名对象, 当前行的执行结束后,系统会立即回收掉匿名对象(会被调用系统函数)
//	//Person(p5);// 不要里用拷贝构造函数初始化匿名对象,编译器会认为 Person(p5) === Person p5, 再次创建一个p5的对象
//
//
//	// 隐式转化法
//	Person p7 = 7; // Person p7 = Person(10);
//	Person p8 = p7; // Person p8 = Person(p7);
//
//
//	// 拷贝构造函数的调用时机
//	// 一个对象的实例做为形参传递给参数时会调用拷贝构造函数
//	Person p9(9);
//	Test2(p9);
//	// *****目前不会这样了****方法内部的私有对象变量作为返回值时,会调用构造函数
//	Test3();
//
//	//cout << p10.age << endl;
//
//	// 拷贝>有参>无参
//
//	// 如果有属性在堆区申请内存空间请一定要有自己的拷贝构造函数
//
//
//	// 初始化列表
//	Student student(10, 20, 30);
//
//	cout << "Student A = " << student.m_A << endl;
//	cout << "Student B = " << student.m_B << endl;
//	cout << "Student C = " << student.m_C << endl;
//
//
//	// 类对象作为类成员的时候,先构造类成员的对象再构造被类的对象.
//	// 析构的顺序与类构造相反,先释放本类的对象再释放类对象的对象.
//	system("pause");
//	return 1;
//}