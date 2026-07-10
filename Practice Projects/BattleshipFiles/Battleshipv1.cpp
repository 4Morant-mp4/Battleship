#include <iostream>
#include "UserInteraction.h"
#include "Boards.h"
#include <limits>

// 7/10/26 -- Everything works great and has been separated and organized neatly!
// Also fixed index numbers so the code processes indexes from 0-9 (just to make it a bit easier to read)
// Minor issue with the "You pick column: " producing one less than the actual chosen column. Just an aesthetic bug. fix later
// We can finally begin working on the random AI
// Post game implementation I would like to figure out how to implement save files to continue the game later.

int main()
{
    instructions();
    Board userOcean;
    drawBoard(userOcean.grid);
    char shipType, rowInp, orientation, direction, clearShip, proceed;
    int startRow, endRow, startCol, endCol, uSize;
    
    do{
        do{
            std::cout<<'\n'<<"Which ship would you like to move?"<<"\n";
            std::cout<<"Please type \"A\", for Airship (5), \"B\" for Battleship (4), \"C\" for Cruiser (3), \"S\" for Submarine (3), or \"D\" for Destroyer (2)"<<'\n';
            std::cout<<"When You are finished moving your ships, please type \"F\""<<'\n';
            std::cout<<"If you would like to clear a ship, please type \"X\""<<'\n';
            std::cin>>shipType;
            shipType = (char)toupper(shipType);
            
            if (userOcean.isOnBoard(userOcean.grid, shipType)){
                do{
                    std::cout<<"This ship is already on the board."<<'\n'<<"Would you like to clear the ship? (Y or N)\n";
                    std::cin>>clearShip;
                    clearShip = (char)toupper(clearShip);
                }while(clearShip != 'Y' && clearShip != 'N');
                
                if (clearShip == 'Y') userOcean.clear(userOcean.grid, shipType);
                else break;
                
            }
            if (shipType=='A')
            {
                std::cout<<"You have chosen: The Aircraft Carrier"<<'\n';
                uSize = 5;
                userOcean.moveShip(userOcean.grid, shipType, uSize);
            }
            else if(shipType=='B')
            {
                std::cout<<"You have chosen: The Battleship"<<'\n';
                uSize = 4;
                userOcean.moveShip(userOcean.grid, shipType, uSize);
            }
            else if(shipType=='C')
            {
                std::cout<<"You have chosen: The Cruiser"<<'\n';
                uSize = 3;
                userOcean.moveShip(userOcean.grid, shipType, uSize);
            }
            else if(shipType=='D')
            {
                std::cout<<"You have chosen: The Destroyer"<<'\n';
                uSize = 2;
                userOcean.moveShip(userOcean.grid, shipType, uSize);
            }
            else if (shipType =='S')
            {
                std::cout<<"You have chosen: The Submarine"<<'\n';
                uSize = 3;
                userOcean.moveShip(userOcean.grid, shipType, uSize);
            }
            else if (shipType == 'X')
            {
                do{
                std::cout<<"Which ship would you like to clear?"<<'\n';
                std::cout<<"Please type \"A\", for Airship, \"B\" for Battleship, \"C\" for Cruiser, \"D\" for Destroyer, or \"S\" for Submarine"<<'\n';
                std::cin>>clearShip;
                clearShip = (char)toupper(clearShip);
                userOcean.clear(userOcean.grid, clearShip);
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
        
        if (userOcean.isOnBoard(userOcean.grid, 'A') && userOcean.isOnBoard(userOcean.grid, 'B') && userOcean.isOnBoard(userOcean.grid, 'C') && userOcean.isOnBoard(userOcean.grid, 'D') && userOcean.isOnBoard(userOcean.grid, 'S')){
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
