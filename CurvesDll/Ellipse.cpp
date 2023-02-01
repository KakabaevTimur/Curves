#include "pch.h"
#include "Ellipse.h"

Ellipse::Ellipse(const Point& point, double radiusX, double radiusY) : m_point(point), m_radiusX(radiusX), m_radiusY(radiusY)
{

}

Point Ellipse::getPoint(double radian) const
{
	return Point{ m_radiusX * cos(radian) + m_point.x, m_radiusY * sin(radian) + m_point.y, 0.0 };
}

Point Ellipse::getDerivative(double) const
{
	return Point{}; //not implemented due to lack of correct formula
}

void Ellipse::print() const
{
	std::cout << "Ellipse " << "\n" << "Given point: " << m_point << "Given radiusX: " << m_radiusX << "\n" << "Given radiusY: " << m_radiusY << std::endl;
}