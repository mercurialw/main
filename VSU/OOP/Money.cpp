#include "Money.h"
#include <iostream>

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

Money Money::operator*(const int n)
{
	return Money((*rubles) * n + (*kopeks) * n / 100, (*kopeks) * n % 100);
}

Money Money::operator/(const int n)
{
	return Money(((*rubles) * 100 + (*kopeks)) / n / 100, ((*rubles) * 100 + (*kopeks)) / n % 100);
}

ostream& operator<<(ostream& os, Money& obj)
{
	return os << "Кол-во рублей - " << *(obj.rubles) << ", кол-во копеек - " << *(obj.kopeks) << ".\n";
}
istream& operator>>(istream& os, Money& obj)
{
	return os >> *(obj.rubles) >> *(obj.kopeks);
}
