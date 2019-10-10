#include "controller.h"
#include <iostream>
#include <stdlib.h>
#include <iterator>
#include <string>
#include <vector>
#include <memory>

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
        //loadGame();
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

    std::cout << "\nEnter a name for player 2 (uppercase characters only)\n (Enter 'AI' for an AI Character)\n";
    std::string playerTwoName = "";
    std::cin >> playerTwoName;

    std::cout << "\nLet's Play!";

    // create blank players and board here with heap allocation and then pass
    // pointers onto runGame() method.
    std::shared_ptr<Board> board = std::make_shared<Board>();
    std::shared_ptr<Player> player1 = std::make_shared<Player>(playerOneName);
    std::shared_ptr<Player> player2 = std::make_shared<Player>(playerTwoName);
    std::shared_ptr<LinkedList> bag = std::make_shared<LinkedList>();
    createBag(bag);

    for (int i = 0; i < NUMBER_OF_TILES; i++)
    {
		srand(time(NULL));
        int pickTile = rand() % bag->getSize();
		std::cout << "\n" << std::to_string(pickTile);
        Tile* tile = bag->getTile(pickTile);
        player1->hand->addTileToBack(tile); 
        bag->deleteTile(pickTile);

        pickTile = rand() % bag->getSize();
		std::cout << "\n" << std::to_string(pickTile);
        tile = bag->getTile(pickTile);
        player2->hand->addTileToBack(tile); 
        bag->deleteTile(pickTile);

    }
    if(player2->getName() == "AI") {
    runGame(board, player1, player2, bag, true, true);
    }
    else
    {
        runGame(board, player1, player2, bag, true, false);
    }

}

/* This method reads in input from a saved file to create a new gameEngine object with
a board and two players with appriopriate tiles. 
*/
/*void controller::loadGame()
{
    std::cout << "\nEnter the file name from which to load a game\n";
    std::string fileName = "";
    std::cin >> fileName;
    // file is 18 lines long for all data
    std::string fileData[18];
    int loopCounter = 0;
    std::string line;
    std::ifstream saveFile(fileName);
    //declaing bool for who starts
    bool p1Starts = true;
    if (saveFile.is_open())
    {
        while (!saveFile.eof())
        {
            std::getline(saveFile, line);
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
} */

/*This method takes in a the neccessary objects to run the gaem and then loops 
with a while loop until a player wins or quits
*/
void controller::runGame(std::shared_ptr<Board> board, std::shared_ptr<Player> player1, std::shared_ptr<Player> player2,
                         std::shared_ptr<LinkedList> bag, bool p1Starts, bool AIPlayerEnabled)
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
		std::cout << "\n";
        if (playerOneTurn)
        {
            std::cout << player1->getName() << ", it's your turn\n";
        }
        else
        {
            std::cout << player2->getName() << ", it's your turn\n";
        }
		char letterB = 66;
		board->placeTile(letterB, 1, 0, 0);
        std::cout << "Score for " << player1->getName() << ": " << player1->getScore() << "\n";
        std::cout << "Score for " << player2->getName() << ": " << player2->getScore() << "\n";
        std::cout << "\n";
        std::cout << board->toString();
        std::cout << "\n";
        std::cout << "Your hand is";
        if (playerOneTurn)
        {
            std::cout << player1->hand->toString();
        }
        else
        {
            player2->hand->toString();
        }
        std::cout << "\n";		
        std::string userTurn = "";
        std::getline(std::cin, userTurn);

        //bool to redo turn until valid input is entered
		bool invalidTurn = true;

        while (invalidTurn)
        {
            if(!playerOneTurn && AIPlayerEnabled) {
                    //MAXWELL -- INSERT YOUR CODE HERE


                    /*
                    MAXES CODE FOR AI
                    Just needs one turn - i.e. place tile or replace tile. The hand of the player is player2
                    to make it work with my existing function use this code below. All you have to do is replace the 
                    tile and position with strings of the tile (Y1) or position (A1)
                    gameEngineHelper->placeTile(tile, position, bag, board, player2)
                    if replaceing use this one where tile is also a string
                    gameEngineHelper->replaceTile(tile, bag, player2)
                    */
            }
            else
            {
                invalidTurn = false;

            if ((userTurn.length() == 14) && (userTurn.substr(0, 5) == "place"))
            { //i.e a place move
                std::string tile = userTurn.substr(6, 2);
                std::string position = userTurn.substr(12, 2);
				//place P4 at G5

                if (playerOneTurn)
                {
                    if(!(gameEngineHelper->placeTile(tile, position, bag, board, player1))) {
                        invalidTurn = true;
                        std::cout << "Please enter a valid move.\n";
                    }
                }
                else
                {
                   if(!(gameEngineHelper->placeTile(tile, position, bag, board, player1))) {
                       invalidTurn = true;
                       std::cout << "Please enter a valid move.\n";
                   }
                }
            }
            else if ((userTurn.length() == 10) && (userTurn.substr(0, 7) == "replace")) //i.e. replace tile
            {
                if (bag->getSize() > 0)
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

        }

        // check bag or player hand
        if ((bag->getSize() == 0) || (player1->hand->getSize() == 0) ||
            (player2->hand->getSize() == 0))
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
void controller::endGame(std::shared_ptr<Player> player1, std::shared_ptr<Player> player2)
{

    std::cout << "Game over\n";
    std::cout << "Score for " << player1->getName() << ": " << player1->getScore() << "\n";
    std::cout << "Score for " << player2->getName() << ": " << player2->getScore() << "\n";
    if (player1->getScore() > player2->getScore())
    {
        std::cout << "Player" << player1->getName() << " won!\n";
    }
    else
    {
        std::cout << "Player" << player2->getName() << " won!\n";
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

void controller::createBag(std::shared_ptr<LinkedList> bag)
{
    char colours [6] = {82, 79, 89, 71, 66, 80};
    int shapes [6] = {1,2,3,4,5,6};

    for (int i = 0; i < NUMBER_OF_TILES; i++)
    {
        for (int j = 0; j < NUMBER_OF_TILES; j++)
        {
            Tile* tile1 = new Tile(colours[i],shapes[j]);
            Tile* tile2 = new Tile(colours[i],shapes[j]);

            bag->addTileToBack(tile1);
            bag->addTileToBack(tile2);
        }

    }

}
