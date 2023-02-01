#pragma once
#include "Point.h"
#include "Curve.h"

class __declspec(dllexport) Ellipse final : public Curve
{
public:
	Ellipse(const Point& point, double radiusX, double radiusY);

	Point getPoint(double radian) const override;

	Point getDerivative(double) const override;

	void print() const override;

	virtual ~Ellipse() = default;
private:
	Point m_point;
	double m_radiusX;
	double m_radiusY;
};