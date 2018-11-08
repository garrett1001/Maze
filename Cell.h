#ifndef CELL_H
#define CELL_H

class Cell
{
    private:
        bool isWall;
        bool beenVisited;
        
    public:
        Cell( );
        void setIsWall( bool state );
        void setVisited( bool state );
        bool getIsWall();
        bool getBeenVisited();
};

#endif