#include <iostream>
#include "Point.h"
#include "Circle.h"

using namespace std;



void DistanceByCircleAndPoint(Circle c, Point p) 
{
	double distance = (c.GetPoint().GetX() - p.GetX()) * (c.GetPoint().GetX() - p.GetX()) +
		              (c.GetPoint().GetY() - p.GetY()) * (c.GetPoint().GetY() - p.GetY());
	double rDistance = c.GetR() * c.GetR();

	if (distance == rDistance) {
		cout << "点在圆上." << endl;
	}
	else if (distance > rDistance) {
		cout << "点在圆外." << endl;
	}
	else {
		cout << "点在圆里." << endl;
	}

}

int main() {

	Point center;
	center.SetX(10);
	center.SetY(0);
	Circle circle;
	circle.SetR(10);
	circle.SetPoint(center);


	Point pc = circle.GetPoint();
	cout << "PointCenter对象的地址" << &center << endl;
	cout << "CircleCenter对象的地址" << &pc << endl;
	cout << "Circle对象的地址" << &circle << endl;


	double arr[] = { 1,2,3,4,5 };

	Point p;
	p.SetX(10);
	p.SetY(11);

	p.SetV(arr);

	DistanceByCircleAndPoint(circle, p);

	system("pause");
	return 1;
}