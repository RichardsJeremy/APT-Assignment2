#include "controller.h"
#include "player.cpp"
#include "board.cpp"
#include "gameEngine.cpp"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

controller::controller(/* args */)
{
}

controller::~controller()
{
}

void controller::choose(int choice)
{

    if (choice == 1)
    {
        newGame();
    }
    else if (choice == 2)
    {
        loadGame();
    }
    else if (choice == 3)
    {
        showInformation();
    }
    else if (choice == 4)
    {
        std::cout << "Goodbye!!"
                  << "\n";
    }
}

// Method to start a game with all fields empty and then call runGame on them
void controller::newGame()
{

    std::cout << "\nStarting a New Game\n";

    std::cout << "Enter a name for player 1 (uppercase characters only)\n";
    std::string playerOneName = "";
    std::cin >> playerOneName;

    std::cout << "\nEnter a name for player 2 (uppercase characters only)\n";
    std::string playerTwoName = "";
    std::cin >> playerTwoName;

    std::cout << "\nLet's Play!";

    // create blank players and board here with heap allocation and then pass
    // pointers onto runGame() method.
    Board *board = new Board();
    Player *player1 = new Player(playerOneName);
    Player *player2 = new Player(playerTwoName);

    runGame(board, player1, player2);
}

/* This method reads in input from a saved file to create a new gameEngine object with
a board and two players with appriopriate tiles. 
*/
void controller::loadGame()
{

    std::cout << "\nEnter the file name from which to load a game\n";
    std::string fileName = "";
    std::cin >> fileName;

    if (performFileCheck())
    {
        std::cout << "Quirkle game successfully loaded ";

        // TODO implment loading into various form to create board and players.
    }
    else
    {
        return;
    }
}

/*This method takes in a the neccessary objects to run the gaem and then loops 
with a while loop until a player wins or quits
*/
void controller::runGame(Board *board, Player *player1, Player *player2)
{
    // Creating helper gameEngine object
    gameEngine *gameEngineHelper = new gameEngine();

    // booleans for quitting, winning and turn
    // game will only loop if these are false
    bool quit = false;
    bool win = false;
    bool playerOneTurn = true;

    while (!win && !quit)
    {
        if (playerOneTurn)
        {
            std::cout << player1->getName() << ", it's your turn";
        }
        else
        {
            std::cout << player2->getName() << ", it's your turn";
        }

        std::cout << "Score for " << player1->getName() << ": " << player1->getScore();
        std::cout << "Score for " << player2->getName() << ": " << player2->getScore();
        std::cout << "\n";
        board->display();
        std::cout << "\n";
        std::cout << "Your hand is";
        if (playerOneTurn)
        {
            player1->displayHand();
        }
        else
        {
            player2->displayHand();
        }
        std::cout << "\n";

        std::string userTurn = "";
        std::cin >> userTurn;

        //bool to redo turn until valid input is entered
        bool invalidTurn = true;

        while (invalidTurn)
        {
            invalidTurn = false;

            if (userTurn.length == 14)
            { //i.e a place move
                std::string tile = userTurn.substr(6, 2);
                std::string position = userTurn.substr(12,2);

                gameEngineHelper->placeTile(tile, position);
            }
            else if (userTurn.length == 10) //i.e. replace tile
            {
                std::string tile = userTurn.substr(9,2);
                gameEngineHelper->replaceTile(tile);
            }
            else
            {
                if ((userTurn.substr(0,4) == "save"))
                {
                    gameEngineHelper->saveGame(userTurn.substr(6));
                }
                 
                invalidTurn = true;
            }
            
        }
    }
}

//End of game and restarts menu and deletes save if there was one.
void controller::endGame() {}

// displays information about who wrote the game
void controller::showInformation()
{

    std::cout << "\n----------------------------------\n";
    std::cout << "Name:\tMaxwell Morrissy";
    std::cout << "Student ID:\ts3668048";
    std::cout << "Email:\ts3668048@student.rmit.edu.au\n";

    std::cout << "Name:\tLiam Pietralla";
    std::cout << "Student ID:\ts3784354";
    std::cout << "Email:\ts3784354@student.rmit.edu.au\n";

    std::cout << "Name:\tTravis Stella";
    std::cout << "Student ID:\ts3783006";
    std::cout << "Email:\ts3783006@student.rmit.edu.au\n";

    std::cout << "Name:\tJeremy Richards";
    std::cout << "Student ID:\ts3721762";
    std::cout << "Email:\ts3721762@student.rmit.edu.au";
    std::cout << "----------------------------------\n";
}