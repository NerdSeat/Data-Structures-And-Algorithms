#include "Fraction.h"

Fraction::Fraction(int num, int denom)
    : numerator(num), denominator(denom) {}

Fraction::Fraction(int num)
    : numerator(num), denominator(1) {}

Fraction::Fraction() {}

Fraction::~Fraction() {}

void Fraction::factor()
{
    int gcd = min(numerator, denominator);

    while (gcd != 0)
    {
        if ((denominator % gcd == 0) && (numerator % gcd == 0))
            break;
        gcd--;
    }
    this->numerator /= gcd;
    this->denominator /= gcd;
}

Fraction Fraction::operator=(const Fraction &frac)
{
    this->numerator = frac.numerator;
    this->denominator = frac.denominator;
    return *this;
}

Fraction operator+(const Fraction &frac1, const Fraction &frac2)
{
    int num = (frac1.numerator * frac2.denominator) + (frac2.numerator * frac1.denominator);
    int denom = frac1.denominator * frac2.denominator;
    Fraction sum(num, denom);
    return sum;
}

Fraction operator-(const Fraction &frac1, const Fraction &frac2)
{
    int num = (frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator);
    int denom = frac1.denominator * frac2.denominator;
    Fraction difference(num, denom);
    return difference;
}
Fraction operator*(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.numerator * frac2.numerator;
    int denom = frac1.denominator * frac2.denominator;
    Fraction product(num, denom);
    return product;
}
Fraction operator/(const Fraction &frac1, const Fraction &frac2)
{
    int num = frac1.numerator * frac2.denominator;
    int denom = frac1.denominator * frac2.numerator;
    Fraction quotient(num, denom);
    return quotient;
}
std::ostream &operator<<(std::ostream &output, const Fraction &frac)
{
    if(frac.denominator==1)
        output<<frac.numerator;
    else
        output << frac.numerator << "/" << frac.denominator;

    return output;
}
std::istream &operator>>(std::istream &input, Fraction &frac)
{
    std::cout << "Enter Numerator: ";
    input >> frac.numerator;
    std::cout << "Enter Denominator: ";
    input >> frac.denominator;
    return input;
}

int Fraction::min(int a, int b)
{
    return a < b ? a : b;
}