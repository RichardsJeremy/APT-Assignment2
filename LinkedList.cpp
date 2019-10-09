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
      delete get(i);
   }
   head = nullptr;
}

//Returns the size of the list.
int LinkedList::getSize() {
   return size;
}

//Returns a tile.
Tile LinkedList::getTile(int tilePos) {
	Node* tileNode = head;
	for (int i = 0; i<tilePos; i++) {
		tileNode = tileNode->next;
	}
	return tileNode->tile;
}

//Returns a tile position.
int LinkedList::getTilePos(int shape, char colour) {
	Node* tileNode = head;
	int returnPos = 0;
	int currentPos = 0;
	while (tempNode != nullptr) {
		if (returnPos == 0;)
			if (tempNode->tile->getShape() == shape && tempNode->tile->getColour() == colour) {
				returnPos = currentPos;
			}
		currentPos++;
	}
	returnPos -= 1;
	return returnPos;
}

//Adds a tile to the list.
void LinkedList::addTileToBack() {
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
	Node* tileNode = head;
	for (int i = 0; i<tilePos; i++) {
		tileNode = tileNode->next;
	}
	Node* toDelete = tileNode->next;
	if (toDelete->next != nullptr) {
		tileNode->next = toDelete->next;
		delete toDelete;
		while (tempTile->next != nullptr) {
			toDelete = tileNode->next;
			tileNode->next = toDelete->next;
			delete toDelete;
		}
	}
	else {
		tileNode->next = toDelete->next;
		delete toDelete;
	}
	size--;
}