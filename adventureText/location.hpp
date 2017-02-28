/*
 *  location.hpp
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

#ifndef __LOCATION_HPP
#define __LOCATION_HPP

#include <iostream>
#include <string>
#include "player.hpp"
#include <ctime>
#include <unistd.h>

// Global function to clear screen:
void clearScreen();

using namespace std;

class Player;

// Parent Class definition for different locations
class Location {

protected:

    string name;
    Location *north;
    Location *east;
    Location *south;
    Location *west;

    virtual void printMenu() = 0;

public:
    
    Location(string n);
    
    // virtual function that returns the status of game and
    // keeps track of locations
    virtual PlayerStatus enterLocation(Player *player) = 0;
    
    // 4x location pointers for each "location"
    void setNorth(Location *d);
    void setEast(Location *d);
    void setSouth(Location *d);
    void setWest(Location *d);
    
    // a rolldie function to simulate chance...set at 100 
    int rolldie();
    
    
};




#endif
