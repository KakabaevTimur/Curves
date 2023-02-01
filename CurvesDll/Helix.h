#pragma once
#include "Point.h"
#include "Curve.h"

class __declspec(dllexport) Helix final : public Curve
{
public:
	Helix(const Point& point, double radius, double step);

	Point getPoint(double radian) const override;

	Point getDerivative(double) const override;

	void print() const override;

	virtual ~Helix() = default;
private:
	Point m_point;
	double m_radius;
	double m_step = 0.0;
};