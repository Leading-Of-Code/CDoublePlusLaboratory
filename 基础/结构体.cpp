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
	cout << "ֵ����" << endl;
	cout << "ѧ��1 ID = " << s1.ID << ", ����: " << s1.Name << ", ����: " << s1.Age << ", �ɼ�: " << s1.Score << endl;

}

void StudentToString(Student* s1) {
	cout << "��ַ����" << endl;
	cout << "ѧ��1 ID = " << s1->ID << ", ����: " << s1->Name << ", ����: " << s1->Age << ", �ɼ�: " << s1->Score << endl;

}

void ConstStudentToString(const Student* s1) {
	// ����const֮��,һ�����޸ĵĲ����ͻᱨ��,�ɷ�ֹ���ǵ������
	cout << "const��ַ����" << endl;
	cout << "ѧ��1 ID = " << s1->ID << ", ����: " << s1->Name << ", ����: " << s1->Age << ", �ɼ�: " << s1->Score << endl;

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

	cout << "ѧ��1 ID = " << s1.ID << ", ����: " << s1.Name << ", ����: " << s1.Age << ", �ɼ�: " << s1.Score << endl;

	s2.ID = 2;
	s2.Name = "Lily";
	s2.Age = 19;
	s2.Score = 99;

	cout << "ѧ��2 ID = " << s2.ID << ", ����: " << s2.Name << ", ����: " << s2.Age << ", �ɼ�: " << s2.Score << endl;

	// �ṹ������
	Student students[2] = {
		{1, "Mike", 18, 100},
		{2, "Yang", 19, 101}
	};
	students[1].Name = "Peng";

	// �ṹ��ָ��
	Student* sp = &s1;
	cout << "ѧ��1 ID = " << sp->ID << ", ����: " << sp->Name << ", ����: " << sp->Age << ", �ɼ�: " << sp->Score << endl;


	// Ƕ�׽ṹ��
	Teacher t1 = { 1, "T1", {s1,s2} };
	Teacher t2 = { 2, "T2", *students };

	// �ṹ����Ϊ����
	StudentToString(s1);
	StudentToString(&s1);


	// �ṹ���е�const
	// �������е��βθ�Ϊָ��,���Խ�ʡ�ڴ�ռ�, ���Ҳ��Ḵ�Ƹ�������
	ConstStudentToString(&s2);


	// ��ϵ
	struct Hero heroArray[3] = {
		{"����", 22, "��"},
		{"����", 23, "��"},
		{"�ŷ�", 20, "��"},
	};
	SmokeSort(heroArray, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << heroArray[i].Name << endl;
	}

	system("pause");
	return 1;
}