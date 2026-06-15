#include <iostream>
#include <ctime>

int winCount;
int lossCount;
int drawCount;

char getComputerChoice();
void computeWinner(char userChoice, char computerChoice);

int main(){
    char userChoice;
    char computerChoice;
    char keepPlaying;

    std::cout<<"\nWelcome to Rock Paper Scissors!\n";
    do
    {
        std::cout<<"*********************************\n";
        std::cout<<"Enter your choice -> Rock (R), Paper(P), or Scissors(S): ";
        std::cin>>userChoice;

        while (userChoice != 'r' && userChoice != 'R' && userChoice != 'p' && userChoice!='P' && userChoice != 'S' && userChoice != 's')
        {
            std::cout<<"\nThat is not a valid choice.\n"<<"Please enter R, P,  or S: ";
            std::cin>>userChoice;
        }

        computerChoice = getComputerChoice();
        std::cout<<"\nYour choice: "<< userChoice;
        std::cout<<"\nComputer Choice: "<< computerChoice;

        computeWinner(userChoice, computerChoice);
        std::cout<<"\n\n*********************************";
        std::cout<<"\nPlay Again? (y/n): ";
        std::cin>>keepPlaying;

    } while (keepPlaying == 'y' || keepPlaying =='Y');
    
    std::cout<<"*********************************";
    std::cout<<"\nWins: " << winCount << "\nLosses: " << lossCount << "\nDraws: " << drawCount << '\n';
    std::cout<<"Thanks for Playing!";

    return 0;
}

char getComputerChoice()
{
    srand(time(NULL));
    int num = rand()%3+1;
    char choice;

    switch (num)
    {
        case 1:
            choice = 'R';
            break;
        case 2:
            choice = 'P';
            break;
        case 3:
            choice = 'S';
    }
    return choice;
}

void computeWinner(char user, char comp)
{
    std::string win = "\nYou Win! :D";
    std::string lose = "\nYou lose :(";
    std::string tie = "\nIt's a draw! :O";

    if ((user == 'r' || user =='R') && comp == 'S')
    {
        std::cout<< win;
        winCount++;
    }
    else if ((user == 'P' || user =='p') && comp == 'R'){
        std::cout<<win;
        winCount++;
    }
    else if ((user == 's' || user =='S') && comp == 'P'){
        std::cout<<win;
        winCount++;
    }
    else if((user == 'r' || user =='R') && comp == 'P'){
        std::cout<<lose;
        lossCount++;
    }
    else if((user == 's' || user =='s') && comp == 'R'){
        std::cout<<lose;
        lossCount++;
    }
    else if((user == 'p' || user =='P') && comp == 'S'){
        std::cout<<lose;
        lossCount++;
    }
    else{
        std::cout<<tie;
        drawCount++;
    }
}