
#include "Tile.h"

Tile::Tile(char colour_, int shape_) : colour(colour_), shape(shape_) {}

std::string Tile::toString()
{
    return std::to_string(colour) + std::to_string(shape);    
}

char Tile::getColour()
{
    return colour;
}

char Tile::getShape()
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
