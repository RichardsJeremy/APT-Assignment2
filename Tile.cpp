
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

bool Tile::equals(Tile* inTile)
{
    if(this->getColour() == inTile->getColour())
        if(this->getShape() == inTile->getShape())
            return true;
    return false;
}
