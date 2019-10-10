//Jeremy Richards
//S3721762@student.rmit.edu.au

#include "LinkedList.h"

//Constructor, initialise empty LinkedList.
LinkedList::LinkedList() {
   head = nullptr;
   size = 0;
}

//Destructor, deletes each item.
LinkedList::~LinkedList() {
   for (int i = 0; i<size; i++) {
      delete getTile(i);
   }
   head = nullptr;
}

//Returns the size of the list.
int LinkedList::getSize() {
   return size;
}

//Returns a tile.
Tile* LinkedList::getTile(int tilePos) {
	Node* tileNode = head;
	for (int i = 0; i<tilePos; i++) {
		tileNode = tileNode->next;
	}
	return tileNode->tile;
}

//Returns a tile position.
int LinkedList::getTilePos(int shape, char colour) {
	Tile toFind = Tile(colour, shape);
	Node* tileNode = head;
	int currentPos = 0;
	while (tileNode != nullptr) {
		if (tileNode->tile->equals(&toFind)) 
		{
			return currentPos;
		}
		currentPos++;
		tileNode = tileNode->next;
	}
	return NULL;
}

//Adds a tile to the list.
void LinkedList::addTileToBack(Tile* tile) {
   Node* newTile = new Node(tile, nullptr);
   if (size > 1) {
	  Node* tempTile = head;
	  while (tempTile->next != nullptr) {
		 tempTile = tempTile->next;
	  }
	  tempTile->next = newTile;
   }
   else if (size == 1) {
	  head->next = newTile;
   }
   else {
	  head = newTile;
   }
}

//Deletes the Tile at position.
void LinkedList::deleteTile(int tilePos) {
	Node* previousNode = head;
	Node* toDelete = head;
	for (int i = 0; i<tilePos; i++) {
		previousNode = toDelete;
		toDelete = toDelete->next;
	}
	if (toDelete->next) 
	{
		previousNode->next = toDelete->next;
	}
	delete toDelete;
	size--;
}
//To String Method.
std::string LinkedList::toString() 
{
   std::string toReturn = "";
   Node* node = head;
   while (node) 
   {
	   toReturn += ",";
	   toReturn += node->tile->toString();
   }
   return toReturn;
}