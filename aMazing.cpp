#include <iostream>
#include <sstream>   // for istringstream
#include <utility>
#include <vector>
#include <string>
#include <stack>
#include "Cell.h"
#include "Maze.h"
#include "Direction.h"
#include "Location.h"

using namespace std;

vector<string> split( const string& s , char delimiter ) //splits an input
{
   vector<string> terms;         // vector of terms
   string term;                  // a single term
   istringstream termStream(s);  // an input string stream
   
   while( getline( termStream , term , delimiter ) )
        terms.push_back(term);    // add found term

   return terms;
}

int main()
{
    string input;             // input string
    char   delimiter = ' ';   // what separates terms in the input string
    int mazeCount = 1;
    
    while(getline( cin , input ))    // runs while there is valid input
    {
        Maze aMaze;  // creates a new maze
        stack <Location> path;  // creates a stack of locations
        string input2;
        bool solution = false;
        vector<string> vecOfRow = split( input , delimiter );    // Use the split() function above to extract terms
        
        aMaze.setMazeRow( vecOfRow, 0 );  //  sets first row
        
        for( int i = 1; i < 10; i++ ) // gets and sets rest of rows
        {
            getline( cin , input2 );
            vector<string> vecOfRow2 = split( input2 , delimiter );
            aMaze.setMazeRow( vecOfRow2, i);
        }
        getline( cin , input ); //  gets emty line
         
        
        Location start = aMaze.getStart();  //  creates and gets start location
        path.push( start );  //pushs start location onto stack
        
        Location current;
        
        while(!path.empty() && !aMaze.isGoal( current ) && !solution)  //  find path
        {
            current = path.top();
            path.pop();
            
            while( current.canTurn() )
            {
                Location step = current.Go();
                
                Cell stepCell = aMaze.getCell( step.getRow(), step.getCol() );
                
                if( aMaze.isGoal( step ) )
                {
                    path.push( step );
                    solution = true;
                }
                else if( !stepCell.getIsWall() && !stepCell.getBeenVisited() && step.inBounds( 0, 9, 0, 9 ) )
                {
                    stepCell.setVisited( true );
                    aMaze.setMazeCell( stepCell, step.getRow(), step.getCol() );
                    
                    current.Turn();
                    
                    path.push( current );
                    
                    current = step;
                }
                else
                {
                    current.Turn();
                }
            }
        }
        
        vector<Location> vecPath;  // puts path into vector
        while(!path.empty())
        {
          vecPath.push_back(path.top());
          path.pop();
        }
        
        if( solution == true )
        {
            cout<<"Maze "<<mazeCount<<": Solution found"<<endl;
            aMaze.printMaze( vecPath, solution );
            mazeCount++;
        }
        else
        {
            cout<<"Maze "<<mazeCount<<": Solution found"<<endl;
            aMaze.printMaze( vecPath, solution );
            mazeCount++;
        }
    }
    
    
    return 0;
}
