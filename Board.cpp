#include "Board.h"

Board::Board(int xSize, int ySize)
{
   this->xSize = xSize;
   this->ySize = ySize;
   tile = new Tile**[ySize];
   for(int y = 0; y < ySize; y++)
   {
      tile[y] = new Tile*[xSize];
   }
   for(int y = 0; y < ySize; y++)
   {
      for(int x = 0; x < xSize; x++)
      {
         tile[y][x] = nullptr;
      }
   }

}

//Desctructor
Board::~Board()
{
   for(int y = 0; y < ySize; y++)
   {
      for(int x = 0; x < xSize; x++)
      {
         delete tile[y][x];
      }
      delete[] tile[y];
   }
   delete[] tile;
   tile = nullptr;
}

int Board::getXSize()
{
   return xSize;
}

int Board::getYSize()
{
   return ySize;
}

int Board::placeTile(char color, int shape, int xPos, int yPos)
{
   int points = 0;
   //Validate position
   if ((yPos % 2 == 0 || yPos == 0) && (xPos % 2 == 0 || xPos == 0))
   {
      points = validTile(color, shape, xPos, yPos);
   }
   else if ((yPos % 2 != 0) && (xPos % 2 != 0))
   {
      points = validTile(color, shape, xPos, yPos);
   }
   if (points > 0)
   {
      tile[yPos][xPos] = new Tile(color, shape);
	  expandBoard();
   }
   return points;
}

