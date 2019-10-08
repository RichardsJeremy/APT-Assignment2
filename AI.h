#pragma once
#include <string>
#include <vector>
#include "Tile.h"
#include "LinkedList.h"
#define openTile	nullptr
#define NW	0
#define NE	1
#define SE	2
#define SW	3
//Cardinal directions

class AI
{
public:
	AI();
	std::string getMove(Tile** board, LinkedList hand, int rows, int cols);
	std::string getHint(Tile** board, LinkedList hand, int rows, int cols, Tile* tile);
private:
	std::vector<std::string> getPotentialMoves(Tile** board, LinkedList hand, int rows, int cols);
	std::pair<int,int> getAdjacentSpace(Tile** board, int direction, std::pair<int, int> space);
	Tile * getTile(Tile** board, std::pair<int, int> space);
	int getOppositeDirection(int direction);
	std::string getPlaceCommand(Tile* tile, std::pair<int, int> space);
	bool isFilled(Tile * tile);
};

