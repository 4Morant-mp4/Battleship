#include <iostream>

int main()
{
    //An array is a list of elements of a specific type.
    //Arrays are declared in c++ as: <type> arrayName [] = {};
    int numsToTen[] = {1,2,3,4,5,6,7,8,9,10};
   
    //When you try to print an array, it is going to
    //return the location in memory of that array, rather than
    //the contents of the array. You must print the array as you
    //iterate through it.
    std::cout<<"location in memory: " << numsToTen << "\n";
    
    //to traverse arrays of a set size, you need a for loop
    std::cout<<"Numbers to 10: ";
    for (int i=0; i<10; i++)
    {
        std::cout<<numsToTen[i]<<" ";
    }

    //you can change elements at certain indices of arrays
    //plug that index between the brackets and set the new
    //index equal to whatever you want it to be.
    std::cout<<"\nEven numbers to 20: ";
    int numsTo20[10];
    for (int i=0; i<10; i++)
    {
        numsTo20[i] = numsToTen[i]*2;
        std::cout<<numsTo20[i]<<" ";
    }

    //Traversing arrays of an unknown or changing size gets a little trickier
    //Unlike java, there is no .length() function for arrays in c++
    //Instead, we use the sizeof() function which returns the size of a:
    //variable, list, data type, class, objects, etc.
    std::cout<<"\nSize of integers: "<< sizeof(int) << " bytes";

    //So, if you have a list comprised solely of a specific data type,
    //You can take the total size of that array and divide it by
    //the size of the specific data type to find the number of elements:
    int size = sizeof(numsToTen)/sizeof(numsToTen[0]);
    std::cout<<"\nThe number of elements in numsToTen is: " << size;

    //You can also traverse an array without knowing the size using a for each loop:
    std::cout<<"\nLet's just reprint numsTo20: ";
    for (int element:numsTo20)
    {
        element*=4;
        std::cout<<element<<" ";
    }

    //This is especially good if you do not need to permanently alter the array contents.
    std::cout<<"\nLet's just reprint numsTo20 (again): ";
    for (int element:numsTo20)
    {
        std::cout<<element<<" ";
    }

    //Lastly, you can sort an array using nested loop and a temp variable:
    int scatteredList[] = {4, 3, 10, 9, 7, 1};
    int scatteredListSize=sizeof(scatteredList)/sizeof(scatteredList[0]);
    std::cout<<"\nAscending ScatteredList: ";
    int temp;
    for (int i=0; i<scatteredListSize;i++){
        for (int j=i;j<scatteredListSize;j++){
            if (scatteredList[i]>scatteredList[j]){
                temp = scatteredList[i];
                scatteredList[i] = scatteredList[j];
                scatteredList[j] = temp;
            } 
        }

        std::cout<<scatteredList[i]<<" ";
    }

    return 0;
}