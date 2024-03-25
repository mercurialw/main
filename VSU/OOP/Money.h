#include <iostream>
#include <string>

using namespace std;

class Money {
private:
    int* rubles;
    int* kopeks;

public:
    Money();
    Money(int, int);
    ~Money();
    Money(const Money&);

    int* getRubles();
    int* getKopeks();
    void setRubles(int);
    void setKopeks(int);

    Money& operator=(const Money&);
    bool operator==(const Money&);
    bool operator!=(const Money&);
    bool operator>(const Money&);
    bool operator>=(const Money&);
    bool operator<(const Money&);
    bool operator<=(const Money&);

    Money operator+(const Money&);
    Money operator-(const Money&);
    Money operator*(const int);
    Money operator/(const int);

    friend ostream& operator<<(ostream&, Money&);
    friend istream& operator>>(istream&, Money&);
};