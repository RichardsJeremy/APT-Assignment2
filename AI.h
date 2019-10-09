#pragma once
#include <string>
#include <vector>
#include "Tile.h"
#include "LinkedList.h"
#include "Board.h"
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
	std::string getMove(Board board, LinkedList hand);
	std::string getMoveOptimal(Board board, LinkedList hand);
	std::string getHint(Board board, LinkedList hand, Tile* tile);
private:
	std::vector<std::string> getPotentialMoves(Board boardObj, LinkedList hand);
	std::pair<int,int> getAdjacentSpace(Tile*** board, int direction, std::pair<int, int> space);
	Tile * getTile(Tile*** board, std::pair<int, int> space);
	int getOppositeDirection(int direction);
	std::string getPlaceCommand(Tile* tile, std::pair<int, int> space);
	bool isFilled(Tile * tile);
};

