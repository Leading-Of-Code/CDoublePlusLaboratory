//#include <iostream>
//using namespace std;
//
//class Student {
//public:
//	int id = 0;
//protected:
//	string name;
//public:
//	void GetTheStudentInfo() const {
//		cout << "学号: " << id << " \t姓名: " << name << endl;
//	}
//};
//
//
//struct Person {
//	int id;
//private:
//	string name;
//};
//
//int main() {
//
//	Student s1;
//	s1.id = 1;
//	//s1.name = "111";// 不可访问
//	s1.GetTheStudentInfo();
//
//	// struct和class的唯一区别就是默认访问权限不同
//	// struct是public
//	// class是private
//
//	Person p;
//	p.id = 1;
//	//p.name = "111"; // 无法访问
//
//	system("pause");
//	return 1;
//}