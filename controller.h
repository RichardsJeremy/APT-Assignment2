#ifndef CONTROLLER_ASS_TWO
#define CONTROLLER_ASS_TWO

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

    void runGame(std::shared_ptr<Board> board, std::shared_ptr<Player> player1, std::shared_ptr<Player> player2,
                 std::shared_ptr<LinkedList> bag, bool p1Starts, bool aIEnabled);

    void endGame(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2);

    void showInformation();

    void createBag(std::shared_ptr<LinkedList> bag);
};

#endif
