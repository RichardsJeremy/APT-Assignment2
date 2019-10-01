
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H
#include <string>

class Tile {
private:
    char colour;
    int shape;
public:
    Tile(char colour_, int shape_);
    std::string toString();
    char getColour();
    char getShape();
    bool equals(Tile* inTile);
};

#endif // ASSIGN2_TILE_H
