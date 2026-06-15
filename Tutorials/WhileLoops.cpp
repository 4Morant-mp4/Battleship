#include <iostream>
#include <String>

int main()
{
    std::string name;
    std::cout<<"please enter your name: ";
    std::getline(std::cin, name);

/*  Let's say, for example, we want the user to actually enter a name
    so we can run the rest of the code. In this case, we can use
    a while loop:
*/

    while(name.empty())
    {
        std::cout<<"\nYou did not enter a valid name." << "\n";
        std::cout<<"please enter your name: ";
        std::getline(std::cin, name);
    }
    
    std::cout<<"\nHello " << name << "!" << "\n";

/*
    There are also do while loops. These loops perform a block of code,
    then they repeat again if the condition at the end is true.
*/

    int num;

    do
    {
        std::cout<<"Enter a positive number: ";
        std::cin>>num;
    }while(num<0);

    std::cout<<"\n" << name << "'s number is " << num;

/*
    I could have rewrote the name retrieval part of the code as a do while:

    std::string name;
    do
    {
        std::cout<<"Enter your name: ";
        std::getline(std::cin,name);
    }while(name.empty());

    Much nicer, and saves us a few lines of code. Only issue is I would
    have had to omit the "That is not a valid name" part, or make an if
    statement for it.
*/

    return 0;
}
