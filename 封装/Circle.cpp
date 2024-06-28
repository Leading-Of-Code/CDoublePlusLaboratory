#include "Circle.h"

double Circle::GetR() {
	return m_R;
}
void Circle::SetR(double r) {
	m_R = r;
}

Point Circle::GetPoint() {
	return m_Center;
}
void Circle::SetPoint(Point center) {
	m_Center = center;
}