#include <iostream>
#include "Boards.h"
#include "UserInteraction.h"
#include <limits>

Board::Board() {
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            grid[r][c] = ' ';
}

void Board::moveShip(char ocean[10][10], char shipType, int uSize){
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

            ::drawBoard(ocean);
}

void Board::editBoardHorizontal(char ocean[10][10], char shipType, int startRow, int startCol, int endCol, int size, char orientation, char direction){
    int count=0;

    if (direction == 'L'){
        for (int i=endCol-1; i<startCol-1; i++){
            if (ocean[startRow-1][i] == ' '){
                ocean[startRow-1][i] = shipType;
            }
            else{
                count++;
            }
        } 
    }
    else{
        for (int i=startCol-1; i<endCol-1; i++){
            if (ocean[startRow-1][i]==' '){
                ocean[startRow-1][i] = shipType;
            }
            else{
                count++;
            }
        }

    }
    if (count>0){
        clear(ocean, shipType);
        std::cout<<'\n'<<"This space is occupied. Please choose another."<<'\n';
    }   
}

void Board::editBoardVertical(char ocean[10][10], char shipType, int startRow, int endRow, int startCol, int size, char orientation, char direction){
    int count;
    if (direction == 'U'){
        for (int i=endRow-1; i<startRow-1; i++){
            if (ocean[i][startCol-1]==' '){
                ocean[i][startCol-1] = shipType;
            }
            else{
                count++;
            }
        }
    }
    else{
        for (int i=startRow-1; i<endRow-1; i++){
            if (ocean[i][startCol-1]==' '){
                ocean[i][startCol-1] = shipType;
            }
            else{
                count++;
            }
             
        }   
    }
    if (count>0){
        clear(ocean, shipType);
        std::cout<<'\n'<<"This space is occupied. Please choose another."<<'\n';
    }
}

bool Board::isOnBoard(char ocean[10][10], char ship){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (ocean[i][j]==ship) return true;
        }
    }
    return false;
}

void Board::clear(char ocean[10][10], char ship){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (ocean[i][j]==ship) ocean[i][j]=' ';
        }
    }
    ::drawBoard(ocean);
}