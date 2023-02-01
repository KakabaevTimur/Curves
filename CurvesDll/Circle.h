#pragma once
#include "Point.h"
#include "Curve.h"

class __declspec(dllexport) Circle final : public Curve
{
public:
	Circle(const Point& point, double radius);

	double getRadius() const;

	Point getPoint(double radian) const override;

	Point getDerivative(double radian) const override;

	void print() const override;

	virtual ~Circle() = default;
private:
	Point m_point;
	double m_radius;
};