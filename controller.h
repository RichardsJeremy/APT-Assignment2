#ifndef CONTROLLER_ASS_TWO
#define CONTROLLER_ASS_TWO

class Board;
class Player;

class controller
{
private:
    /* data */
public:
    controller(/* args */);

    ~controller();

    void choose(int choice);

    void newGame();

    void loadGame();

    void runGame(Board *board, Player *player1, Player *player2);

    void endGame();

    void showInformation() {}
};


#endif
