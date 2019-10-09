#include "player.h"
#include <iostream>

// Constructor
Player::Player()
{
  name = nullptr;
  *score = 0;
  *hand = LinkedList();
}

// Destructor
Player::~Player()
{
  delete name;
  delete score;
  delete hand;
}

// Used to set the name of a Player
void Player::setName(std::string _name)
{
  *name = _name;
}

// Returns the player's name
std::string Player::getName()
{
  return *name;
}

// Used to add to a player's total score
void Player::addScore(int amount)
{
  *score += amount;
}

// Returns the player's score
int Player::getScore()
{
  return *score;
}

// Prints the information in the save file format
std::string Player::playerInformation()
{
  std::string toString = "";
  toString.append(getName() + "\n");
  toString.append(getScore() + "\n");
  toString.append(hand->toString() + "\n");

  return toString;
}
