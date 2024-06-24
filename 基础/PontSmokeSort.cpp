#include "PontSmokeSort.h"
// 9,2,3,1,6,8,7,10,5,4
void PointSmokeSort(int* p, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++) {
			int temp = p[j];
			if (j <= length - 2 - i && p[j] > p[j + 1]) {
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
