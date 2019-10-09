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
	static std::string getMove(std::shared_ptr<Board> board, LinkedList hand);
	static std::string getMoveOptimal(std::shared_ptr<Board> board, LinkedList hand);
	static std::string getHint(std::shared_ptr<Board> board, LinkedList hand, Tile* tile);
private:
	static std::vector<std::string> getPotentialMoves(std::shared_ptr<Board> boardObj, LinkedList hand);
	static std::pair<int,int> getAdjacentSpace(Tile*** board, int direction, std::pair<int, int> space);
	static Tile * getTile(Tile*** board, std::pair<int, int> space);
	static int getOppositeDirection(int direction);
	static std::string getPlaceCommand(Tile* tile, std::pair<int, int> space);
	static bool isFilled(Tile * tile);
};

