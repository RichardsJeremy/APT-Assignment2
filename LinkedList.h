
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
   int getTilePos();
   Tile getTile();
   void addTileToBack();
   void deleteTile();
   std::string toString();

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
