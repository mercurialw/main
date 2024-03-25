#include <string>

class Triangle
{
public:
	Triangle();
	Triangle(double, double, double);
	Triangle(double, double, double, double);

	double getA();
	double getB();
	double getC();
	double getAlpha();
	double getBeta();
	double getGamma();

	void setSides(double, double, double);
	void setAngles(double, double, double, double);

	double Area();
	double Perimeter();
	double Height(double);
	void Type();

	std::string toString();

private:
	double A;
	double B;
	double C;
	double Alpha;
	double Beta;
	double Gamma;
};