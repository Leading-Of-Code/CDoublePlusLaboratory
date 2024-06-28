#include <iostream>
#include "Point.h"

using namespace std;

double Point::GetX() {
	return m_X;
}
void Point::SetX(double x) {
	m_X = x;
}

double Point::GetY() {
	return m_Y;
}
void Point::SetY(double y) {
	m_Y = y;
}

// สตั้
void Point::SetV(double* v)
{
	m_V = v;
}
