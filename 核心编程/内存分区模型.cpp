//#include <iostream>
//using namespace std;
//
//// 栈区
//int* FuncStack() {
//	int a = 10;
//	return &a;
//}
//
//// 堆区
//int* FuncHeap() {
//	int* p = new int(10);
//	return p;
//}
//
//// 值传递
//void SwapValue(int a, int b) {
//	int temp = a;
//	a = b;
//	b = a;
//}
//
//// 地址传递
//void SwapAddress(int* a, int* b) {
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//// 引用传递
//void SwapRe(int& a, int& b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//
//// 引用函数不要返回局部变量的引用
//int& LocalRef() {
//	int a = 10; // 栈区
//	return a;
//}
//
//int& LocalRefStatic() {
//	static int a = 10; // 全局变量区
//	return a;
//}
//
//int main() {
//
//	// C++中在程序运行前分为全局区和代码区
//	// 代码区的特点是共享和只读
//	// 全局区存放全局变量,静态变量,常量
//	// 常量区存放const修饰的全局常量和字符串常量
//	// 局部变量和局部常量不在全局区
//
//
//
//	// 栈区数据  *不要返回局部变量的地址
//	// 栈区的数据由编译器管理开辟和释放
//	// 存放局部变量和形参
//	int* stack = FuncStack();
//	cout << "栈区数据:" << endl;
//
//	cout << *stack << endl;
//	cout << *stack << endl; // 数据不对
//
//	// 堆区
//	// 由程序员管理, 如果不释放则程序结束时由系统回收
//	// 里用new
//	int* heap = FuncHeap();
//	cout << "堆区数据:" << endl;
//
//	cout << *heap << endl;
//	cout << *heap << endl;
//	cout << *heap << endl;
//	cout << *heap << endl;
//
//
//	// new 返回的是该数据的指针
//	int* p = new int(10);
//	cout << *p << endl;
//	cout << *p << endl;
//	// 释放内存
//	delete p;
//	// cout << *p << endl; // 报错,已经释放
//
//	int* array = new int[5];
//	for (int i = 0; i < 5; i++)
//	{
//		array[i] = i + 10;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << array[i] << endl;
//	}
//	delete[] array; // 释放数组
//
//
//
//	//引用 别名
//	int source = 10;
//	int source2 = 20;
//	// 引用必须初始化
//	int& as = source;
//	as = source2; // 赋值操作,而不是更改引用, 引用在初始化后不可以改变.
//
//	cout << "source = " << source << endl;
//	cout << "source2 = " << source2 << endl;
//	cout << "as = " << as << endl;
//
//	as = 100;
//
//	cout << "source = " << source << endl;
//	cout << "source2 = " << source2 << endl;
//	cout << "as = " << as << endl;
//
//
//	int swapA = 10;
//	int swapB = 20;
//	SwapValue(swapA, swapB);
//	cout << "swapA = " << swapA << endl;
//	cout << "swapB = " << swapB << endl;
//
//	SwapAddress(&swapA, &swapB);
//	cout << "swapA = " << swapA << endl;
//	cout << "swapB = " << swapB << endl;
//
//	int swapC = 100;
//	int swapD = 200;
//	SwapRe(swapC, swapD);
//	cout << "swapC = " << swapC << endl;
//	cout << "swapD = " << swapD << endl;
//
//	// 不要返回局部变量引用
//	int& localRef = LocalRef();
//	cout << "localRef = " << localRef << endl;
//
//
//	// 引用函数可以作为左值
//	int& staticRef = LocalRefStatic();
//	cout << "staticRef = " << staticRef << endl;
//	cout << "staticRef = " << staticRef << endl;
//	LocalRefStatic() = 1000;
//	cout << "staticRef = " << staticRef << endl;
//	cout << "staticRef = " << staticRef << endl;
//
//
//	// 引用的本质
//	// 引用就是指针常量.指向不可变,值可变.
//
//
//	// 常量引用
//	// 使用场景:用来修饰形参防止误操作.
//	int r = 10;
//	//int& re = 10; // 不是合法内存空间
//	const int& ref = 10; // 编译器优化 int temp = 10; const int& ref = temp;
//	//ref = 20; // 只读不允许修改.
//
//	int r1 = 100;
//	const int& re1 = r1;
//	// re1 = 10000;// 只读,不允许修改.
//
//
//
//
//	system("pause");
//	return 1;
//}