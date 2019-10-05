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
void gameEngine::saveGame(std::string saveGameName, Player *player1, Player *player2,
                          bool playerOneTurn, LinkedList *bag, Board *board)
{
    saveGameName = saveGameName + ".txt";
    std::ofstream outfile(saveGameName);

    outfile << player1->getName() << "\n";
    outfile << player1->getScore() << "\n";
    outfile << player1->displayHand() << "\n";
    outfile << player2->getName() << "\n";
    outfile << player1->getScore() << "\n";
    outfile << player2->displayHand() << "\n";
    outfile << board->displayFullBoard() << "\n";
    outfile << bag->displayItems() << "\n";
    if (playerOneTurn)
    {
        outfile << player1->getName() << "\n";
    }
    else
    {
        outfile << player2->getName() << "\n";
    }
    outfile.close();
}

// places tile on board and removes from players hand
void gameEngine::placeTile(std::string tile, std::string pos, LinkedList *bag,
                           Board *board, Player *player)
{

    player->hand->removeTile(tile);
    //remove front should return a string to be added to a hand
    if (bag->size() > 0)
    {
        player->hand->addBack(bag->removeFront());
    }
    // board place should return an int
    player->setPoints() = player->getScore() + board->place(tile, pos);
}

// replaces tile in players hand
void gameEngine::replaceTile(std::string tile, LinkedList *bag,
                             Player *player) 
    {
        player->hand->removeTile(tile);
        player->hand->addBack(bag->removeFront());
        bag->addBack(tile);
    }