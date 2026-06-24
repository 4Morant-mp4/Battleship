#include <iostream>
#include <limits>

// 6/24/26 - The loop is now fixed. Players can put ships infinitely if they choose or continue the game.
// Fixed some small placement issues and a previous misspelling
// Also if the player tries to move a ship already on the board, the code will stop them
// Code will also stop the player if they have moved all their ships. The method used is a bit annoying for the player but it's a good start
// Next i need to design the isValidSpace() method to ensure no overlapping ships
// After that, we can begin coding a simple AI that randomly places ships.

void instructions();
void drawBoard(char ocean[10][10]);
void editBoardHorizontal(char ocean[10][10], char shipType, int startRow, int startCol, int endCol, int size, char orientation, char direction);
void editBoardVertical(char ocean[10][10], char shipType, int startRow, int endRow, int startCol, int size, char orientation, char direction);
void moveShip(char ocean[10][10], char shipType, int size);
bool isOnBoard(char ocean[10][10], char ship);
void clear(char ocean[10][10], char shipType);

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
    char shipType, rowInp, orientation, direction, clearShip, proceed;
    int startRow, endRow, startCol, endCol, uSize;
    
    do{
        do{
            std::cout<<"Which ship would you like to move?"<<"\n";
            std::cout<<"Please type \"A\", for Airship, \"B\" for Battleship, \"C\" for Cruiser, \"D\" for Destroyer, or \"S\" for Submarine"<<'\n';
            std::cout<<"When You are finished moving your ships, please type \"F\""<<'\n';
            std::cout<<"If you would like to clear a ship, please type \"X\""<<'\n';
            std::cin>>shipType;
            shipType = (char)toupper(shipType);
            
            if (isOnBoard(userOcean.grid, shipType)){
                do{
                    std::cout<<"This ship is already on the board."<<'\n'<<"Would you like to clear the ship? (Y or N)\n";
                    std::cin>>clearShip;
                    clearShip = (char)toupper(clearShip);
                }while(clearShip != 'Y' && clearShip != 'N');
                
                if (clearShip == 'Y') clear(userOcean.grid, shipType);
                else break;
                
            }
            if (shipType=='A')
            {
                std::cout<<"You have chosen: The Aircraft Carrier"<<'\n';
                uSize = 5;
                moveShip(userOcean.grid, shipType, uSize);
            }
            else if(shipType=='B')
            {
                std::cout<<"You have chosen: The Battleship"<<'\n';
                uSize = 4;
                moveShip(userOcean.grid, shipType, uSize);
            }
            else if(shipType=='C')
            {
                std::cout<<"You have chosen: The Cruiser"<<'\n';
                uSize = 3;
                moveShip(userOcean.grid, shipType, uSize);
            }
            else if(shipType=='D')
            {
                std::cout<<"You have chosen: The Destroyer"<<'\n';
                uSize = 3;
                moveShip(userOcean.grid, shipType, uSize);
            }
            else if (shipType =='S')
            {
                std::cout<<"You have chosen: The Submarine"<<'\n';
                uSize = 2;
                moveShip(userOcean.grid, shipType, uSize);
            }
            else if (shipType == 'X')
            {
                do{
                std::cout<<"Which ship would you like to clear?"<<'\n';
                std::cout<<"Please type \"A\", for Airship, \"B\" for Battleship, \"C\" for Cruiser, \"D\" for Destroyer, or \"S\" for Submarine"<<'\n';
                std::cin>>clearShip;
                clearShip = (char)toupper(clearShip);
                clear(userOcean.grid, clearShip);
                }while(clearShip!='A' && clearShip!='B' && clearShip!='C' && clearShip!='D' && clearShip!='S');
            }
            else if (shipType == 'F')
            {
                break;
            }
            else
            {
                std::cout<<"That is not a valid input :/"<<'\n';
            }

        } while (shipType!='A' && shipType!='B' && shipType!='C' && shipType!='D' && shipType!='S');
        
        if (isOnBoard(userOcean.grid, 'A') && isOnBoard(userOcean.grid, 'B') && isOnBoard(userOcean.grid, 'C') && isOnBoard(userOcean.grid, 'D') && isOnBoard(userOcean.grid, 'S')){
            std::cout<<"You have placed all your ships!"<<'\n';
            do{
                std::cout<<"Would you like to proceed with the game or continue moving your ships? (\"P\" for proceed, \"C\" for continue)";
                std::cin>>proceed;
                proceed=(char)toupper(proceed);
            }while(proceed!='P' && proceed!='C');

            if (proceed=='P') shipType = 'F';
            else shipType = ' ';
        }
        else shipType = ' ';
    }while (shipType != 'F');
    
    return 0;
}


