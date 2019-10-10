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

int Board::placeTile(char colour, int shape, int xPos, int yPos)
{
   int points = 0;
   //Validate position
   if ((yPos % 2 == 0 || yPos == 0) && (xPos % 2 == 0 || xPos == 0))
   {
      points = validTile(colour, shape, xPos, yPos);
   }
   else if ((yPos % 2 != 0) && (xPos % 2 != 0))
   {
      points = validTile(colour, shape, xPos, yPos);
   }
   if (points > 0)
   {
      tile[yPos][xPos] = new Tile(colour, shape);
	  expandBoard(xPos, yPos);
   }
   return points;
}

//Validates whether the move is valid and returns the score.
int Board::validTile(char colour, int shape, int xPos, int yPos)
{
   int returnPoints = 0;
   int currentPos1 = 1;
   int currentPos2 = 1;
   int currentPos3 = 1;
   int currentPos4 = 1;
   Tile* currentTile1 = nullptr;
   Tile* currentTile2 = nullptr;
   Tile* currentTile3 = nullptr;
   Tile* currentTile4 = nullptr;
   if (tile[yPos][xPos] != nullptr)
   {
      if (yPos != 0)
	  {
         if (xPos != 0)
	     {
            if ((tile[yPos - 1][xPos - 1]->getColour() == colour && tile[yPos - 1][xPos - 1]->getShape() != shape)
			   || (tile[yPos - 1][xPos - 1]->getShape() == shape && tile[yPos - 1][xPos - 1]->getColour() !=colour))
            {
			   currentTile1 = tile[yPos - 1][xPos - 1];
            }
         }
         if (xPos != xSize - 1)
         {
            if ((tile[yPos - 1][xPos + 1]->getColour() == colour && tile[yPos - 1][xPos + 1]->getShape() != shape)
			   || (tile[yPos - 1][xPos + 1]->getShape() == shape && tile[yPos - 1][xPos + 1]->getColour() !=colour))
            {
			   currentTile2 = tile[yPos + 1][xPos - 1];
            }
         }
      }
	  if (yPos != ySize - 1)
	  {
         if (xPos != 0)
	     {
            if ((tile[yPos + 1][xPos - 1]->getColour() == colour && tile[yPos + 1][xPos - 1]->getShape() != shape)
			   || (tile[yPos + 1][xPos - 1]->getShape() == shape && tile[yPos + 1][xPos - 1]->getColour() !=colour))
            {
			   currentTile3 = tile[yPos - 1][xPos + 1];
            }
         }
         if (xPos != xSize - 1)
         {
            if ((tile[yPos + 1][xPos + 1]->getColour() == colour && tile[yPos + 1][xPos + 1]->getShape() != shape)
			   || (tile[yPos + 1][xPos + 1]->getShape() == shape && tile[yPos + 1][xPos + 1]->getColour() !=colour))
            {
			   currentTile4 = tile[yPos + 1][xPos + 1];
            }
         }
      }
      while (currentTile1 != nullptr)
      {
         if ((currentTile1->getColour() == colour && currentTile1->getShape() != shape)
            || (currentTile1->getShape() == shape && currentTile1->getColour() !=colour))
         {
            returnPoints += 1;
			currentPos1 += 1;
			if (xPos - currentPos1 > 0 && yPos - currentPos1 > 0)
			{
			   currentTile1 = tile[yPos - currentPos1][xPos - currentPos1];
            }
			else
			{
			   currentTile1 = nullptr;
            }
         }  
      }
	  while (currentTile2 != nullptr)
      {
         if ((currentTile2->getColour() == colour && currentTile2->getShape() != shape)
            || (currentTile2->getShape() == shape && currentTile2->getColour() !=colour))
         {
            returnPoints += 1;
			currentPos1 += 1;
			if (xPos + currentPos1 > xSize && yPos - currentPos1 > 0)
			{
			   currentTile2 = tile[yPos - currentPos2][xPos + currentPos2];
            }
			else
			{
			   currentTile2 = nullptr;
            }
         }  
      }
	  while (currentTile3 != nullptr)
      {
         if ((currentTile3->getColour() == colour && currentTile3->getShape() != shape)
            || (currentTile3->getShape() == shape && currentTile3->getColour() !=colour))
         {
            returnPoints += 1;
			currentPos3 += 1;
			if (xPos - currentPos3 > 0 && yPos + currentPos3 > ySize)
			{
			   currentTile3 = tile[yPos + currentPos3][xPos - currentPos3];
            }
			else
			{
			   currentTile3 = nullptr;
            }
         }  
      }
	  while (currentTile4 != nullptr)
      {
         if ((currentTile4->getColour() == colour && currentTile4->getShape() != shape)
            || (currentTile4->getShape() == shape && currentTile4->getColour() !=colour))
         {
            returnPoints += 1;
			currentPos4 += 1;
		    if (xPos + currentPos4 < xSize && yPos + currentPos4 > ySize)
		    {
			   currentTile4 = tile[yPos + currentPos4][xPos + currentPos4];
            }
			else
			{
			   currentTile4 = nullptr;
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
	  for (int y = 0; y < ySize; y++)
	  {
		  expTile[y] = new Tile*[xSize + 2];
	  }
	  for(int y = 0; y < ySize; y++)
      {
         for(int x = 0; x < xSize + 1; x++)
         {
            expTile[y][x] = nullptr;
         }
      }
	  for (int x = 0; x < xSize + 2; x++)
      {
         for (int y = 0; y < ySize; y++)
		 {
            if(tile[y][x] != nullptr)
            {
               expTile[y][x + 2] = new Tile(tile[y][x]->getColour(), tile[y][x]->getShape());
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
	  for (int y = 0; y < ySize; y++)
	  {
		  expTile[y] = new Tile*[xSize + 1];
	  }
	  for(int y = 0; y < ySize; y++)
      {
         for(int x = 0; x < xSize + 1; x++)
         {
            expTile[y][x] = nullptr;
         }
      }
	  for (int x = 0; x < xSize + 1; x++)
      {
         for (int y = 0; y < ySize; y++)
		 {
            if(tile[y][x] != nullptr)
            {
               expTile[y][x] = new Tile(tile[y][x]->getColour(), tile[y][x]->getShape());
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
	  for (int y = 0; y < ySize; y++)
	  {
		  expTile[y] = new Tile*[xSize];
	  }
	  for(int y = 0; y < ySize + 1; y++)
      {
         for(int x = 0; x < xSize; x++)
         {
            expTile[y][x] = nullptr;
         }
      }
	  for (int x = 0; x < xSize; x++)
      {
         for (int y = 0; y < ySize + 1; y++)
		 {
            if(tile[y][x] != nullptr)
            {
               expTile[y + 1][x - 1] = new Tile(tile[y][x]->getColour(), tile[y][x]->getShape());
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
	  for (int y = 0; y < ySize; y++)
	  {
		  expTile[y] = new Tile*[xSize];
	  }
	  for(int y = 0; y < ySize + 1; y++)
      {
         for(int x = 0; x < xSize; x++)
         {
            expTile[y][x] = nullptr;
         }
      }
	  for (int x = 0; x < xSize; x++)
      {
         for (int y = 0; y < ySize + 1; y++)
		 {
            if(tile[y][x] != nullptr)
            {
               expTile[y][x] = new Tile(tile[y][x]->getColour(), tile[y][x]->getShape());
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

void Board::forceTile(char colour, int shape, int xPos, int yPos)
{
   tile[yPos][xPos] = new Tile(colour, shape);
}

Tile*** Board::getBoard()
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
      std::string row;
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