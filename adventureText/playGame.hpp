/*
 *  playGame.hpp
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


#ifndef PLAYGAME_HPP
#define PLAYGAME_HPP

#include <iostream>
#include "player.hpp"
#include <string>
#include "location.hpp"
#include "city.hpp"
#include "store.hpp"
#include "jungle.hpp"

// PlayGame class definition
class PlayGame {
    
private:
    
    Location *city;
    Location *jungle;
    Location *store;
    Location *village;
    Location *ruins;
    Location *cave;
    Location *lostCity;
    
    Player *player;
    
    void play();
    void win();
    void lose();
    void noMoreTime();
    void quitter();
    
public:
    
    PlayGame();
    void begin();
    
};


#endif 
