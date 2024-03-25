#include "iostream"
#include <string>
#include "Triangle.h"
#include <cmath>
#include <Windows.h>

Triangle::Triangle()
{
	A = B = C = Alpha = Beta = Gamma = 0;
}

Triangle::Triangle(double A, double B, double C) :
	A(A), B(B), C(C), 
	Alpha(180 * acos((C * C + B * B - A * A) / (2 * B * C)) / 3.14),
	Beta(180 * acos((C * C + A * A - B * B) / (2 * A * C)) / 3.14),
	Gamma(180 * acos((A * A + B * B - C * C) / (2 * A * B)) / 3.14) {}

Triangle::Triangle(double Alpha, double Beta, double Gamma, double A) :
	Alpha(Alpha), Beta(Beta), Gamma(Gamma), A(A),
	B(A * sin(Beta * 3.14 / 180) / sin(Alpha * 3.14 / 180)),
	C(A * sin(Gamma * 3.14 / 180) / sin(Alpha * 3.14 / 180)) {}

double Triangle::getA()
{
	return A;
}
double Triangle::getB()
{
	return B;
}
double Triangle::getC()
{
	return C;
}
double Triangle::getAlpha()
{
	return Alpha;
}
double Triangle::getBeta()
{
	return Beta;
}
double Triangle::getGamma()
{
	return Gamma;
}


void Triangle::setAngles(double alpha, double beta, double gamma, double a)
{
	Alpha = alpha;
	Beta = beta;
	Gamma = gamma;
	A = a;
	B = A * sin(Beta * 3.14 / 180) / sin(Alpha * 3.14 / 180);
	C = A * sin(Gamma * 3.14 / 180) / sin(Alpha * 3.14 / 180);
}

void Triangle::setSides(double a, double b, double c)
{
	A = a;
	B = b;
	C = c;
	Alpha = 180 * acos((C * C + B * B - A * A) / (2 * B * C)) / 3.14;
	Beta = 180 * acos((C * C + A * A - B * B) / (2 * A * C)) / 3.14;
	Gamma = 180 * acos((A * A + B * B - C * C) / (2 * A * B)) / 3.14;
}

double Triangle::Area()
{
	return A * B * sin(Gamma * 3.14 / 180) / 2;
} 
 
double Triangle::Perimeter()
{
	return A + B + C;
}

double Triangle::Height(double A)
{
	return 2 * Area() / A;
}

void Triangle::Type()
{
	if ((int) Alpha == 90 || (int) Beta == 90 || (int) Gamma == 90)
	{
		std::cout << "Треугольник прямоугольный\n";
	}
	else if (A == B && B == C)
	{
		std::cout << "Треугольник равносторонний\n";
	}
	else if (A == B || B == C || A == C)
	{
		std::cout << "Треугольник равнобедренный\n";
	} 
	else
	{
		std::cout << "Треугольник обычный\n";
	}
}

std::string Triangle::toString()
{
	return "Стороны треугольника: " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + " см. Углы треугольника: "
		+ std::to_string(Alpha) + ", " + std::to_string(Beta) + ", " + std::to_string(Gamma) + " градусов.\n";
}