void moveShip(char ocean[10][10], char shipType, int uSize){
    char rowInp, orientation, direction;
    int startRow, endRow, startCol, endCol;
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

                    if (std::cin.fail()) {
                    std::cin.clear(); // reset fail state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
                    std::cout << "Invalid input. Please enter a number between 1 and 10.\n";
                    startCol = -1; // force loop to continue
                    }
                } while (startCol <1 || startCol > 10);
                

                std::cout<<"You picked column: "<<startCol<<std::endl;
                if ((uSize + startCol <= 11)&&(startCol - uSize >= 0)){
                    do{
                    std::cout<<"which direction would you like to the ship to lay in? Left (L) or Right (R)?: ";
                    std::cin>>direction;
                    direction = (char)toupper(direction);
                    }while (direction != 'L' && direction !='R');

                    if (direction == 'L')
                    {
                        startCol++;
                        endCol = startCol-uSize;
                    }
                    else
                    {
                        endCol = startCol+uSize;
                    }
                }
                else if (startCol + uSize > 11){
                    direction = 'L';
                    endCol = startCol - uSize;
                    startCol++;
                }
                else if (startCol - uSize < 0){
                    direction = 'R';
                    endCol = startCol + uSize;
                }
                
                editBoardHorizontal(ocean, shipType, startRow, startCol, endCol, uSize, orientation, direction);
            }

            if (orientation == 'V'){

                do{
                    std::cout<<"Which column would you like the ship to be in (from 1-10)?: ";
                    std::cin>>startCol;

                    if (std::cin.fail()) {
                        std::cin.clear(); // reset fail state
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
                        startCol = -1; // force loop to continue
                    }
                }while ((startCol < 1) || (startCol > 10));

                std::cout<<"You picked column: ";
                std::cout<<startCol<<std::endl;

                do{
                std::cout<<"Which row would you like the back of the ship to be in (from A-J)?: ";
                std::cin>>rowInp;
                rowInp = toupper(rowInp);
                startRow = rowInp - 63;
                }while ((startRow < 2) || (startRow > 11));

                std::cout<<"You picked row: "<<startRow<<std::endl;
                
                if((uSize + startRow <= 12)&&(startRow - uSize >= 0)){
                    do{
                    std::cout<<"which direction would you like the ship to lay in? Up (U) or Down (D)?: ";
                    std::cin>>direction;
                    direction = (char)toupper(direction);
                    }while (direction != 'U' && direction !='D');

                    if (direction == 'U')
                    {
                        endRow = startRow-uSize;
                    }
                    else
                    {
                        startRow--;
                        endRow = startRow+uSize;
                    }
                }
                else if (startRow + uSize > 11){
                    direction = 'U';
                    endRow = startRow - uSize;
                }
                else if (startRow - uSize < 0){
                    direction = 'D';
                    endRow = startRow + uSize;
                }
                
                
                editBoardVertical(ocean, shipType, startRow, endRow, startCol, uSize, orientation, direction);
            }

            drawBoard(ocean);
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

bool isOnBoard(char ocean[10][10], char ship){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (ocean[i][j]==ship) return true;
        }
    }
    return false;
}

void clear(char ocean[10][10], char ship){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (ocean[i][j]==ship) ocean[i][j]=' ';
        }
    }
    drawBoard(ocean);
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
