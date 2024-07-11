#include <iostream>
using namespace std;

//虚析构函数和纯虚析构函数是为了解决无法释放子类堆资源(父类指针释放子类对象)

class Animal {
public:
	virtual void Speak() = 0;
	/*~Animal()
	{
		cout << "Animal 析构函数被执行." << endl;
	}*/
	// 如果父类是虚析构函数会走子类的析构函数
	/*virtual ~Animal()
	{
		cout << "Animal 析构函数被执行." << endl;
	}*/
	// 纯虚析构需要在成员方法中实现
	// 有了纯虚析构函数的时候这个类也就是抽象类了,无法被实例化
	virtual ~Animal() = 0;
};
Animal::~Animal() {
	cout << "Animal 纯析构函数被执行." << endl;
}

class Cat : public Animal{
public:
	Cat(string name) {
		m_Name = new string(name);
	}
	void Speak() {
		cout << *m_Name << "小猫在说话" << endl;
	}
	~Cat() 
	{
		cout << "Cat 析构函数被执行." << endl;
		if (m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}
	string* m_Name; // 用指针使name存放到堆区
};

//void DoSpeak(Animal& animal) {
//	animal.Speak();
//}
void Test31() {
	Animal* animal = new Cat("Tom"); // 当Animal的析构函数不是虚析构函数的时候,不会走Cat的析构函数
	animal->Speak();
	delete animal;
}

//int main() {
//
//	Test31();
//
//	system("pause");
//	return 1;
//}