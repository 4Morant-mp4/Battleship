#include <iostream>
#include <string>

int main(){
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    /* Using the .length() function
   
    if (name.length() > 12)
    {
        std::cout << "Your name is too long.\n";
    }
    else
    {
        std::cout << "Your name is just right.\n";
    }
    */



    /* using the .empty() function

    if (name.empty())
    {
        std::cout << "You didn't enter a name.\n";
    }
    else
    {
        std::cout << "Hello, " << name << "!\n";
    }
    */



    /* using the .clear() function

    name.clear();
    std::cout << "Your name is now: " << name << "\n";

    */

    return 0;
}