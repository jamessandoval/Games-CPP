/*
 *  player.hpp
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

#ifndef PLAYER_HPP
#define PLAYER_HPP

// global constant to keep track of gameplay time
const int TIMER = 15;

// game status returned with virtual Gamestatus function at each location
enum PlayerStatus { ALIVE, DEAD, WON, NO_TIME, QUIT};

#include "inventory.hpp"
#include "location.hpp"
#include <ctime>

class Location;
class Inventory;

// definition of player class
class Player{
    
private:
    
    Location *location;
    Inventory *inventory;
    
    int health;
    int goldCoins;
    
    time_t startTimer;
    
public:
    Player(){
        
        inventory = new Inventory();
        
        health = 100;
        goldCoins = 25;
        
        // start the timer when player is created
        time(&startTimer);
    }
 
bool outOfTime(){
        
        time_t currentTime;
        time(&currentTime);
        
        if(difftime(currentTime, startTimer) / 60.0 > TIMER)
            return true;
        else
            return false;
        
    }

    // getter/setter functions for locations
    Location* getLocation(){
        
        return location;
    }
    void setLocation(Location *l){
        
        location = l;
    }
    // getter for inventory pointer
    Inventory* getInventory(){
        
        return inventory;
    }

    // getter//setter functions for health
    void setHealth(int h){
        
        health = h;
        
    }
    int getHealth(){
        
        return health;
    }
    
    // getter//setter functions for strength
    void setGoldCoins(int g){
        
        goldCoins = g;
        
    }
    int getGoldCoins(){
        
        return goldCoins;
    }

};




#endif
