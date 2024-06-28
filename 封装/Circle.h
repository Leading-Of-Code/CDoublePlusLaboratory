#pragma once
#include "Point.h"

class Circle {
public:
	double GetR();
	void SetR(double r);

	Point GetPoint();
	void SetPoint(Point center);

private:
	double m_R;
	Point m_Center;
};