/*
 *  village.hpp
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

#ifndef VILLAGE_HPP
#define VILLAGE_HPP

#include <iostream>
#include "location.hpp"
#include "player.hpp"

class Village : public Location {
    
private:
    
    // the custom virtual function
    void printMenu();
    
public:
    
    Village() : Location("VILLAGE") {}
    
    // virtual function that returns the status of game and
    // keeps track of locations
    PlayerStatus enterLocation(Player *player);
    
};


#endif
