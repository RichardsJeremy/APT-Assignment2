#include "player.h"


// Constructor
Player::Player(std::string setName)
{
  this->name = setName;
  this->score = 0;
  hand = new LinkedList();
}

// Destructor
Player::~Player()
{
  delete &name;
  delete &score;
  delete hand;
}

// Used to set the name of a Player
void Player::setName(std::string _name)
{
  this->name = _name;
}

// Returns the player's name
std::string Player::getName()
{
  return name;
}

// Used to add to a player's total score
void Player::addScore(int amount)
{
  this->score += amount;
}

// Returns the player's score
int Player::getScore()
{
  return score;
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
