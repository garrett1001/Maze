#ifndef DIRECTION_H
#define DIRECTION_H

class Direction
{
    private:
        char direction;
    
    public:
        Direction( );
        void setNextDirection();
        void setDirection( char d );
        char getDirection()const;
};

#endif