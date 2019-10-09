
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <string>

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int getSize();
   int getTilePos(int shape, char colour);
   Tile * getTile(int pos);
   void addTileToBack(Tile *tile);
   void deleteTile(int pos);
   std::string toString();

private:
   Node* head;
   int size;
};

#endif // ASSIGN2_LINKEDLIST_H
