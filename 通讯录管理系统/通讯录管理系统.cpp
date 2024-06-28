#include <iostream>
using namespace std;


struct Person {
	string Name;
	int Age;
	string CellPhone;
};

struct AddressList {
	int Count = 0;
	Person Persons[100];
};

void CreatePerson(AddressList* list) {
	if (list->Count == 100) {
		cout << "通讯录已满" << endl;
		return;
	}
	/*Person person;
	cout << "请输入姓名:" << endl;
	cin >> person.Name;
	cout << "请输入年龄:" << endl;
	cin >> person.Age;
	cout << "请输入电话号码:" << endl;
	cin >> person.CellPhone;
	list->Persons[list->Count++] = person;*/
	string name;
	cout << "请输入姓名:" << endl;
	cin >> name;
	int age;
	cout << "请输入年龄:" << endl;
	cin >> age;
	string cellPhone;
	cout << "请输入电话号码:" << endl;
	cin >> cellPhone;
	list->Persons[list->Count++] = {name, age, cellPhone};
}

int SearchPerson(AddressList* list, string searchName) {
	int count = list->Count;
	for (int i = 0; i < count; i++)
	{
		Person targetPerson = list->Persons[i];
		if (searchName._Equal(targetPerson.Name)) {
			cout << "用户名: " << targetPerson.Name << endl;
			return i;
		}
	}
	cout << "未找到该用户." << endl;
	return -1;
}

void DispayPerson(AddressList* list) {
	int count = list->Count;
	for (int i = 0; i < count; i++)
	{
		cout << "用户名: " << list -> Persons[i].Name << endl;
	}
}

void DeletePerson(AddressList* list, string deleteName) {
	int thePersonIndex = SearchPerson(list, deleteName);
	if (thePersonIndex >= 0) 
	{
		for (int i = thePersonIndex; i < list->Count; i++)
		{
			list->Persons[i] = list->Persons[i + 1];
		}
		list->Count--;
	}
}

void UpdatePerson(AddressList* list, string updateName) {

	int thePersonIndex = SearchPerson(list, updateName);
	if (thePersonIndex >= 0) {
		int count = list->Count;
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;
		int age;
		cout << "请输入年龄:" << endl;
		cin >> age;
		string cellPhone;
		cout << "请输入电话号码:" << endl;
		cin >> cellPhone;
		list->Persons[thePersonIndex] = { name, age, cellPhone };
	}
}

void ClearPersons(AddressList* list) {
	list->Count = 0;
	cout << "已经清空." << endl;
}

void ShowMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出登录    *****" << endl;
	cout << "**************************" << endl;
}

int main() {

	AddressList addressList;
	int select = 0;
	string inputName;
	while (true) {
	    ShowMenu();
		cin >> select;
		switch (select) {
		case 1: 
			CreatePerson(&addressList);
			// 添加联系人
			break;
		case 2: 
			//显示联系人
			DispayPerson(&addressList);
			break;
		case 3:
			//删除联系人 
			cout << "请输入姓名: " << endl;
			cin >> inputName;
			DeletePerson(&addressList, inputName);
			break;
		case 4:
			// 查找联系人
			cout << "请输入姓名: " << endl;
			cin >> inputName;
			SearchPerson(&addressList, inputName);
			break;
		case 5:
			// 修改联系人
			cout << "请输入姓名: " << endl;
			cin >> inputName;
			UpdatePerson(&addressList, inputName);
			break;
		case 6:
			// 清空联系人
			ClearPersons(&addressList);
			break;
		case 0:
			// 退出登录
			cout << "欢迎下次使用." << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
}



enum Menu {
	退出登录,
	添加联系人,
	显示联系人,
	删除联系人,
	查找联系人,
	修改联系人,
	清空联系人,
};