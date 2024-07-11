#include <iostream>
using namespace std;
#include <fstream> // 1. 包含文件操作的头文件
#include <string>

void OutputFile() {
	// 2. 创建对象流
	ofstream ofs;
	// 3. 打开文件
	ofs.open("Test.txt", ios::out);
	// 4. 写内容进文件
	ofs << "Hello File." << endl;
	ofs << "Hello File2." << endl;
	ofs << "Hello File3." << endl;
	// 5. 关闭文件
	ofs.close();
}

void InputFile() {
	// 2. 创建对象六
	ifstream ifs;
	// 3. 打开文件,并判断是否打开成功
	ifs.open("Test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "打开失败." << endl;
		ifs.close();
		return;
	}

	// 4.读数据
	// 第一种
	/*char buf[1024] = { 0 };
	while (ifs >> buf) 
	{
		cout << buf << endl;
	}*/
	// 第二种
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	// 第三种
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	// 第四种
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c << endl;
	}

	// 5. 关闭文件
	ifs.close();
}


//int main() {
//
//	//OutputFile();
//	InputFile();
//
//	system("pause");
//	return 1;
//}