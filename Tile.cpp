
#include "Tile.h"

Tile::Tile(char colour_, int shape_) : colour(colour_), shape(shape_) {}

std::string Tile::toString()
{
	std::string toReturn;
	std::string toChar;
	toChar = (char)colour;
	toReturn.append(toChar);
	toReturn.append(std::to_string(shape));
    return toReturn;    
}

char Tile::getColour()
{
    return colour;
}

int Tile::getShape()
{
    return shape;
}

bool Tile::equals(Tile* toCompare)
{
    if(this->getColour() == toCompare->getColour())
        if(this->getShape() == toCompare->getShape())
            return true;
    return false;
}

bool Tile::related(Tile* toCompare)
{
    if(this->getColour() == toCompare->getColour())
    {
        if(this->getShape() != toCompare->getShape())
            return true;
        return false;
    }        
    if(this->getShape() == toCompare->getShape())
        return true;
    return false;

}