//Validates whether the move is valid and returns the score.
int Board::validTile(char color, int shape, int xPos, int yPos)
{
   int returnPoints = 0;
   int currentPos = 1;
   Tile currentTile1 = nullptr;
   Tile currentTile2 = nullptr;
   Tile currentTile3 = nullptr;
   Tile currentTile4 = nullptr;
   if (tile[xPos][Ypos] != nullptr)
   {
      if (yPos != 0)
	  {
         if (xPos != 0)
	     {
            if ((tile[yPos - 1][xPos - 1].getColor() == color && tile[yPos - 1][xPos - 1].getShape() != shape)
			   || (tile[yPos - 1][xPos - 1].getShape() == shape && tile[yPos - 1][xPos - 1].getColor() != color))
            {
			   currentTile1 = tile*[yPos - 1][xPos - 1];
            }
         }
         if (xPos != getXSize)
         {
            if ((tile[yPos - 1][xPos + 1].getColor() == color && tile[yPos - 1][xPos + 1].getShape() != shape)
			   || (tile[yPos - 1][xPos + 1].getShape() == shape && tile[yPos - 1][xPos + 1].getColor() != color))
            {
			   currentTile2 = tile*[yPos + 1][xPos - 1];
            }
         }
      }
	  if (yPos != getYSize)
	  {
         if (xPos != 0)
	     {
            if ((tile[yPos + 1][xPos - 1].getColor() == color && tile[yPos + 1][xPos - 1].getShape() != shape)
			   || (tile[yPos + 1][xPos - 1].getShape() == shape && tile[yPos + 1][xPos - 1].getColor() != color))
            {
			   currentTile3 = tile*[yPos - 1][xPos + 1];
            }
         }
         if (xPos != getXSize)
         {
            if ((tile[yPos + 1][xPos + 1].getColor() == color && tile[yPos + 1][xPos + 1].getShape() != shape)
			   || (tile[yPos + 1][xPos + 1].getShape() == shape && tile[yPos + 1][xPos + 1].getColor() != color))
            {
			   currentTile4 = tile*[yPos + 1][xPos + 1];
            }
         }
      }
	  currentPos = 0;
      while (currentTile2 != nullptr)
      {
         if ((currentTile.getColor == color && currentTile.getShape != shape)
            || (currentTile.getShape == shape && currentTile.getColor != color))
         {
            returnPoints += 1;
			currentPos += 1;
			if (xPos - currentPos > 0 && yPos - currentPos > 0)
			{
			   currentTile1 = tile*[yPos - currentPos][xPos - currentPos];
            }
			else
			{
			   currentTile1 = nullptr;
            }
         }  
      }
	  currentPos = 0;
	  while (currentTile2 != nullptr)
      {
         if ((currentTile.getColor == color && currentTile.getShape != shape)
            || (currentTile.getShape == shape && currentTile.getColor != color))
         {
            returnPoints += 1;
			currentPos += 1;
			if (direction == 2 && (xPos + currentPos > getXSize && yPos - currentPos > 0)
			{
			   currentTile = tile*[yPos - currentPos][xPos + currentPos];
            }
			else
			{
			   currentTile = nullptr;
            }
         }  
      }
	  currentPos = 0;
	  while (currentTile3 != nullptr)
      {
         if ((currentTile.getColor == color && currentTile.getShape != shape)
            || (currentTile.getShape == shape && currentTile.getColor != color))
         {
            returnPoints += 1;
			currentPos += 1;
			if (direction == 3 && (xPos - currentPos > 0 && yPos + currentPos > getYSize)
			{
			   currentTile = tile*[yPos + currentPos][xPos - currentPos];
            }
			else
			{
			   currentTile = nullptr;
            }
         }  
      }
	  currentPos = 0;
	  while (currentTile4 != nullptr)
      {
         if ((currentTile.getColor == color && currentTile.getShape != shape)
            || (currentTile.getShape == shape && currentTile.getColor != color))
         {
            returnPoints += 1;
			currentPos += 1;
		    if (direction == 4 && (xPos + currentPos < getXSize && yPos + currentPos > getYSize)
		    {
			   currentTile = tile*[yPos + currentPos][xPos + currentPos];
            }
			else
			{
			   currentTile = nullptr;
            }
         }  
      }
	  if (returnPoints == QWIRKLE_POINTS)
	  {
         returnPoints += QWIRKLE_POINTS;
      }	
   }
   return returnPoints;
}

void Board::expandBoard(int xPos, int yPos)
{
   if (xPos == 0)
   {
      Tile*** expTile = new Tile**[ySize];
	  expTile[y] = new Tile*[xSize + 1];
	  for(int y = 0; y < expTile.getYSize; y++)
      {
         for(int x = 0; x < expTile.getXSize; x++)
         {
            expTile[y][x] = nullptr;
         }
      }
	  for (int x = 0; x < expTile.getXSize; x++)
      {
         for (int y = 0; y < expTile.getYSize; y++)
		 {
            if(tile[y][x] != nullptr)
            {
               expTile[y][x + 2] = new Tile(tile[y][x]->getColor, tile[y][x[]->getShape());
            }
         }
      }
	  for(int y = 0; y < ySize; y++)
      {
         for(int x = 0; x < xSize; x++)
		 {
            delete tile[y][x];
         }
			delete[] tile[y];
		 }
      delete[] tile;
	  tile = nullptr;
	  tile = expTile;
      *tile = *expTile;
	  **tile = **expTile;
	  ***tile = ***expTile;
	  xSize++;
   }
   if (xPos == xSize - 1)
   {
      Tile*** expTile = new Tile**[ySize];
	  expTile[y] = new Tile*[xSize + 1];
	  for(int y = 0; y < expTile.getYSize; y++)
      {
         for(int x = 0; x < expTile.getXSize; x++)
         {
            expTile[y][x] = nullptr;
         }
      }
	  for (int x = 0; x < expTile.getXSize; x++)
      {
         for (int y = 0; y < expTile.getYSize; y++)
		 {
            if(tile[y][x] != nullptr)
            {
               expTile[y][x] = new Tile(tile[y][x]->getColor, tile[y][x[]->getShape());
            }
         }
      }
	  for(int y = 0; y < ySize; y++)
      {
         for(int x = 0; x < xSize; x++)
		 {
            delete tile[y][x];
         }
			delete[] tile[y];
		 }
      delete[] tile;
	  tile = nullptr;
	  tile = expTile;
      *tile = *expTile;
	  **tile = **expTile;
	  ***tile = ***expTile;
	  xSize++;
   }
      if (yPos == 0)
   {
      Tile*** expTile = new Tile**[ySize + 1];
	  expTile[y] = new Tile*[xSize];
	  for(int y = 0; y < expTile.getYSize; y++)
      {
         for(int x = 0; x < expTile.getXSize; x++)
         {
            expTile[y][x] = nullptr;
         }
      }
	  for (int x = 0; x < expTile.getXSize; x++)
      {
         for (int y = 0; y < expTile.getYSize; y++)
		 {
            if(tile[y][x] != nullptr)
            {
               expTile[y + 1][x - 1] = new Tile(tile[y][x]->getColor, tile[y][x[]->getShape());
            }
         }
      }
	  for(int y = 0; y < ySize; y++)
      {
         for(int x = 0; x < xSize; x++)
		 {
            delete tile[y][x];
         }
			delete[] tile[y];
		 }
      delete[] tile;
	  tile = nullptr;
	  tile = expTile;
      *tile = *expTile;
	  **tile = **expTile;
	  ***tile = ***expTile;
	  ySize++;
   }
   if (yPos == ySize - 1)
   {
      Tile*** expTile = new Tile**[ySize + 1];
	  expTile[y] = new Tile*[xSize];
	  for(int y = 0; y < expTile.getYSize; y++)
      {
         for(int x = 0; x < expTile.getXSize; x++)
         {
            expTile[y][x] = nullptr;
         }
      }
	  for (int x = 0; x < expTile.getXSize; x++)
      {
         for (int y = 0; y < expTile.getYSize; y++)
		 {
            if(tile[y][x] != nullptr)
            {
               expTile[y][x] = new Tile(tile[y][x]->getColor, tile[y][x[]->getShape());
            }
         }
      }
	  for(int y = 0; y < ySize; y++)
      {
         for(int x = 0; x < xSize; x++)
		 {
            delete tile[y][x];
         }
			delete[] tile[y];
		 }
      delete[] tile;
	  tile = nullptr;
	  tile = expTile;
      *tile = *expTile;
	  **tile = **expTile;
	  ***tile = ***expTile;
	  ySize++;
   }
   
}

void Board::forceTile(char color, int shape, int xPos, int yPos)
{
   tile[yPos][xPos] = new Tile(color, shape);
}

Tile** Board::getBoard()
{
	return tile;
}

std::string Board::toString()
{
   std::string boardString = "";
   boardString.append(" ");
   for(int x = 0; x < xSize; x += 2)
   {
      boardString.append("    " + x);
   }
   boardString.append("\n   -");
   for(int x = 0; x < xSize; x += 2)
   {
      boardString.append("-----");
   }
   boardString.append("\n");
   for(int y = 0; y < ySize; y++)
   {
      char rowLetter = 65 + y;
      string row;
      row = rowLetter;
      
      if (y % 2 == 0)
	  {
         boardString.append(row + " |");
         for(int x = 0; x < xSize; x++)
         {
            boardString.append(" ");
            if(tile[y][x] == nullptr)
            {
               boardString.append("   |");
            }
            else
            {
            boardString.append(tile[y][x]->toString() + " |");
            }
         }
      }
      boardString.append("\n");
   }
   boardString.append("   -");
   for(int x = 0; x < xSize; x += 2)
   {
      boardString.append("-----");
   }
   boardString.append("\n    ");
   for(int x = 1; x < xSize; x += 2)
   {
      boardString.append("    " + x);
   }
   boardString.append("\n");
   return boardString;
}