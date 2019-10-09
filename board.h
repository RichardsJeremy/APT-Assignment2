#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include <iostream>
#include <string>

#define MAX_X  26
#define MAX_Y  26
#define QWIRKLE_POINTS 6


class Board {
public:
   Board(int xSize, int ySize);
   ~Board();
   int getXSize();
   int getYSize();
   int placeTile(char colour, int shape, int xPos, int yPos);
   int validTile(char colour, int shape, int xPos, int yPos);
   void expandBoard(int xPos, int yPos);
   void forceTile(char colour, int shape, int xPos, int yPos);
   Tile*** getBoard();
   std::string toString();

private:
   Tile*** tile;
   int  xSize;
   int  ySize;
};

#endif //BOARD_H