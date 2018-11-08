#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
#include "Cell.h"
#include "Location.h"
#include "Direction.h"

class Maze
{
    private:
        Cell maze[10][10];
        Location start;  //start location
        Location goal;  //goal location
    
    public:
        void setMazeRow( std::vector<std::string> input, int row);  // set 1 whole row of maze
        void setMazeCell( Cell aCell, int row, int col );  // sets one maze cell at a row and col
        Cell getCell( int row, int col ); //gets cell at row and col
        Location getStart();  //gets start location
        bool isGoal( Location current );  //checks is location is goal
        void printMaze( std::vector<Location> path, bool solution );  //prints maze
};

#endif