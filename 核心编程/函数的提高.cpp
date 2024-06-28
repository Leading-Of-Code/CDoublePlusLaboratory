#include <iostream>

using namespace std;


int Func1(int a, int b = 20, int c = 30) {
	return a + b + c;
}


// 函数声明带默认参数,实现就不能带默认参数.它们中由一个有即可
//int Func2(int a, int b = 20, int c = 30);
int Func2(int a, int b = 20, int c = 30) {
	return a + b + c;
}


// 占位参数
void Func3(int a, int = 10)
{
	// 第二个参数目前用不到.
	cout << "占位参数." << endl;
}
#pragma region 函数重载

// 函数重载
void Func4(int a) {
	cout << "函数重载1" << endl;
}
// 函数重载
void Func4(string a) {
	cout << "函数重载2" << endl;
}
// 函数重载
void Func4(string a, int b) {
	cout << "函数重载3" << endl;
}

// 函数重载
void Func4(int b, string a) {
	cout << "函数重载4" << endl;
}
#pragma endregion

#pragma region 函数重载注意事项
// 引用参数可以重载函数
void Func5(int& a) 
{
	cout << "Func5(int& a)" << endl;
}
void Func5(const int& a)
{
	cout << "Func5(const int& a)" << endl;
}

// 尽量不要用默认参数重载函数
void Func6(int a)
{
	cout << "Func6(int a)" << endl;
}

void Func6(int a, int b = 10)
{
	cout << "Func6(int a, int b = 10)" << endl;
}
#pragma endregion


int main() {

	cout << Func1(10, 40) << endl;
	cout << Func2(10, 40) << endl; // 重定义默认参数

	Func3(10, 11);

	Func4(10);
	Func4("函数重载");
	Func4("10", 20);
	Func4(20, "10");


	// 引用重载
	int a = 10;
	Func5(a); // Func5(int& a)
	Func5(10); // Func5(const int& a)

	//Func6(10); // 报错
	Func6(10, 20); // 不报错


	system("pause");
	return 1;
}