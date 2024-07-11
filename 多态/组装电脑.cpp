#include <iostream>
using namespace std;

class CPUBase {
public:
	virtual void Calculator() = 0;
};

class GraphicsCardBase {
public:
	virtual void Video() = 0;
};

class MemeryBase {
public:
	virtual void Memery() = 0;
};

class Computor {
public:
	Computor(CPUBase* cpu, GraphicsCardBase* graphicsCard, MemeryBase* memery): m_cpu(cpu), m_graphicsCard(graphicsCard), m_memery(memery){}
	void Run()
	{
		m_cpu->Calculator();
		m_graphicsCard->Video();
		m_memery->Memery();
	}
	~Computor() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_graphicsCard != NULL) {
			delete m_graphicsCard;
			m_graphicsCard = NULL;
		}
		if (m_memery != NULL) {
			delete m_memery;
			m_memery = NULL;
		}
	}
private:
	CPUBase* m_cpu;
	GraphicsCardBase* m_graphicsCard;
	MemeryBase* m_memery;
	
};

class IntelCpu : public CPUBase {
public:
	void Calculator() {
		cout << "Intel CPU 开始计算." << endl;
	}
};

class NVIDIAGraphicsCard : public GraphicsCardBase {
public:
	void Video() {
		cout << "NVIDIA 显卡 开始显示." << endl;
	}
};

class ChangJiangMemery : public MemeryBase {
public:
	void Memery() {
		cout << "ChangJiang 内存 开始存储数据." << endl;
	}
};

int main() {

	CPUBase* cpu = new IntelCpu;
	GraphicsCardBase* graphicsCard = new NVIDIAGraphicsCard;
	MemeryBase* memery = new ChangJiangMemery;

	Computor computor1(cpu, graphicsCard, memery);
	computor1.Run();

	Computor* computor2 = new Computor(new IntelCpu, new NVIDIAGraphicsCard, new ChangJiangMemery);
	computor2->Run();
	delete computor2;


	system("pause");
	return 1;
}