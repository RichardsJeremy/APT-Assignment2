#ifndef PLAYER_H
#define PLAYER_H
#include "LinkedList.h"
#include <iostream>
#include <string>

class Player{

public:
  std::string name;
  int score;
  LinkedList* hand;

  Player(std::string setName);
  ~Player();

  void setName(std::string _name);
  std::string getName();

  void addScore(int amount);
  int getScore();
    
  std::string playerInformation();
};

#endif //PLAYER_H