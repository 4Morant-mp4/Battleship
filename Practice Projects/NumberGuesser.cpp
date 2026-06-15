#include <iostream>
#include <ctime>

int main()
{
    srand(time(NULL));
    int num = (rand()%20)+1;
    int guess;
    int count = 1;

    std::cout<<"************************************"<<"\n";
    std::cout<<"  WELCOME TO THE NUMBER GUESSER!"<<"\n";
    std::cout<<'\n'<<"I'm thinking of a number 1-20.\n";
    std::cout<<"What is the number?: ";
    std::cin>>guess;

    if(guess==num)
    {
        std::cout<< '\n' << num << " is correct!!\nYou solved it in "<<count<<" tries!";
    }
    else
    {
      do
        {
            std::cout<<"\nThat is incorrect >:)\n";
            std::cout<<"Try again: ";
            std::cin>>guess;
            count++;

        }while(guess != num);

    std::cout<< '\n' << num << " is correct!!\nYou solved it in "<<count<<" tries!";
    }

    return 0;  
}