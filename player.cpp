#include "player.h"

Player::Player()
{
    name = "";
    score = 0;
    hand::LinkedList();
}

Player::~Player()
{
    name = NULL;
    score = NULL;
    hand::deleteList();
}

void Player::setName(std::string _name)
{
    name = _name;
}

std::string Player::getName()
{
    return name;
}

void Player::addScore(int amount)
{
    score += amount;
}

// Would be used if implementing an undo function
void Player::subtractScore(int amount)
{
    score -= amount;
}

int Player::getScore()
{
    return score;
}

void Player::displayHand()
{
    //TODO Will iterate through each Node of the hand and print the data, seperated by commas.
}

// Prints the information in the save file format
void Player::printInformation()
{
    std::cout << name << std::endl;
    std::cout << score << std::endl;
    this.displayHand();
}
