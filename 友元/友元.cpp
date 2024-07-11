//#include <iostream>
//using namespace std;
//
//class Building;
//class Friend;
//class Friend2;
//
//class Building {
//	// 告诉编译器, FriendPerson是全局函数, 是Building类的好朋友,可以访问类中的私有内容
//	friend void FriendPerson(Building* building);
//	// 告诉编译器, Friend类是Building的好朋友,可以访问该Building类中的私有内容
//	friend class Friend;
//	// 告诉编译器,Friend2类中的Visit是Building的好朋友,可以访问Building中的私有内容
//	friend void Friend2::Visit2();
//public:
//	string livingRoom_ = "客厅";
//private:
//	string bedRoom_ = "卧室";
//};
//
//// 全局函数
//void FriendPerson(Building* building)
//{
//	cout << "朋友正在访问: " << building->livingRoom_ << endl;
//	cout << "朋友正在访问: " << building->bedRoom_ << endl; // 不是友元的情况下全局函数无法访问类的私有成员
//}
//
//// 类
//class Friend {
//public:
//	void Visit();
//	Building* building_ = new Building;// 在堆里创建对象
//};
//// 在类外写成员函数
//void Friend::Visit() {
//	cout << "Friend正在访问: " << building_->livingRoom_ << endl;
//	cout << "Friend正在访问: " << building_->bedRoom_ << endl; // 在不是类友元的情况下无法访问类对象的私有成员
//}
//
//class Friend2 {
//public:
//	Building* building2_ = new Building;// 在堆里创建对象
//	void Visit2();
//};
//void Friend2::Visit2()
//{
//	cout << "Friend2正在访问: " << building2_->livingRoom_ << endl;
//	cout << "Friend2正在访问: " << building2_->bedRoom_ << endl; // 在不是类函数友元的情况下无法访问类对象的私有成员
//}
//
//int main() {
//
//	// 1. 全局函数做友元
//	Building building;
//	FriendPerson(&building);
//	// 2. 类的友元
//	Friend f;
//	f.Visit();
//	// 3. 成员函数做友元
//	Friend2 f2;
//	f2.Visit2();
//
//	system("pause");
//	return 1;
//}