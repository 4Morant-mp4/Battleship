#include <iostream>
#include <string>

int main ()
{
    std::string name;
    std::string city;

    std::cout << "\nEnter your name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << "!";

    /* You can take a string with spaces by using std::getline(std::cin, city)
    Just be sure to clear the input buffer if you take any other input before using getline
    Change std::getline(std::cin, city); to std::getline(std::cin >> std::ws, city); */

    std::cout <<"\nWhat city do you live in? ";
    std::getline(std::cin>>std::ws, city); // To consume the newline character left in the input buffer
    std::cout << "I have heardT " << city << " is a beautiful place!\n";
    
    return 0;
}