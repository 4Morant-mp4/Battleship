#include <iostream>
#include <cmath>

int main()
{
    // This function takes the greatest of two numbers
    int a = 4;
    int b = 2;
    int c;
    int d;
    int e;

    c = std::max(a, b);
    std::cout << "The greatest number between " << a << " and " << b << " is " << c << std::endl;

    // This function takes the smallest of two numbers
    d = std::min(a, b);
    std::cout << "The smallest number between " << a << " and " << b << " is " << d << std::endl;

    //This function raises a to the power of b
    e = pow(a, b);
    std::cout << a << " raised to the power of " << b << " is " << e << std::endl;

    //This function calculates the square root of a number
    int f = sqrt(a);
    std::cout << "The square root of " << a << " is " << f<< std::endl;

    //This function calculates the absolute value of a number
    int g = abs(-5);
    std::cout << "The absolute value of -5 is " << g << std::endl;

    //This function calculates the rounded value of a number
    double h = round(4.2);
    std::cout << "The rounded value of 4.2 is " << h << std::endl;

    //You can find more math functions in the cmath library at cplusplus.com/reference/cmath/


    return 0;
}