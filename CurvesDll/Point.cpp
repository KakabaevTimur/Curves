#include "pch.h"
#include "Point.h"

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << point.x << " " << point.y << " " << point.z << std::endl;
	return out;
}