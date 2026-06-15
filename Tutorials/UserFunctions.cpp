#include <iostream>
#include <string>

// Our compiler reads the code from top to bottom, meaning
// you cannot place a user-defined function after the main
// function unless you declare it first.

int until2030(int thisYear);

void whoMadeThatMess()
{
    std::cout<<"\nWho made that mess!!? >:)\n";
    std::cout<<"You did King!! :(\n";
    std::cout<<"I made the mess ? >:P\n";
    std::cout<<"Yessss king!!";
}

int main()
{
    std::string mess;
    std::string name;
    int year;

    do
    {
        std::cout<<"Is there a mess (y/n)? ";
        std::getline(std::cin, mess);

    }while (mess!="y" && mess!="n" && mess!="Y" && mess!="N");

    if (mess=="y"||mess=="Y")
    {
        whoMadeThatMess();
    }
    else
    {
        std::cout<<"\nOh great!\n"<<"What's your name? ";
        std::getline(std::cin, name);
        std::cout<<"Hey, "<<name<<"!\nWhat year is it? ";
        std::cin>>year;
        std::cout<<"Wow! That's "<<until2030(year)<<" years until 2030!";

    }

    return 0;
}

// We can also make code that returns something and stores
// that in the form of a variable.
// Just be sure to change "void" to the type of variable
// being retured.

// Also, we can take in a value and use that value in our code
// Just put it in the parenthesis along with the value
// being entered. We can take in multiple values, each of diff types.

int until2030(int thisYear)
{
    return 2030-thisYear;
}