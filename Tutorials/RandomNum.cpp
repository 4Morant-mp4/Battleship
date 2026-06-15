#include <iostream>
#include <ctime>

int main()
{
    //coders usually use the current calendar time to
    //generate a random number.

    srand(time(NULL));

    int num = rand();

    std::cout << num << "\n";

    //If you want to generate a number in a certain
    //range x to n, take the n-(x-1) modulus of rand()
    //then add x to that.

    //Numbers 1-5
    int num2 = rand() % 5 + 1;
    std::cout << num2 << "\n";

    //Numbers 1-20
    int num3 = rand() % 20 + 1;
    std::cout << num3 << "\n";

    //Numbers 5 - 20
    int num4 = rand() % 16 + 5;
    std::cout << num4 << "\n";

}