// 普通函数和函数模板的使用规则
// 1. 优先普通函数
// 2. 通过空模板的函数列表强行调用函数模板 func<>(a,b);
// 3. 函数模板可以重载
// 4. 如果函数模板可以产生更好的匹配,优先调用函数模板.
void myPrint(int a, int b) {
	
}
template<class T>
void myPrint(T a, T b) {

}

// 普通函数和函数模板的区别
// 1. 普通函数可以发生隐式转换
// 2. 函数模板如果自动推到 不会发生隐式转换
// 3. 函数模板定义了模板类型, 则会发生隐式转换



// 优先使用具体化的Person去比较Person是否相等
class Person {
public:
	int m_Age;
};
template<class T >
bool compare(T& a, T& b) {
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}
template<> bool compare(Person& p1, Person& p2) {
	if (p1.m_Age == p2.m_Age) {
		return true;
	}
	else {
		return false;
	}
}