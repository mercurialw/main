#include <iostream>

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
    Money operator*(const double);
    Money operator/(const double);
    double operator/(const Money&);

    friend std::ostream& operator<<(std::ostream&, Money&);
    friend std::istream& operator>>(std::istream&, Money&);
};

class Bankomat
{
private:
    int id;
    Money currentSum, maxSum, minSum;
public:
    Bankomat();
    Bankomat(int);
    Bankomat(int, Money, Money, Money);
    int getId();
    Money& getCur();
    Money& getMax();
    Money& getMin();
    void setCur(Money);
    void setMax(Money);
    void setMin(Money);

    void withdraw(Money&, bool&);
    void deposit(Money&, bool&);
    std::string toString();

    friend std::ostream& operator<<(std::ostream&, Bankomat&);
};

Money doubleToMoney(const double);