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
//	// ͨ��һ��ָ��������һ����ַ;ָ�����һ����ַ.
//	// ����һ��ָ��
//	int a = 10;
//	int* pa = &a;
//	cout << "a�ĵ�ַ: " << &a << endl;
//	cout << "pa�ĵ�ַ: " << pa << endl;
//
//	cout << "a��ֵ" << a << endl;
//	cout << "pa��ֵ" << * pa << endl;
//	// ʹ��ָ��; ͨ�������õķ�ʽ���ҵ�ָ��ָ����ڴ�(* + ָ�����)
//
//	a = 1'000;
//	cout << "a��ֵ(�任��)" << a << endl;
//	cout << "pa��ֵ(�任��)" << *pa << endl;
//
//	*pa = 10'000;
//	cout << "a��ֵ(ָ��任��)" << a << endl;
//	cout << "pa��ֵ(ָ��任��)" << *pa << endl;
//
//	// ָ����ռ�ڴ�ռ� 
//	// ��32λ����ϵͳ����4���ֽڿռ�;
//	// 64 -> 8
//	cout << "ָ����ռ�ڴ�ռ�: " << sizeof(pa) << endl;
//	cout << "ָ���ָ��ռ�ڴ�ռ�: " << sizeof(*pa) << endl;
//	
//	cout << "sizeof(int*) = " << sizeof(int *) << endl;
//	cout << "sizeof(char*) = " << sizeof(char *) << endl;
//	cout << "sizeof(string*) = " << sizeof(string *) << endl;
//	cout << "sizeof(double*) = " << sizeof(double *) << endl;
//	
//	
//	// ��ָ�� : ָ�����ָ���ڴ���Ϊ0�Ŀռ�;
//	// ��;: ��ʼ��ָ�����
//	// ע��: ��ָ����ڴ��ǲ����Է��ʵ�.
//	int* p = NULL;
//	//*p = 100; // ��ָ����Ȩ���� ��ַ���0~255Ϊϵͳ��ռ��,�����Է���.
//	
//	
//	// Ұָ�� : Ұָ�����ָ��Ƿ��ڴ�ռ�
//	int* pi = (int*)0x1100;
//
//	//cout << *pi << endl; // ����Ȩ�޳�ͻ
//
//
//	// const����ָ�� -- ����ָ��
//	int a1 = 10;
//	int b1 = 20;
//	const int* constP = &a1;
//	// *constP�������޸�(ָ���ֵ�������޸�)
//	//*constP = 100; // ���ʽ�����ǿ��޸ĵ���ֵ
//	constP = &b1; // OK ָ���ָ������޸�
//
//	// const���γ��� -- ָ�볣��
//	int* const pConst = &a1;
//	*pConst = 100; // OK ָ���ֵ�����޸�
//	//pConst = &b1; // ���ʽ����ʱ���޸ĵ���ֵ
//
//	// const����ָ��ͳ���
//	const int* const constPconst = &a1;
//	// ָ���ָ���ֵ���������޸�
//	//constPconst = &b1; // ���ʽ����ʱ���޸ĵ���ֵ
//	//*constPconst = 100; // ���ʽ����ʱ���޸ĵ���ֵ
//
//
//	// ָ�������
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int* pArr = arr;
//
//	cout << "ָ����ʵ�һ��Ԫ��" << *pArr << endl;
//	pArr++;
//	cout << "ָ����ʵڶ���Ԫ��" << *pArr << endl;
//
//	int* pArr2 = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "ָ�� = " << *pArr2 << endl;
//		pArr2++;
//	}
//
//	// ָ��ͺ���
//	int changA = 10;
//	int changB = 20;
//	cout << "�任ǰ: a = " << changA << ", b = " << changB << endl;
//	ChangePoint(&changA, &changB);
//	cout << "�任��: a = " << changA << ", b = " << changB << endl;
//
//	int sortArr[] = {9,2,3,1,6,8,7,10,5,4};
//	PointSmokeSort(sortArr, 10);
//	for (int i = 0; i < 10; i++)
//	{
//		cout << "ð��:" << sortArr[i] << endl;
//	}
//	system("pause");
//	return 1;
//}