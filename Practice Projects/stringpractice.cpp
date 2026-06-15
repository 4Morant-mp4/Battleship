#include <iostream>

int main()
{
    //strings can be used like arrays to print out a specific value at an index
    std::string example1 = "Cookies";
    std::cout<<example1[3]<<"\n";

    std::string example2 = "4932";
    std::cout<<example2[0]<<"\n";

    //I think this operator is taking the decimal value of example2[0] ('4', or 52) and 
    //adding that to the decimal value of the character '1' (49) and then returning that decimal value (101)
    std::cout<<example2[0]+'1'<<"\n";

    //meaning, if you that computation to returnt the actual number stored in the string
    //plus the number you want, you have to subtract 49 (which is also the character '0')
    //from the string at index i and then
    //add the number you want to add

    std::cout<<(example2[0]-'0')+1<<"\n";

    return 0;
}