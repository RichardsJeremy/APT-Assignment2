#include <string>
#include <iostream>
#include <fstream>

class gameEngine
{
private:
    /* data */
public:
    gameEngine(/* args */);

    ~gameEngine();

    void saveGame(std::string saveGameName, Player *player1, Player *player2,
    bool playerOneTurn, LinkedList *bag, Board *board);

    void placeTile(std::string tile, std::string pos, LinkedList *bag,
    Board *board, Player *player);

    void replaceTile(std::string tile, LinkedList *bag,
    Player *player);
};

