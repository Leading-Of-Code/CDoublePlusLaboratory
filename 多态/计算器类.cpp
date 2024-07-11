#include <iostream>
using namespace std;
// 普通实现
class Calculator {
public:
	Calculator(int a, int b) : m_A(a), m_B(b) {}
	int GetResult(string oper) {
		switch (oper[0])
		{
		case '+':
			return m_A + m_B;
		case '-':
			return m_A - m_B;
		default:
			break;
		}
	}
	int m_A;
	int m_B;
};
void Test1()
{
	Calculator c(10, 20);
	cout << " 10 + 20 = " << c.GetResult("+") << endl;
	cout << " 10 - 20 = " << c.GetResult("-") << endl;
}

// 多态实现
class CalculatorBase {
protected:
	int m_A;
	int m_B;
public:
	virtual int GetResult() = 0;
};

class ClassAdd : public CalculatorBase {
public:
	ClassAdd(int a, int b) {
		this->m_A = a;
		this->m_B = b;
	}
	int GetResult() override {
		return m_A + m_B;
	}
};
class ClassSub : public CalculatorBase {
public:
	ClassSub(int a, int b) {
		this->m_A = a;
		this->m_B = b;
	}
	int GetResult() override {
		return m_A - m_B;
	}
};

int CalculatorTheNumbers(CalculatorBase& cb) {
	return cb.GetResult();
}

void Test2() 
{
	ClassAdd ca(10, 20);
	cout << "加法: " << CalculatorTheNumbers(ca) << endl;
	ClassSub cs(10, 20);
	cout << "减法: " << CalculatorTheNumbers(cs) << endl;
}

void Test3()
{
	CalculatorBase* ca = new ClassAdd(20,40);
	cout << "加法: " << ca->GetResult() << endl;
	CalculatorBase* cs = new ClassSub(20, 40);
	cout << "加法: " << cs->GetResult() << endl;

	// 用完后delete
	delete ca, cs;
}

//int main() {
//	//Test1();
//	//Test2();
//	Test3();
//	system("pause");
//	return 1;
//}