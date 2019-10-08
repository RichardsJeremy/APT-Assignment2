#include "controller.h"
#include "player.cpp"
#include "board.cpp"
#include "gameEngine.cpp"
#include "LinkedList.cpp"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#define NUMBER_OF_TILES 6
#define BOARD_HEIGHT 10

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
	std::shared_ptr<Board> board = std::make_shared<Board>();
	std::shared_ptr<Player> player1 = std::make_shared<Player>();
	std::shared_ptr<Player> player2 = std::make_shared<Player>();
	
	std::shared_ptr<LinkedList> bag = std::make_shared<LinkedList>();
    createShuffledBag(bag);

    for (int i = 0; i < NUMBER_OF_TILES; i++)
    {
        //TODO code to remove front tiles from bag and add
        // to players hands.
    }

    runGame(board, player1, player2, bag, true);
}

/* This method reads in input from a saved file to create a new gameEngine object with
a board and two players with appriopriate tiles. 
*/
void controller::loadGame()
{

    std::cout << "\nEnter the file name from which to load a game\n";
    std::string fileName = "";
    std::cin >> fileName;

    // file is 18 lines long for all data
    std::string fileData [18];
    int loopCounter = 0;
    std::string line;
    std::ifstream saveFile (fileName);

    //declaing bool for who starts
    bool p1Starts = true;


    if (saveFile.is_open())
    {
        while (! saveFile.eof())
        {
            std::getline(saveFile,line);
            fileData[loopCounter] = line;
            loopCounter++;
        }
        saveFile.close();

        // getting players
        std::string playerOneName = fileData[0];
        int playerOneScore = std::stoi(fileData[1]);
        // secondary constructor for player will convert string into linked list
        std::string playerOneHand = fileData[2];
        std::string playerTwoName = fileData[3];
        int playerTwoScore = std::stoi(fileData[4]);
        // secondary constructor for player will convert string into linked list
        std::string playerTwoHand = fileData[5];

		std::shared_ptr<Player> player1 = std::make_shared<Player>();
		std::shared_ptr<Player> player2 = std::make_shared<Player>();

        std::string boardString = "";
        for (int i = 6; i < BOARD_HEIGHT; i++)
        {
            boardString += fileData[i] + "\n";
        }
        //constructor for board takes in string input. 
		std::shared_ptr<Board> board = std::make_shared<Board>();
        
        //constructor for list takes in string
		std::shared_ptr<LinkedList> bag = std::make_shared<LinkedList>(fileData[16]);
        if (fileData[17] == fileData[0])
        {
            p1Starts = true;
        }
        else
        {
             p1Starts = false;
        }
                
        std::cout << "Quirkle game successfully loaded ";
        runGame(board, player1, player2, bag, p1Starts);
        // TODO implment loading into various form to create board and players.
    }
    else
    {
        std::cout << "File not loaded :(\n";
    }
}

/*This method takes in a the neccessary objects to run the gaem and then loops 
with a while loop until a player wins or quits
*/
void controller::runGame(Board *board, Player *player1, Player *player2, LinkedList *bag,
bool p1Starts)
{
    // Creating helper gameEngine object
	std::shared_ptr<gameEngine> gameEngineHelper = std::make_shared<gameEngine>();

    // booleans for quitting, winning  
    // game will only loop if these are false
    bool quit = false;
    bool win = false;

    //boolean for which players turn
    bool playerOneTurn = p1Starts;

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

            if ((userTurn.length == 14) && (userTurn.substr(0,5) == "place"))
            { //i.e a place move
                std::string tile = userTurn.substr(6, 2);
                std::string position = userTurn.substr(12, 2);

                if (playerOneTurn)
                {
                    gameEngineHelper->placeTile(tile, position, bag, board, player1);
                }
                else
                {
                    gameEngineHelper->placeTile(tile, position, bag, board, player1);
                }
            }
            else if ((userTurn.length == 10) && (userTurn.substr(0, 7) == "replace")) //i.e. replace tile
            {
                if (bag->size() > 0)
                {
                    std::string tile = userTurn.substr(9, 2);
                    if (playerOneTurn)
                    {
                        gameEngineHelper->replaceTile(tile, bag, player1);
                    }
                    else
                    {
                        gameEngineHelper->replaceTile(tile, bag, player2);
                    }
                }
                else
                {
                    std::cout << "Bag is empty, you can not draw from it!\n";
                    invalidTurn = true;
                }
            }
            else
            {
                if ((userTurn.substr(0, 4) == "save"))
                {
                    gameEngineHelper->saveGame(userTurn.substr(6), player1, player2,
                    playerOneTurn, bag, board);
                    quit = true;
                }
                else
                {
                    std::cout << "Invalid Input";
                invalidTurn = true;
                }
                
                
            }
        }

        // check bag or player hand
        if ((bag->size == 0) || (player1->getHand()->size() == 0) || 
        (player2->getHand()->size() == 0))
        {
            win = true;
            endGame(player1, player2);
        }
        else // i.e. game is continuing
        {
            if (playerOneTurn)
            {
                playerOneTurn = false;
            }
            else
            {
                playerOneTurn = true;
            }
        }
    }
}

//End of game and restarts menu and deletes save if there was one.
void controller::endGame(Player *player1, Player *player2)
{

    std::cout << "Game over\n";
    std::cout << "Score for " << player1->getName() << ": " << player1->getScore() << "\n";
    std::cout << "Score for " << player2->getName() << ": " << player2->getScore() << "\n";
    if (player1->getScore() > player2->getScore())
    {
        std::cout << "Player" << player1->getName() << " won!";
    }
    else
    {
        std::cout << "Player" << player2->getName() << " won!";
    }
}

// displays information about who wrote the game
void controller::showInformation()
{

    std::cout << "\n----------------------------------\n";
    std::cout << "Name:\tMaxwell Morrissy\n";
    std::cout << "Student ID:\ts3668048\n";
    std::cout << "Email:\ts3668048@student.rmit.edu.au\n\n";

    std::cout << "Name:\tLiam Pietralla\n";
    std::cout << "Student ID:\ts3784354\n";
    std::cout << "Email:\ts3784354@student.rmit.edu.au\n\n";

    std::cout << "Name:\tTravis Stella\n";
    std::cout << "Student ID:\ts3783006\n";
    std::cout << "Email:\ts3783006@student.rmit.edu.au\n\n";

    std::cout << "Name:\tJeremy Richards\n";
    std::cout << "Student ID:\ts3721762\n";
    std::cout << "Email:\ts3721762@student.rmit.edu.au\n";
    std::cout << "----------------------------------\n";
}

void controller::createShuffledBag(LinkedList *bag)
{
    //TODO create shuffled bag.
}
