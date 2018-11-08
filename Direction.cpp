#include "Direction.h"

using namespace std;

Direction::Direction( )
{
    direction = 'N';
}

void Direction::setNextDirection()
{
    if( direction == 'N' )
    {
        direction = 'E';
    }
    else if( direction == 'E' )
    {
        direction = 'S';
    }
    else if( direction == 'S' )
    {
        direction = 'W';
    }
    else if( direction == 'W' )
    {
        direction = 'N';
    }
}

void Direction::setDirection( char d )
{
    direction = d;
}

char Direction::getDirection() const
{
    return direction;
}
