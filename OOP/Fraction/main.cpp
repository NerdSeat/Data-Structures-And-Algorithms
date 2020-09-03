
#include "Fraction.cpp"
int main()
{
    Fraction half(1, 2);
    Fraction quater(1, 4);
    Fraction sum = half + quater;
    sum.factor();
    
    Fraction difference = half - quater;
    difference.factor();
    
    Fraction product = half * quater;
    product.factor();

    Fraction quotient = half / quater;
    quotient.factor();

    std::cout << half << " + " << quater << " = " << sum<< std::endl;
    std::cout << half << " - " << quater << " = " << difference << std::endl;
    std::cout << half << " * " << quater << " = " << product << std::endl;
    std::cout << half << " / " << quater << " = " << quotient<< std::endl;

    return 0;
}