#include "LinkedList.h"

class Player{
  std::string* name;
  int* score;
  LinkedList* hand;

public:
  Player();
  ~Player();

  void setName(std::string _name);
  std::string getName();

  void addScore(int amount);
  void subtractScore(int amount);
  int getScore();
    
  void printInformation();
};
