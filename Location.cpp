#include "Location.h"
#include "Direction.h"

using namespace std;

Location::Location( )
{
    row = 0;
    col = 0;
}

Location::Location( int r , int c , Direction d )
{
    row = r;
    col = c;
    dir = d;
}

void Location::set( int r , int c )
{
    row = r;
    col = c;
}

void Location::setRow( int r )
{
    row = r;
}

void Location::setCol( int c )
{
    col = c;
}

void Location::setDir( Direction d )
{
    dir = d;
}

int Location::getRow() const
{
    return row;
}

int Location::getCol() const
{
    return col;
}

Direction Location::getDir() const
{
    return dir;
}

bool Location::inBounds( int lx , int ux , int ly , int uy ) const
{
    if( ( lx <= col ) && ( col <= ux ) && ( ly <= row ) && ( row <= uy ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

Location Location::Go() const
{
    Location next;

    if( dir.getDirection() == 'N' )
    {
        next.row = row - 1;
        next.col = col;
    }
    else if( dir.getDirection() == 'E' )
    {
        next.row = row;
        next.col = col + 1;
    }
    else if( dir.getDirection() == 'S' )
    {
        next.row = row + 1;
        next.col = col;
    }
    else if( dir.getDirection() == 'W' )
    {
        next.row = row;
        next.col = col - 1;
    }
    
    return next;
}

bool Location::Turn()
{
    if( dir.getDirection() == 'W' )
    {
        return false;
    }
    else
    {
        dir.setNextDirection();
        return true;
    }
}

bool Location::canTurn()
{
    if( dir.getDirection() == 'W' )
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*friend bool operator==( const Location& a , const Location& b )
{
    if( a.row == b.row && a.col == b.col )
    {
        return true;
    }
    else
    {
        return false;
    }
}

friend bool operator!=( const Location& a , const Location& b )
{
    if( a.row != b.row && a.col != b.col )
    {
        return true;
    }
    else
    {
        return false;
    }
}*/
