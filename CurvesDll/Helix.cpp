#include "pch.h"
#include "Helix.h"

Helix::Helix(const Point& point, double radius, double step) : m_point(point), m_radius(radius), m_step(step)
{

}

Point Helix::getPoint(double radian) const
{
	return Point{ m_radius * cos(radian) + m_point.x, m_radius * sin(radian) + m_point.y, (m_step * radian) / (2 * PI) };
}

Point Helix::getDerivative(double) const
{
	return Point{}; //not implemented due to lack of correct formula
}

void Helix::print() const
{
	std::cout << "Helix " << "\n" << "Given point: " << m_point << "Given radius: " << m_radius << " Given step: " << m_step << std::endl;
}