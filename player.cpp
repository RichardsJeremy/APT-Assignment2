#include "player.h"
#include <iostream>

Player::Player()
{
  name = nullptr;
  *score = 0;
  *hand = LinkedList();
}

Player::~Player()
{
  delete name;
  delete score;
  delete hand;
}

void Player::setName(std::string _name)
{
  *name = _name;
}

std::string Player::getName()
{
  return *name;
}

void Player::addScore(int amount)
{
  *score += amount;
}

// Would be used if implementing an undo function
void Player::subtractScore(int amount)
{
  *score -= amount;
}

int Player::getScore()
{
  return *score;
}

// Prints the information in the save file format
void Player::printInformation()
{
  std::cout << *name << std::endl;
  std::cout << *score << std::endl;
  std::cout << hand->toString() << std::endl;
}
