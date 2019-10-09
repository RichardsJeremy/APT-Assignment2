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
void gameEngine::saveGame(std::string saveGameName, std::shared_ptr<Player> player1, std::shared_ptr<Player> player2,
                          bool playerOneTurn, std::shared_ptr<LinkedList> bag, std::shared_ptr<Board> board)
{
    saveGameName = saveGameName + ".txt";
    std::ofstream outfile(saveGameName);

    outfile << player1->getName() << "\n";
    outfile << player1->getScore() << "\n";
    outfile << player1->hand->toString() << "\n";
    outfile << player2->getName() << "\n";
    outfile << player1->getScore() << "\n";
    outfile << player2->hand->toString() << "\n";
    outfile << board->toString() << "\n";
    outfile << bag->toString() << "\n";
    if (playerOneTurn)
    {
        outfile << player1->getName() << "\n";
    }
    else
    {
        outfile << player2->getName() << "\n";
    }
    outfile.close();
    std::cout << "Game successfully saved\n";
}

// places tile on board and removes from players hand
bool gameEngine::placeTile(std::string tile, std::string pos, std::shared_ptr<LinkedList> bag,
                           std::shared_ptr<Board> board, std::shared_ptr<Player> player)
{
    bool validMove = false;
    char colour = tile[0];
    int shape = tile[1];
    int tilePos = player->hand->getTilePos(shape, colour);
    player->hand->deleteTile(tilePos);
    //remove front should return a string to be added to a hand
    if (bag->getSize() > 0)
    {
        int pickTile = rand() % (bag->getSize() + 1);
        Tile tile = bag->getTile(pickTile);
        player->hand->addTileToBack(&tile);
        bag->deleteTile(pickTile);
    }

    // place tile and get points to add to score.
    int res = board->placeTile(tile[0], tile[1], pos[0], pos[1]);
    player->addScore(res);

    if (res > 0)
    {
        validMove = true;
    }
}

// replaces tile in players hand
void gameEngine::replaceTile(std::string tile, std::shared_ptr<LinkedList> bag,
                             std::shared_ptr<Player> player)
{
    char colour = tile[0];
    int shape = tile[1];
    int tilePos = player->hand->getTilePos(shape, colour);
    player->hand->deleteTile(tilePos);

    // add tile to players hadn
    int pickTile = rand() % (bag->getSize() + 1);
    Tile tileToRemove = bag->getTile(pickTile);
    player->hand->addTileToBack(&tileToRemove);
    bag->deleteTile(pickTile);

    Tile *tileToAdd = new Tile(shape, colour);
    bag->addTileToBack(tileToAdd);
}