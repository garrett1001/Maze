#include "Cell.h"

using namespace std;

Cell::Cell( )
{
    isWall = false;
    beenVisited = false;
}

void Cell::setIsWall( bool state )
{
    isWall = state;
}

void Cell::setVisited( bool state )
{
    beenVisited = state;
}

bool Cell::getIsWall()
{
    return isWall;
}

bool Cell::getBeenVisited()
{
    return beenVisited;
}


