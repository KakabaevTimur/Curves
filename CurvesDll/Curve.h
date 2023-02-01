#pragma once
#include "Point.h"

const double PI = 3.141592653589793238463;

class __declspec(dllexport) Curve
{
public:
	virtual Point getPoint(double) const = 0;

	virtual Point getDerivative(double) const
	{
		return Point{};
	}

	virtual void print() const = 0;

	virtual ~Curve() = default;
};