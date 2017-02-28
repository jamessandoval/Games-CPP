/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 17, 2016
 
 ** Title: Program 1
 
 ** Description: This program is an implementation of Conways game of
 life.
 
 *********************************************************************/
#ifndef conway_HPP
#define conway_HPP

using namespace std;

//Define Conway Class
class Conway{
private:
    vector<vector<char> > world;       // vector to hold 1st instance of matrix
    vector<vector<char> > mirror;      // vector to hold copy of matrix
    int xCoord;                        // User defined value X
    int yCoord;                        // User defined value Y
    
public:
    Conway();   // defualt constructor to initialize private members
    
    void setXCoord(int);       // Setter for X Coord
    void setYCoord(int);       // Setter for Y coord
    void printWorld();         // Prints a viewing pane to the console
    void scanWorld();          // Implments the ruls of conways game of life
    void oscillator();         // loads the matrix with a pattern
    void glider();             // loads the matrix with a pattern
    void gliderCannon();       // loads the matrix with a pattern
    
};

#endif

