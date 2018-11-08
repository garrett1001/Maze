#include "Maze.h"
#include "Cell.h"
#include "Location.h"
#include "Direction.h"

using namespace std;

void Maze::setMazeRow( vector<string> input, int row )
{
    for(int col = 0; col < 10; col++)
    {
        Cell aCell;
        
        if( input[col] == "S" )
        {
            start.set( row, col );
            aCell.setVisited(true);
            maze[row][col] = aCell;
        }
        else if( input[col] == "G" )
        {
            goal.set( row, col );
            maze[row][col] = aCell;
        }
        else if( input[col] == "0" )
        {
            maze[row][col] = aCell;
        }
        else if( input[col] == "1" )
        {
            aCell.setIsWall(true);
            maze[row][col] = aCell;
        }
    }
}

void Maze::setMazeCell( Cell aCell, int row, int col )
{
    maze[row][col] = aCell;
}

Cell Maze::getCell( int row, int col )
{
    Cell aCell = maze[row][col];
    
    return aCell;
}

Location Maze::getStart()
{
    return start;
}

bool Maze::isGoal( Location current )
{
    if( goal.getRow() == current.getRow() && goal.getCol() == current.getCol() )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Maze::printMaze( vector<Location> path, bool solution)
{
    char pMaze[10][10];
    
    for( int i = 0; i < 10; i++ )
    {
        for( int j = 0; j < 10; j++ )
        {
            if( maze[i][j].getIsWall() == true )
            {
                pMaze[i][j] = '1';
            }
            else
            {
                pMaze[i][j] = '0';
            }
        }
    }
    
    if( solution )
    {
        for( int i = 0; i < path.size(); i++ )
        {
            pMaze[path[i].getRow()][path[i].getCol()] = '*';
        }
    }
    
    pMaze[start.getRow()][start.getCol()] = 'S';
    pMaze[goal.getRow()][goal.getCol()] = 'G';
    
    for( int i = 0; i < 10; i++ )
    {
        for( int j = 0; j < 10; j++ )
        {
            cout<<pMaze[i][j];
            
            if( j < 9)
            {
              cout<<" ";
            }
        }
        cout<<endl;
    }
}