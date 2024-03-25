#include "Inheritance.h"

Triad::Triad() {
	a = b = c = 0;
}

Triad::Triad(int _a, int _b, int _c) {
	a = _a; b = _b; c = _c;
}

Triad::Triad(Triad const& other) {
	a = other.a; b = other.b; c = other.c;
}

int Triad::getA() { return a; }
int Triad::getB() { return b; }
int Triad::getC() { return c; }
void Triad::setA(int A) { a = A; }
void Triad::setB(int B) { b = B; }
void Triad::setC(int C) { c = C; }

Triad& Triad::first_add1() { a++; return *this; }

Triad& Triad::second_add1() { b++; return *this; }

Triad& Triad::third_add1() { c++; return *this; }

Triad& Triad::operator ++() { a++; b++; c++; return *this; }

Triad Triad::operator ++(int) {
	Triad temp(*this);
	a++; b++; c++;
	return temp;
}

std::ostream& operator <<(std::ostream& os, Triad const& obj) {
	return os << obj.a << " " << obj.b << " " << obj.c;
}

std::istream& operator >>(std::istream& os, Triad& obj) {
	int a, b, c;
	os >> a >> b >> c;
	obj.setA(a);
	obj.setB(b);
	obj.setC(c);
	return os;
}


Date::Date() { a = b = c = 0; }

Date::Date(int _a, int _b, int _c) { a = _a; b = _b; c = _c; }

Date::Date(Date const& other) {
	a = other.a; b = other.b; c = other.c;
}
Date::Date(Triad& other) {
	a = other.getA(); b = other.getB(); c = other.getC();
}


Date& Date::first_add1() {
	Triad::first_add1();
	normalize();
	return *this;
}

Date& Date::second_add1() {
	Triad::second_add1();
	normalize();
	return *this;
}

Date& Date::third_add1() {
	Triad::third_add1();
	return *this;
}

Date& Date::operator ++() {
	Triad::operator++();
	normalize();
	return *this;
}

Date Date::operator ++(int) {
	Date temp(*this);
	Triad::operator++();
	normalize();
	return temp;
}


void Date::normalize() {
	int daysInMonth[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (b > 12) {
		c++;
		b = 1;
	}
	else {
		int maxDay = daysInMonth[b - 1]; 
		if (b == 2 && ((c % 4 == 0 && c % 100 != 0) || c % 400 == 0)) {
			maxDay = 29;
		}

		if (a < 1 || a > maxDay) {
			while (a > maxDay) {
				a -= maxDay;
				b++;

				if (b > 12) {
					b = 1; 
					c++; // Новый год
				}

				maxDay = daysInMonth[b - 1]; 
				if (b == 2 && ((c % 4 == 0 && c % 100 != 0) || c % 400 == 0)) {
					maxDay = 29;
				}
			}
		}
	}
}

Date& Date::dateIncrease(int n) {
	a += n;
	normalize();
	return *this;
}

std::ostream& operator <<(std::ostream& os, Date const& obj) {
	if (obj.a < 10 && obj.b < 10) {
		return os << "0" << obj.a << ".0" << obj.b << "." << obj.c;
	} else if (obj.a < 10) {
		return os << "0" << obj.a << "." << obj.b << "." << obj.c;
	} else if (obj.b < 10) {
		return os << obj.a << ".0" << obj.b << "." << obj.c;
	} else {
		return os << obj.a << "." << obj.b << "." << obj.c;
	}
}

std::istream& operator >>(std::istream& os, Date& obj) {
	int a, b, c;
	os >> a >> b >> c;
	obj.setA(a);
	obj.setB(b);
	obj.setC(c);
	return os;
}