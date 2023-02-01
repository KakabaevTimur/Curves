#include "pch.h"
#include "Circle.h"

Circle::Circle(const Point& point, double radius) : m_point(point), m_radius(radius)
{

}

double Circle::getRadius() const
{
	return m_radius;
}

Point Circle::getPoint(double radian) const
{
	return Point{ m_radius * cos(radian) + m_point.x, m_radius * sin(radian) + m_point.y, 0.0 };
}

Point Circle::getDerivative(double radian) const
{
	Point point = getPoint(radian);

	double k = (point.y - m_point.y) / (point.x - m_point.x);
	double ax = -1 / k;
	double by = (point.x + point.y) / k;
	double cz = 0.0;

	return Point{ ax, by, cz };
}

void Circle::print() const
{
	std::cout << "Circle " << "\n" << "Given point: " << m_point << "Given radius: " << m_radius << std::endl;
}