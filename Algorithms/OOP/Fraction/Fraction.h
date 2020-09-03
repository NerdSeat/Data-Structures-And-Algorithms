#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction();
    Fraction(int num);
    Fraction(int num, int denom);
    void factor();
    Fraction operator=(const Fraction &frac);
    friend Fraction operator+(const Fraction &frac1, const Fraction &frac2);
    friend Fraction operator-(const Fraction &frac1, const Fraction &frac2);
    friend Fraction operator/(const Fraction &frac1, const Fraction &frac2);
    friend Fraction operator*(const Fraction &frac1, const Fraction &frac2);
    friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);
    friend std::istream &operator>>(std::istream &input, Fraction &frac);
    int min(int a, int b);

    ~Fraction();
};
#endif