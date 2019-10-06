
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int getSize();
   int getTilePos();
   Tile getTile();
   void addTileToBack();
   void deleteTile();

private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
