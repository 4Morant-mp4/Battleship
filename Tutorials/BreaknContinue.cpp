#include <iostream>

int main ()
{

    for(int i=0; i<10;i++)
    {
        if (i==6)
        {
            //We can use the continue function to skip the current
            //iteration of the code.
            continue;
        }

        if (i==9)
        {
            //We can also use the break function to end a loop completely.
            std::cout<<"Code ending. 6 was tolerable. 9 as the last straw...";
            break;
        }
        std::cout<<i<<"\n";
    }
    return 0;
}