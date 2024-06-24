#include <iostream>
using namespace std;

struct Student {
	int ID;
	string Name;
	int Age;
	int Score;
} s2;


struct Teacher {
	int ID;
	string Name;
	Student students[2];
};

struct Hero {
	string Name;
	int Age;
	string Gender;
};

void StudentToString(Student s1) {
	cout << "值传递" << endl;
	cout << "学生1 ID = " << s1.ID << ", 姓名: " << s1.Name << ", 年龄: " << s1.Age << ", 成绩: " << s1.Score << endl;

}

void StudentToString(Student* s1) {
	cout << "地址传递" << endl;
	cout << "学生1 ID = " << s1->ID << ", 姓名: " << s1->Name << ", 年龄: " << s1->Age << ", 成绩: " << s1->Score << endl;

}

void ConstStudentToString(const Student* s1) {
	// 加入const之后,一旦有修改的操作就会报错,可防止我们的误操作
	cout << "const地址传递" << endl;
	cout << "学生1 ID = " << s1->ID << ", 姓名: " << s1->Name << ", 年龄: " << s1->Age << ", 成绩: " << s1->Score << endl;

}

void SmokeSort(Hero heroArray[], int length) {
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (j + 1 <= length - 1 - i && heroArray[j].Age > heroArray[j + 1].Age) {
				Hero temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

int main() {

	struct Student s1 = { 1, "Mike", 18, 100 };

	cout << "学生1 ID = " << s1.ID << ", 姓名: " << s1.Name << ", 年龄: " << s1.Age << ", 成绩: " << s1.Score << endl;

	s2.ID = 2;
	s2.Name = "Lily";
	s2.Age = 19;
	s2.Score = 99;

	cout << "学生2 ID = " << s2.ID << ", 姓名: " << s2.Name << ", 年龄: " << s2.Age << ", 成绩: " << s2.Score << endl;

	// 结构体数组
	Student students[2] = {
		{1, "Mike", 18, 100},
		{2, "Yang", 19, 101}
	};
	students[1].Name = "Peng";

	// 结构体指针
	Student* sp = &s1;
	cout << "学生1 ID = " << sp->ID << ", 姓名: " << sp->Name << ", 年龄: " << sp->Age << ", 成绩: " << sp->Score << endl;


	// 嵌套结构体
	Teacher t1 = { 1, "T1", {s1,s2} };
	Teacher t2 = { 2, "T2", *students };

	// 结构体作为参数
	StudentToString(s1);
	StudentToString(&s1);


	// 结构体中的const
	// 将函数中的形参改为指针,可以节省内存空间, 而且不会复制副本出来
	ConstStudentToString(&s2);


	// 联系
	struct Hero heroArray[3] = {
		{"关羽", 22, "男"},
		{"刘备", 23, "男"},
		{"张飞", 20, "男"},
	};
	SmokeSort(heroArray, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << heroArray[i].Name << endl;
	}

	system("pause");
	return 1;
}