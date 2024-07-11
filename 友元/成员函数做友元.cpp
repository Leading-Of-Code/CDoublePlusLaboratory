#include <iostream>
using namespace std;

class B;
class A;
class A {
	friend void B::Access(A& a);
public:
	int m_a = 10;
private:
	int m_b = 100;
};

class B {
public:
	A ca;
	void Access(A& ca) {
		cout << "class A.a = " << ca.m_a << endl;
		cout << "class A.b = " << ca.m_b << endl;
	}
};


int main() {

	B cb;
	A ca;
	cb.Access(ca);

	system("pause");
	return 1;
}

//
//
//#include <iostream>
//using namespace std;
//
//class A;
//class B {
//public:
//	void Access(A& ca);
//};
//
//class A {
//	friend void B::Access(A& a);
//public:
//	int m_a = 10;
//private:
//	int m_b = 100;
//};
//
//
//void B::Access(A& ca) {
//	cout << "class A.a = " << ca.m_a << endl;
//	cout << "class A.b = " << ca.m_b << endl;
//}
//
//int main() {
//
//	B cb;
//	A ca;
//	cb.Access(ca);
//
//	system("pause");
//	return 1;
//}