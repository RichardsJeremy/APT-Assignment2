#include "LinkedList.h"

class Player{
  std::string* name;
  int* score;

public:
  LinkedList* hand;

  Player();
  ~Player();

  void setName(std::string _name);
  std::string getName();

  void addScore(int amount);
  int getScore();
    
  std::string playerInformation();
};
