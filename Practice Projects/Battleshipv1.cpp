#include <iostream>
#include <vector>

void instructions();
void makeBoard();
void drawBoard();
void editBoard();

/*class Ship{
    public:
    char startingRow;
    char endingRow;
    int startingCol;
    int endingCol;
    int size;
    
    Ship(char startRow, int startCol, int uSize);
   
};


Ship::Ship(char startRow, int startCol, int uSize){
    startingRow = startRow;
    startingCol = startCol;
    size = uSize;
}*/

int main()
{
    instructions();
    drawBoard();

    char shipType, startRow, endRow, orientation, userOcean[10][10], direction;
    int startCol, endCol, uSize, rowInp;
    
    do{
        std::cout<<"Which ship would you like to move?"<<"\n";
        std::cout<<"Please type \"A\", for Airship, \"B\" for Battleship, \"C\" for Cruiser, \"D\" for Destroyer, or \"S\" for Submarine"<<'\n';
        std::cout<<"When You are finished moving your ships, please type \"F\""<<'\n';
        std::cin>>shipType;
        (char)toupper(shipType);

        if (shipType=='A')
        {
            std::cout<<"You have chosen: The Aircraft Carrier"<<'\n';
            uSize = 5;
            do{
                std::cout<<"Which orientation would you like? Type \'H\' for horizontal or \'V\' for vertical: ";
                std::cin>>orientation;
                (char)toupper(orientation);
            } while (orientation != 'H' && orientation != 'V');    
            
            if (orientation == 'H'){

                std::cout<<"Which row would you like the ship to be in (from A-J)?: ";
                std::cin>>rowInp;
                rowInp = toupper(rowInp);
                startRow = rowInp - 64;
            
                while ((startRow < 1) || (startRow > 10)){
                    std::cout<<"You have entered an invalid char. Please enter a character (A-J): "<<std::endl;
                    std::cin>>rowInp;
                    rowInp = toupper(rowInp);
                    startRow = rowInp - 64;
                }

                std::cout<<"You picked row: ";
                std::cout<<startRow<<std::endl;

                std::cout<<"Which column would you like the back of the ship to be in?: ";
                std::cin>>startCol;

                while (startCol < 1 || startCol > 10)
                {
                    std::cout<<"You have entered an invalid char. Please enter a character (A-J): "<<std::endl;
                    std::cin>>startCol;
                }

                std::cout<<"You picked column: "<<startCol<<std::endl;

                if (startCol > 5){
                    endCol = startCol - 5;
                }
                else if (startCol < 5){
                    endCol = startCol + 5;
                }
                else{
                    do{
                    std::cout<<"which direction would you like to the ship to lay in? Left (L) or Right (R)?: ";
                    std::cin>>direction;
                    (char)toupper(direction);
                    }while (direction != 'L' || direction !='R');

                    if (direction = 'L')
                    {
                        endCol = startCol - 5;
                    }
                    else
                    {
                        endCol = startCol + 5;
                    }
                }

                editBoard(userOcean, shipType, startRow, startCol, endCol, uSize, orientation);
            }

            shipType = '+';
        }
        else if(shipType=='B')
        {
            std::cout<<"You have chosen: The Battleship"<<'\n';
            shipType = '+';
        }
        else if(shipType=='C')
        {
            std::cout<<"You have chosen: The Cruiser"<<'\n';
            shipType = '+';
        }
        else if(shipType=='D')
        {
            std::cout<<"You have chosen: The Destroyer"<<'\n';
            shipType = '+';
        }
        else if(shipType=='F')
        {
            break;
        }
        else
        {
            std::cout<<"That is not a valid input :/"<<'\n';
        }

    } while (shipType!='A' && shipType!='B' && shipType!='C' && shipType!='D' && shipType!='S' && shipType!='F');
    
    return 0;
}


void editBoard(char ocean[10][10], char shipType, int startRow, int startCol, int endCol, int size, char orientation){
    // need to implement a board check that sees if there is enough space in row to fit ship type. Will make another method for this.
    // also realizng that this does not permanently edit the array. will try to find a way to edit it without declaring globally.
    if (orientation = 'H'){
        for (int i=startCol; i<=endCol; i++){
            ocean[startRow][i] = shipType;
        }
    }


}

void drawBoard(char ocean[10][10])
{
    char ocean[10][10]={};

    int i, j;

    std::cout << "Your Ship Setup:\n";
    std:: cout<< "    "<< "  1   2   3   4   5   6   7   8   9   10"<<'\n'; //column names
    for (i = 0; i < 10; i++) {
        switch (i){ //This makes the row names
                case 0:
                    std::cout<< 'A' << "   ";
                    break;
                case 1:
                    std::cout<< 'B' << "   ";
                    break;
                case 2:
                    std::cout<< 'C' << "   ";
                    break;
                case 3:
                    std::cout<< 'D' << "   ";
                    break;
                case 4:
                    std::cout<< 'E' << "   ";
                    break;
                case 5:
                    std::cout<< 'F' << "   ";
                    break;
                case 6:
                    std::cout<< 'G' << "   ";
                    break;
                case 7:
                    std::cout<< 'H' << "   ";
                    break;
                case 8:
                    std::cout<< 'I' << "   ";
                    break;
                case 9:
                    std::cout<< 'J' << "   ";
                    break;
            }
        std::cout<<"| ";
        for (j = 0; j < 10; j++) {
            if (ocean[i][j]==' '){
                std::cout<<"  | ";
            }
            else{
                std::cout<<"~ | ";
            }
        }
        std::cout<<"\n"<<"    "<<"- - - - - - - - - - - - - - - - - - - - -";
        std::cout << std::endl;
    }

}

void instructions()
{
    std::cout<<"Welcome to Battleship!"<<'\n';
    std::cout<<"-----------------------------------------------"<<'\n';
    std::cout<<"Here's how it works:"<<'\n'<<"Each player will have 5 ships, each of varying sizes:"<<'\n';
    std::cout<<"\t"<<"The aircraft carrier (5 spaces)"<<"\n\t"<<"The Battleship (4 spaces)"<<"\n\t";
    std::cout<<"The cruiser (3 spaces)"<<"\n\t"<<"The Destroyer (3 spaces)"<<"\n\t"<<"The submarine (2 spaces)"<<'\n';
    std::cout<<"Each player will strategically organize their ships on a 10x10 board in either a vertical or horizontal orientation."<<'\n';
    std::cout<<"Both players will also be given an empty 10x10 board to coordinate and track attacks on the enemy's ships."<<"\n";
    std::cout<<"The first player to clear all of the enemy's ships is the victor!"<<'\n';
    std::cout<<"May the best captain win."<<'\n';
    std::cout<<"-----------------------------------------------"<<'\n';
}
