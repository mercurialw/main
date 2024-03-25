#include "ClassesComposition.h"
//#include <iostream>
#include <string>

Money::Money()
{
	rubles = new int(0);
	kopeks = new int(0);
}

Money::Money(int _rubles, int _kopeks)
{
	rubles = new int(_rubles);
	kopeks = new int(_kopeks);
}

Money::~Money()
{
	delete rubles;
	delete kopeks;
}

Money::Money(const Money& other)
{
	rubles = kopeks = nullptr;
	rubles = new int(*(other.rubles));
	kopeks = new int(*(other.kopeks));
}

int* Money::getRubles() { return rubles; }
int* Money::getKopeks() { return kopeks; }
void Money::setRubles(int _rubles) { *rubles = _rubles; }
void Money::setKopeks(int _kopeks) { *kopeks = _kopeks; }


Money& Money::operator=(const Money& other)
{
	*rubles = *(other.rubles);
	*kopeks = *(other.kopeks);
	return *this;
}

bool Money::operator==(const Money& other)
{
	return *rubles == *(other.rubles) && *kopeks == *(other.kopeks);
}

bool Money::operator !=(const Money& other)
{
	return *rubles != *(other.rubles) && *kopeks != *(other.kopeks);
}

bool Money::operator>(const Money& other)
{
	if (*rubles > *(other.rubles)) { return true; }
	else if (*rubles < *(other.rubles)) { return false; }
	else
	{
		if (*kopeks > *(other.kopeks)) { return true; }
		else { return false; }
	}
}

bool Money::operator>=(const Money& other)
{
	if (*rubles > *(other.rubles)) { return true; }
	else if (*rubles < *(other.rubles)) { return false; }
	else
	{
		if (*kopeks >= *(other.kopeks)) { return true; }
		else { return false; }
	}
}

bool Money::operator<(const Money& other)
{
	if (*rubles < *(other.rubles)) { return true; }
	else if (*rubles > *(other.rubles)) { return false; }
	else
	{
		if (*kopeks < *(other.kopeks)) { return true; }
		else { return false; }
	}
}

bool Money::operator<=(const Money& other)
{
	if (*rubles < *(other.rubles)) { return true; }
	else if (*rubles > *(other.rubles)) { return false; }
	else
	{
		if (*kopeks <= *(other.kopeks)) { return true; }
		else { return false; }
	}
}

Money Money::operator+(const Money& other)
{
	return Money(*rubles + *(other.rubles) + (*kopeks + *(other.kopeks)) / 100, *kopeks + *(other.kopeks) - (*kopeks + *(other.kopeks)) / 100 * 100);
}

Money Money::operator-(const Money& other) {
	if (*kopeks - *(other.kopeks) < 0)
	{
		return Money(*rubles - *(other.rubles) - 1, *kopeks - *(other.kopeks) + 100);
	}
	else
	{
		return Money(*rubles - *(other.rubles), *kopeks - *(other.kopeks));
	}
}

Money Money::operator*(const double n)
{
	return Money(((int)((*rubles * 100 + *kopeks) * n)) / 100, ((int)((*rubles * 100 + *kopeks) * n)) % 100);
}

Money Money::operator/(const double n)
{
	return Money(((int)((*rubles * 100 + *kopeks) / n)) / 100, ((int)((*rubles * 100 + *kopeks) / n)) % 100);
}

double Money::operator/(const Money& other)
{
	return ((double)((*rubles) * 100 + (*kopeks))) / ((*(other.rubles)) * 100 + (*(other.kopeks)));
}

std::ostream& operator<<(std::ostream& os, Money& obj)
{
	return os << *(obj.rubles) << "." << *(obj.kopeks);
}

std::istream& operator>>(std::istream& os, Money& obj)
{
	double a;
	os >> a;
	obj.setRubles((int)(a * 100) / 100);
	obj.setKopeks((int)(a * 100) % 100);
	return os;
}





Bankomat::Bankomat() { id = 0; Money currentSum, maxSum, minSum; }
Bankomat::Bankomat(int id) : id(id) { Money currentSum, maxSum, minSum; }
Bankomat::Bankomat(int id, Money currentSum, Money maxSum, Money minSum) :
	id(id), currentSum(currentSum), maxSum(maxSum), minSum(minSum) {}

int Bankomat::getId() { return id; }
Money& Bankomat::getCur() { return currentSum; }
Money& Bankomat::getMax() { return maxSum; }
Money& Bankomat::getMin() { return minSum; }
void Bankomat::setCur(Money _currentSum) { currentSum = _currentSum; }
void Bankomat::setMax(Money _maxSum) { maxSum = _maxSum; }
void Bankomat::setMin(Money _minSum) { minSum = _minSum; }

void Bankomat::withdraw(Money& sum, bool& is_ok)
{
	Money tempsum;
	while (true) {
		std::cin >> tempsum;
		if (tempsum > currentSum || tempsum < minSum || tempsum > maxSum) { is_ok = 0; return; }
		else {
			currentSum = currentSum - tempsum;
			sum = sum + tempsum;
			return;
		}
	}
}

void Bankomat::deposit(Money& sum, bool& is_ok)
{
	Money tempsum;
	while (true) {
		std::cin >> tempsum;
		if (tempsum > sum) { is_ok = 0; return; }
		else {
			currentSum = currentSum + tempsum;
			sum = sum - tempsum;
			return;
		}
	}
}

std::string Bankomat::toString()
{
	return std::to_string(*currentSum.getRubles()) + "." + std::to_string(*currentSum.getKopeks());
}

Money doubleToMoney(const double temp)
{
	return Money((int)temp, (int)((temp - (int)temp) * 100));
}


std::ostream& operator<<(std::ostream& os, Bankomat& A)
{
	return os << A.getCur();
}