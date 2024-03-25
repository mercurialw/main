#include <iostream>

class Triad {
protected:
	int a, b, c;
public:
	Triad();
	Triad(int, int, int);
	Triad(Triad const&);

	int getA();
	int getB();
	int getC();
	void setA(int);
	void setB(int);
	void setC(int);

	Triad& first_add1();
	Triad& second_add1();
	Triad& third_add1();

	Triad& operator ++();
	Triad operator ++(int);

	friend std::ostream& operator <<(std::ostream&, Triad const&);
	friend std::istream& operator >>(std::istream&, Triad&);
};

class Date : public Triad {
public:
	Date();
	Date(int, int, int);
	Date(Date const&);
	Date(Triad &);

	Date& first_add1();
	Date& second_add1();
	Date& third_add1();

	Date& operator ++();
	Date operator ++(int);

	void normalize();

	Date& dateIncrease(int n);
	
	friend std::ostream& operator <<(std::ostream&, Date const&);
	friend std::istream& operator >>(std::istream&, Date&);
};