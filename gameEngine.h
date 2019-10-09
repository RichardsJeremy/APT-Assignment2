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

    void saveGame(std::string saveGameName, std::shared_ptr<Player> player1, std::shared_ptr<Player> player2,
    bool playerOneTurn, std::shared_ptr<LinkedList> bag, std::shared_ptr<Board> board);

    void placeTile(std::string tile, std::string pos, std::shared_ptr<LinkedList> bag,
    std::shared_ptr<Board> board, std::shared_ptr<Player> player);

    void replaceTile(std::string tile, std::shared_ptr<LinkedList> bag,
    std::shared_ptr<Player> player);
};

