#include <iostream>
using namespace std;
#include <fstream>

class Person {
public:
	char m_Name[64]; // ÐÕÃû
	int m_Age;
};

void WirteFile() {

	ofstream ofs("Person.txt", ios::out | ios::binary);
	Person p = { "ÕÅÈý", 18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();
}

void ReadFile()
{
	ifstream ifs;
	ifs.open("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		ifs.close();
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << p.m_Age << p.m_Name << endl;
	ifs.close();
}

int main() {
	//WirteFile();
	ReadFile();

	system("pause");
	return 1;
}