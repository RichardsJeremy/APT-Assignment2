#include <string>

class gameEngine
{
private:
    /* data */
public:
    gameEngine(/* args */);

    ~gameEngine();

    void saveGame(std::string saveGameName);

    void placeTile(std::string tile, std::string pos);

    void replaceTile(std::string tile);
};

