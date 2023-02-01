#pragma once
#include <iostream>

struct __declspec(dllexport) Point
{
	double x = 0;
	double y = 0;
	double z = 0;

	__declspec(dllexport) friend std::ostream& operator<<(std::ostream& out, const Point& point);
};