#ifndef PLAYER_H
#define PLAYER_H
#include "LinkedList.h"

class Player{

public:
  std::string name;
  int score;
  LinkedList hand;

  Player();
  ~Player();

  void setName(std::string setName);
  std::string getName();

  void addScore(int amount);
  int getScore();
    
  std::string playerInformation();
};

#endif //PLAYER_H