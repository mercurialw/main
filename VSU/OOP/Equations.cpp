#include "Equations.h"
#include "cmath"
#include <string>

Root::Root() : roots(nullptr), coefs(nullptr) {}
Root::Root(double a, double b) : roots(nullptr), coefs(new double[2]{a, b}) {};
Root::Root(double a, double b, double c) : roots(nullptr), coefs(new double[3] {a, b, c}) {};

Root::~Root() {
	if (roots != nullptr) {
		if (is_massive)
			delete[] roots;
		else
			delete roots;
	}
	if (coefs != nullptr)
		delete[] coefs;
}

double* Root::getCoefs() { return coefs; }

double* Root::getRoots() {
	root();
	return roots;
}
void Root::setCoefs(double* massive) { coefs = massive; }

Linear::Linear() : Root(0, 0) {}
Linear::Linear(double a, double b) : Root(a, b) {}


void Linear::root() {
	if (coefs[0] == 0) {
		roots = nullptr;
	}
	else if (coefs[1] == 0) {
		roots = new double(0);
	}
	else {
		roots = new double(-coefs[1] / coefs[0]);
	}
}

std::string Linear::getAnswer() {
	if (roots == nullptr) {
		if (coefs[0] == 0 && coefs[1] == 0) {
			return "Бесконечное множество корней";
		}
		else {
			return "Нет корней";
		}
	}
	return "";
}

void Linear::input() {
	std::cin >> coefs[0] >> coefs[1];
}

std::string Linear::to_string() {
	std::string msg;
	msg += std::to_string(coefs[0]);
	msg += " * x ";
	if (coefs[1] < 0) {
		msg += "- ";
		msg += std::to_string(-coefs[1]);
	}
	else {
		msg += "+ ";
		msg += std::to_string(coefs[1]);
	}
	msg += " = 0";
	return msg;
}

Square::Square() : Root(0, 0, 0) {}
Square::Square(double a, double b, double c) : Root(a, b, c) {}

void Square::root() {
	double D = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
	if (coefs[0] == 0 && coefs[1] == 0 || D < 0) {
		roots = nullptr;
		is_massive = 0;
	}
	else if (coefs[0] == 0 && coefs[2] == 0 || coefs[1] == 0 && coefs[2] == 0) {
		roots = new double(0);
		is_massive = 0;
	}
	else if (D == 0) {
		roots = new double(-coefs[1] / (2 * coefs[0]));
		is_massive = 0;
	}
	else if (coefs[0] == 0) {
		roots = new double(-coefs[2] / coefs[1]);
		is_massive = 0;
	}
	else if (coefs[2] == 0) {
		roots = new double[2] {0, -coefs[1] / coefs[0]};
		is_massive = 1;
	} else {
		roots = new double[2] { (-coefs[1] + sqrt(D)) / (2 * coefs[0]), (-coefs[1] - sqrt(D)) / (2 * coefs[0])};
		is_massive = 1;
	}
}

std::string Square::getAnswer() {
	if (roots == nullptr) {
		double D = coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
		if (coefs[0] == 0 && coefs[1] == 0 && coefs[2] == 0) {
			return "Бесконечное множество корней";
		}
		else if (coefs[0] == 0 && coefs[1] == 0 || D < 0) {
			return "Нет корней";
		}
	}
	return "";
}

void Square::input() {
	std::cin >> coefs[0] >> coefs[1] >> coefs[2];
}

std::string Square::to_string() {
	std::string msg;
	msg += std::to_string(coefs[0]);
	msg += " * x^2 ";
	if (coefs[1] < 0) {
		msg += "- ";
		msg += std::to_string(-coefs[1]);
	}
	else {
		msg += "+ ";
		msg += std::to_string(coefs[1]);
	}
	msg += " * x ";
	if (coefs[2] < 0) {
		msg += "- ";
		msg += std::to_string(-coefs[2]);
	}
	else {
		msg += "+ ";
		msg += std::to_string(coefs[2]);
	}
	msg += " = 0";
	return msg;
}