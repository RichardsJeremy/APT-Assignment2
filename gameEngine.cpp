/* Game engine class. This class will contain all methods interacting with the board
and players (and hands) which will all be called from the controller class. 
*/
#include "gameEngine.h"

gameEngine::gameEngine(/* args */)
{
}

gameEngine::~gameEngine()
{
}

//This method ouputs all relevant data for a game to be laoded
void gameEngine::saveGame(std::string saveGameName) {}

// places tile on board and removes from players hand
void gameEngine::placeTile(std::string tile, std::string pos) {}

// replaces tile in players hand
void gameEngine::replaceTile(std::string tile) {}