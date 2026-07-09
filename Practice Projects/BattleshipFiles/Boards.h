#pragma once

struct Board {
    char grid[10][10];
    Board();

    Board createBoard();
    void editBoardHorizontal(char ocean[10][10], char shipType, int startRow, int startCol, int endCol, int size, char orientation, char direction);
    void editBoardVertical(char ocean[10][10], char shipType, int startRow, int endRow, int startCol, int size, char orientation, char direction);
    void moveShip(char ocean[10][10], char shipType, int size);
    bool isOnBoard(char ocean[10][10], char ship);
    void clear(char ocean[10][10], char shipType);
};