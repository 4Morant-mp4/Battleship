#include <iostream>
#include <vector>

// 6/21/26 - Everything works fine. Need to turn the ship placement into a method so i can just call the method for each ship type.
// Also need to make a checking system to see if there is a ship in the spot where the user wants to place their ship
// Also need to add a "clear ship" option
// Also need to fix the loop that should allow user to stop arranging ships
// Finally, figure out how to randomize a computer's ship board. Might be easier to have preset boards than do rng.

void instructions();
void makeBoard();
void drawBoard(char ocean[10][10]);
void editBoardHorizontal(char ocean[10][10], char shipType, int startRow, int startCol, int endCol, int size, char orientation, char direction);
void editBoardVertical(char ocean[10][10], char shipType, int startRow, int endRow, int startCol, int size, char orientation, char direction);

struct Board {
    char grid[10][10];
};

Board createBoard() {
    Board b;
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            b.grid[r][c] = ' ';
    return b;
}

int main()
{
    instructions();
    Board userOcean = createBoard();
    drawBoard(userOcean.grid);
    char shipType, rowInp, orientation, direction;
    int startRow, endRow, startCol, endCol, uSize;
    
    
    do{
        std::cout<<"Which ship would you like to move?"<<"\n";
        std::cout<<"Please type \"A\", for Airship, \"B\" for Battleship, \"C\" for Cruiser, \"D\" for Destroyer, or \"S\" for Submarine"<<'\n';
        std::cout<<"When You are finished moving your ships, please type \"F\""<<'\n';
        std::cin>>shipType;
        shipType = (char)toupper(shipType);

        if (shipType=='A')
        {
            std::cout<<"You have chosen: The Aircraft Carrier"<<'\n';
            uSize = 5;
            do{
                std::cout<<"Which orientation would you like? Type \'H\' for horizontal or \'V\' for vertical: ";
                std::cin>>orientation;
                orientation=(char)toupper(orientation);
            } while (orientation != 'H' && orientation != 'V');    
            
            if (orientation == 'H'){

                do{
                std::cout<<"Which row would you like the ship to be in (from A-J)?: ";
                std::cin>>rowInp;
                rowInp = toupper(rowInp);
                startRow = rowInp - 64;
                }while ((startRow < 1) || (startRow > 10));

                std::cout<<"You picked row: ";
                std::cout<<rowInp<<std::endl;

                do{
                   std::cout<<"Which column would you like the back of the ship to be in (1-10)?: ";
                    std::cin>>startCol; 
                } while (startCol <1 || startCol > 10);
                

                std::cout<<"You picked column: "<<startCol<<std::endl;

                if (startCol > 6){
                    direction = 'L';
                    endCol = startCol - 5;
                }
                else if (startCol < 5){
                    direction = 'R';
                    endCol = startCol + 5;
                }
                else{
                    do{
                    std::cout<<"which direction would you like to the ship to lay in? Left (L) or Right (R)?: ";
                    std::cin>>direction;
                    direction = (char)toupper(direction);
                    }while (direction != 'L' && direction !='R');

                    if (direction == 'L')
                    {
                        startCol++;
                        endCol = startCol-5;
                    }
                    else
                    {
                        endCol = startCol+5;
                    }
                }
                editBoardHorizontal(userOcean.grid, shipType, startRow, startCol, endCol, uSize, orientation, direction);
            }

            if (orientation == 'V'){

                do{
                std::cout<<"Which column would you like the ship to be in (from 1-10)?: ";
                std::cin>>startCol;
                }while ((startCol < 1) || (startCol > 10));

                std::cout<<"You picked column: ";
                std::cout<<startCol<<std::endl;

                do{
                std::cout<<"Which row would you like the back of the ship to be in (from A-J)?: ";
                std::cin>>rowInp;
                rowInp = toupper(rowInp);
                startRow = rowInp - 64;
                }while ((startRow < 1) || (startRow > 10));

                std::cout<<"You picked row: "<<startRow<<std::endl;

                if (startRow > 6){
                    direction = 'U';
                    endRow = startRow - 5;
                }
                else if (startRow < 5){
                    direction = 'D';
                    endRow = startRow + 5;
                }
                else{
                    do{
                    std::cout<<"which direction would you like the ship to lay in? Up (U) or Down (D)?: ";
                    std::cin>>direction;
                    direction = (char)toupper(direction);
                    }while (direction != 'U' && direction !='D');

                    if (direction == 'U')
                    {
                        startRow++;
                        endRow = startRow-5;
                    }
                    else
                    {
                        endRow = startRow+5;
                    }
                }
                
                editBoardVertical(userOcean.grid, shipType, startRow, endRow, startCol, uSize, orientation, direction);
            }

            drawBoard(userOcean.grid);
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



void editBoardHorizontal(char ocean[10][10], char shipType, int startRow, int startCol, int endCol, int size, char orientation, char direction){
    // need to implement a board check that sees if there is enough space in row to fit ship type. Will make another method for this.
    if (direction == 'L'){
        for (int i=endCol-1; i<startCol-1; i++) ocean[startRow-1][i] = shipType;
    }
    else{
     for (int i=startCol-1; i<endCol-1; i++) ocean[startRow-1][i] = shipType;   
    }
    
}
void editBoardVertical(char ocean[10][10], char shipType, int startRow, int endRow, int startCol, int size, char orientation, char direction){
    // need to implement a board check that sees if there is enough space in row to fit ship type. Will make another method for this.
    if (direction == 'U'){
        for (int i=endRow-1; i<startRow-1; i++) ocean[i][startCol-1] = shipType;
    }
    else{
        for (int i=startRow-1; i<endRow-1; i++) ocean[i][startCol-1] = shipType;  
    }
}

void drawBoard(char ocean[10][10])
{
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
            if (ocean[i][j] !=' '){
                std::cout<<ocean[i][j]<<" | ";
            }
            else{
                std::cout<<"  | ";
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
