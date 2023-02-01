#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <cmath>

#include "Point.h"
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

double getRandomDouble(double min, double max)
{
	if (min > max)
	{
		throw std::invalid_argument("Min should be less than max");
	}

	static std::default_random_engine re;

	std::uniform_real_distribution<double> unif(min, max);

	return unif(re);
}

double getRandomDoubleForRadius(double min, double max)
{
	if (min < 0.0)
	{
		throw std::invalid_argument("Radius cannot be negative");
	}

	return getRandomDouble(min, max);
}

int main()
{
	std::vector<std::unique_ptr<Curve>> curves;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	const auto t = PI / 4;

	for (size_t i = 0; i < 10; i++)
	{
		size_t random_variable = std::rand() % 3;

		if (random_variable == 0)
		{
			try
			{
				const Point point{ getRandomDouble(-2.0, 3.0), getRandomDouble(-2.0, 3.0), 0.0 };
				curves.push_back(std::make_unique<Circle>(point, getRandomDoubleForRadius(1.0, 6.0)));
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
				return -1;
			}

		}
		else if (random_variable == 1)
		{
			try
			{
				Point point{ getRandomDouble(-2.0, 3.0), getRandomDouble(-2.0, 3.0), 0.0 };
				curves.push_back(std::make_unique<Ellipse>(point, getRandomDoubleForRadius(1.0, 6.0), getRandomDoubleForRadius(1.0, 6.0)));
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
				return -1;
			}
		}
		else if (random_variable == 2)
		{
			try
			{
				Point point{ getRandomDouble(-2.0, 3.0), getRandomDouble(-2.0, 3.0), 0.0 };
				curves.push_back(std::make_unique<Helix>(point, getRandomDoubleForRadius(1.0, 6.0), getRandomDoubleForRadius(1.0, 6.0)));
			}
			catch (const std::invalid_argument& e)
			{
				std::cout << e.what() << std::endl;
				return -1;
			}
		}

		curves.back()->print();
		std::cout << "Returned point: ";
		std::cout << curves.back()->getPoint(t);
		std::cout << "Returned derivative: ";
		std::cout << curves.back()->getDerivative(t) << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Circles" << std::endl;

	std::cout << std::endl;

	std::vector<Circle*> circles;

	for (auto& curve : curves)
	{
		if (Circle* circle_ptr = dynamic_cast<Circle*>(curve.get()); circle_ptr != nullptr)
		{
			circles.push_back(circle_ptr);

			circle_ptr->print();
		}
	}

	std::cout << std::endl;

	std::cout << "Sorted circles" << std::endl;

	std::cout << std::endl;

	std::sort(circles.begin(), circles.end(), [](const Circle* c1, const Circle* c2) {
		return c1->getRadius() < c2->getRadius();
		});

	double sum = 0.0;

	for (const auto* circle : circles)
	{
		circle->print();
		sum += circle->getRadius();
	}

	std::cout << std::endl;

	std::cout << "Sum of all radii: " << sum << std::endl;

	return 0;
}