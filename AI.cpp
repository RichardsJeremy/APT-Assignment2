#include "AI.h"

std::string AI::getMove(std::shared_ptr<Board> board, LinkedList hand)// look at hand
{
	std::vector<std::string> potentialMoves = getPotentialMoves(board, hand);
	if (!potentialMoves.empty)
	{
		int pos = rand % (potentialMoves.size - 1);
		return potentialMoves.at(pos);
	}
	int pos = rand() % 5;
	std::string replace = "replace ";
	replace += hand.getTile(pos)->toString();
	return replace;
}

std::string AI::getMoveOptimal(std::shared_ptr<Board> board, LinkedList hand)
{
	std::vector<std::string> potentialMoves = getPotentialMoves(board, hand);
	if (!potentialMoves.empty)
	{
		std::string bestMove = potentialMoves.at(0);
		int bestMovePoints = 0;
		for (auto i = potentialMoves.begin(); i != potentialMoves.end(); ++i)
		{
			std::string potentialMove = *i;
			int getPoints = 0;
			if(getPoints > bestMovePoints)
				bestMove = potentialMove;
		}
		return bestMove;
	}
	int pos = rand() % 5;
	std::string replace = "replace ";
	replace += hand.getTile(pos)->toString();
	return replace;
}

std::vector<std::string> AI::getPotentialMoves(std::shared_ptr<Board> boardObj, LinkedList hand)
{
	std::vector<std::string> potentialMoves;
	//array for storing potential moves

	int rows = boardObj->getYSize();
	int cols = boardObj->getXSize();
	Tile*** board = boardObj->getBoard;


	for (int row = 0; row < rows; ++row)
	{
		int startCol = 1;
		if (row % 2 == 0)
			startCol = 0;
		for (int col = startCol; col < cols; ++col)
			if (isFilled(board[row][col]))
				//Loops over board to find a space filled with a piece.
			{
				std::pair<int, int> filledSpace(row, col);
				for (int directionFromFilled = NW; directionFromFilled <= SW; ++directionFromFilled)
				{
					std::pair<int, int> emptySpace = getAdjacentSpace(board, directionFromFilled, filledSpace);
					if (!isFilled(getTile(board, emptySpace)))
						//Loops over potential empty spaces adjacent to the filled space.
						for (int i = 0; i < hand.getSize(); ++i)
						{
							Tile* pieceInHand = hand.getTile(i); //Change to pointer
							if (pieceInHand->related(board[row][col]))
								//Loops through hand to find a related tile
							{
								//if placeable
								potentialMoves.push_back(getPlaceCommand(pieceInHand, emptySpace));
							}
						}
				}
			}
	}
	return potentialMoves;
}

std::string AI::getHint(std::shared_ptr<Board> board, LinkedList hand, Tile* tile)
{
	std::string tileStr = "Place " + tile->getColour() + tile->getShape();
	std::vector<std::string> potentialMoves = getPotentialMoves(board, hand);
	for (auto i = potentialMoves.begin(); i != potentialMoves.end(); ++i) 
	{
		std::string potentialMove = *i;
		if (potentialMove.find(tileStr) != std::string::npos) 
		{
			int points = 0; //point algorithm call
			potentialMove += " for ";
			potentialMove += std::to_string(points);
			potentialMove += " points";
			return potentialMove;
		}
	}
	return "no valid move for tile" + tile->getColour() + tile->getShape();
}

std::pair<int, int> AI::getAdjacentSpace(Tile*** board, int direction, std::pair<int, int> space)
{
	if (direction == NW) 
	{
		std::get<0>(space) -= 1;
		std::get<1>(space) -= 1;
	}
	if (direction == NE)
	{
		std::get<0>(space) -= 1;
		std::get<1>(space) += 1;
	}
	if (direction == SE)
	{
		std::get<0>(space) += 1;
		std::get<1>(space) += 1;
	}
	if (direction == SW)
	{
		std::get<0>(space) += 1;
		std::get<1>(space) -= 1;
	}
	return space;
}

Tile * AI::getTile(Tile*** board, std::pair<int, int> space)
{
	return board[std::get<0>(space)][std::get<1>(space)];
}

int AI::getOppositeDirection(int direction) 
{
	if (direction == NW)
		return SE;
	if (direction == NE)
		return SW;
	if (direction == SE)
		return NW;
	return NE;
}

std::string AI::getPlaceCommand(Tile* tile, std::pair<int, int> space) 
{
	std::string command = "place " + tile->getColour() + tile->getShape();
	command += " at ";
	command += std::to_string(std::get<0>(space));
	command	+= std::to_string(std::get<0>(space));
	return command;
}

bool AI::isFilled(Tile * tile) 
{
	if (tile->equals(openTile))
		return false;
	return true;
}


/*
bool adjacentSpacesRelated = true;
for (int directionFromEmpty = NW; directionFromEmpty <= SW; ++directionFromEmpty)
{
	std::pair<int, int> spaceToCheck = getAdjacentSpace(board, directionFromEmpty, emptySpace);
	Tile* toCheck = getTile(board, spaceToCheck);
	if (!pieceInHand->related(toCheck))
		adjacentSpacesRelated = false;
}
if (adjacentSpacesRelated)
{
	bool validMove = true;
	//int potentialPoints = 0;
	for (int directionFromEmpty = NW; directionFromEmpty <= SW; ++directionFromEmpty)
	{
		std::pair<int, int> spaceToCheck = getAdjacentSpace(board, directionFromEmpty, emptySpace);
		Tile* toCheck = getTile(board, spaceToCheck);
		//int adjacentPoints = 0;
		while (&toCheck && validMove)
		{
			if (toCheck->equals(pieceInHand))
				validMove = false;
			spaceToCheck = getAdjacentSpace(board, directionFromEmpty, spaceToCheck);
			toCheck = getTile(board, spaceToCheck);
			//adjacentPoints++;
			//if(adjacentPoints == 5)

		}
	}
	if (validMove)
	{
*/