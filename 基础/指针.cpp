//#include <iostream>
//#include "PontSmokeSort.h"
//using namespace std;
//
//
//void Change(int* a, int* b) {
//	cout << "Change *a = " << *a << endl;
//	cout << "Change a = " << a << endl;
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void ChangePoint(int *a, int *b) {
//	cout << "ChangPoint *a = " << *a << endl;
//	cout << "ChangPoint a = " << a << endl;
//
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main() {
//	// 通过一个指针来保存一个地址;指针就是一个地址.
//	// 定义一个指针
//	int a = 10;
//	int* pa = &a;
//	cout << "a的地址: " << &a << endl;
//	cout << "pa的地址: " << pa << endl;
//
//	cout << "a的值" << a << endl;
//	cout << "pa的值" << * pa << endl;
//	// 使用指针; 通过解引用的方式来找到指针指向的内存(* + 指针变量)
//
//	a = 1'000;
//	cout << "a的值(变换后)" << a << endl;
//	cout << "pa的值(变换后)" << *pa << endl;
//
//	*pa = 10'000;
//	cout << "a的值(指针变换后)" << a << endl;
//	cout << "pa的值(指针变换后)" << *pa << endl;
//
//	// 指针所占内存空间 
//	// 在32位操作系统下是4个字节空间;
//	// 64 -> 8
//	cout << "指针所占内存空间: " << sizeof(pa) << endl;
//	cout << "指针的指所占内存空间: " << sizeof(*pa) << endl;
//	
//	cout << "sizeof(int*) = " << sizeof(int *) << endl;
//	cout << "sizeof(char*) = " << sizeof(char *) << endl;
//	cout << "sizeof(string*) = " << sizeof(string *) << endl;
//	cout << "sizeof(double*) = " << sizeof(double *) << endl;
//	
//	
//	// 空指针 : 指针变量指向内存编号为0的空间;
//	// 用途: 初始化指针变量
//	// 注意: 空指针的内存是不可以访问的.
//	int* p = NULL;
//	//*p = 100; // 空指针无权访问 地址编号0~255为系统所占用,不可以访问.
//	
//	
//	// 野指针 : 野指针变量指向非法内存空间
//	int* pi = (int*)0x1100;
//
//	//cout << *pi << endl; // 访问权限冲突
//
//
//	// const修饰指针 -- 常量指针
//	int a1 = 10;
//	int b1 = 20;
//	const int* constP = &a1;
//	// *constP不可以修改(指针的值不可以修改)
//	//*constP = 100; // 表达式必须是可修改的左值
//	constP = &b1; // OK 指针的指向可以修改
//
//	// const修饰常量 -- 指针常量
//	int* const pConst = &a1;
//	*pConst = 100; // OK 指针的值可以修改
//	//pConst = &b1; // 表达式必须时刻修改的左值
//
//	// const修饰指针和常量
//	const int* const constPconst = &a1;
//	// 指针的指向和值都不可以修改
//	//constPconst = &b1; // 表达式必须时刻修改的左值
//	//*constPconst = 100; // 表达式必须时刻修改的左值
//
//
//	// 指针和数组
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int* pArr = arr;
//
//	cout << "指针访问第一个元素" << *pArr << endl;
//	pArr++;
//	cout << "指针访问第二个元素" << *pArr << endl;
//
//	int* pArr2 = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "指针 = " << *pArr2 << endl;
//		pArr2++;
//	}
//
//	// 指针和函数
//	int changA = 10;
//	int changB = 20;
//	cout << "变换前: a = " << changA << ", b = " << changB << endl;
//	ChangePoint(&changA, &changB);
//	cout << "变换后: a = " << changA << ", b = " << changB << endl;
//
//	int sortArr[] = {9,2,3,1,6,8,7,10,5,4};
//	PointSmokeSort(sortArr, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "冒泡:" << sortArr[i] << endl;
//	}
//	system("pause");
//	return 1;
//}