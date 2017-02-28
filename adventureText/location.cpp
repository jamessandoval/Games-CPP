/*
 *  location.cpp
 *  CS 162 - Final Project
 *
 *  Created by James Sandoval - 3/14/16.
 *
 *  Description: This program attempts to use good OOP style programming
 *  implementing such features as inheritance, polymorpism, and pointers.
 *
 *  Cheifly, it is a gmae called "The Search for the Lost City of Paititi"
 *  which is a text based game that requires the player to navigate through
 *  a series of locations/spaces and collect a number of items to reach the
 *  end goal in a limited period of time.
 *
 */


#include "location.hpp"
#include "player.hpp"

#include <string>
#include <iostream>

// For the rolldie function:
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

/********************************************************
 *          Name: Location Constructor
 *   Description: constructor
 *    Parameters: string
 ********************************************************/
Location::Location(string n){
    
    name = n;
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    
}

/********************************************************
 *          Name: setNorth
 *   Description: sets North
 *    Parameters: the location
 ********************************************************/

void Location::setNorth(Location *d){
    
    north = d;
}

/********************************************************
 *          Name: setEast
 *   Description: sets East
 *    Parameters: the location
 ********************************************************/

void Location::setEast(Location *d){
    
    east = d;
}

/********************************************************
 *          Name: setSouth
 *   Description: sets south
 *    Parameters: the location
 ********************************************************/

void Location::setSouth(Location *d){
    
    south = d;
}

/********************************************************
 *          Name: setNorth
 *   Description: sets North
 *    Parameters: the location
 ********************************************************/

void Location::setWest(Location *d){
    
    west = d;
}



int Location::rolldie(){
    
    usleep(10);
    
    srand(rand() + time(0) + clock());
    
    return rand() % 100 + 1;
    
}
/********************************************************
 *        Name: clearScreen
 * Description: clears the screen
 *  Parameters: None
 ********************************************************/

void clearScreen()
{
    cout << "\033[2J\033[1;1H";
}



