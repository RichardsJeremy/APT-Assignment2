#ifndef CONTROLLER_ASS_TWO
#define CONTROLLER_ASS_TWO

class Board;
class Player;
class LinkedList;

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

    void runGame(Board *board, Player *player1, Player *player2, LinkedList *bag,
    bool p1Starts);

    void endGame(Player *player1, Player *player2);

    void showInformation();

    void createShuffledBag(LinkedList *bag);
};


#endif
