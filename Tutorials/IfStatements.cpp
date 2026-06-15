#include <iostream>
#include <string>

int main ()
{
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age > 18) {
        std::cout << "You are an adult.\n";
    }
    else if (age == 18) {
        std::cout << "You are just an adult.\n";
    }
    else if (age == 100) {
        std::cout << "You are a century old!\n";
    }
    else if (age > 13) {
        std::cout << "You are a teenager.\n";
    }
    else if (age == 13) {
        std::cout << "You are just a teenager.\n";
    }
    else if (age > 3) {
        std::cout << "You are a child.\n";
    }
    else if (age == 3) {
        std::cout << "You are just a child.\n";
    }
    else {
        std::cout << "You are a minor.\n";
    }

    /* Remember that the order of if and else if statements is very important.
    You also want to try and avoid using too many else if statements by using switches.*/

    int month;
    std::cout << "Enter a month number (1-12): ";
    std::cin >> month;

    switch(month) {
        case 1:
            std::cout << "January\n";
            break;
        case 2:
            std::cout << "February\n";
            break;
        case 3:
            std::cout << "March\n";
            break;
        case 4:
            std::cout << "April\n";
            break;
        case 5:
            std::cout << "May\n";
            break;
        case 6:
            std::cout << "June\n";
            break;
        case 7:
            std::cout << "July\n";
            break;
        case 8:
            std::cout << "August\n";
            break;
        case 9:
            std::cout << "September\n";
            break;
        case 10:
            std::cout << "October\n";
            break;
        case 11:
            std::cout << "November\n";
            break;
        case 12:
            std::cout << "December\n";
            break;
        default:
            std::cout << "Invalid month number.\n";
    }   

    // This is more efficient because it avoids multiple comparisons once a match is found.
    // Note: Switch statements only work with integral types (like int, char) and enum types.

    // You can also use the conditional (ternary) operator for simple if-else conditions
    // syntax: (condition) ? (expression_if_true) : (expression_if_false);
    
    int number;
    
    std::cout << "Enter a number: ";
    std::cin >> number;
    
    std::string result = (number % 2 == 0) ? "Even" : "Odd";
    
    std::cout << number << " is " << result << std::endl;

    return 0;
}