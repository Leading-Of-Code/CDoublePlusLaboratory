#pragma once
class Point {
public:
	double GetX();
	void SetX(double x);

	double GetY();
	void SetY(double y);
	
	void SetV(double* v);
private:
	double m_X;
	double m_Y;
	double* m_V; // สตั้
};