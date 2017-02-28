/*
 *  inventory.hpp
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

#ifndef INVENTORY_HPP
#define INVENTORY_HPP


#include <vector>
#include <iostream>

using namespace std;

// Items in the inventory

enum Item {KNIFE, MACHETTE, PISTOL, COMPASS, TOAD, ELIXIR, MEDKIT, STONE ,NO_ITEM};

class Inventory{
    
private:
    
    vector <Item> items;
    void printItem(Item itemName);
    
public:
    
    void addItem(Item itemName);
    void removeItem(Item itemName);
    Item useItem();
    int getSize();
    bool checkInventory(Item itemName);
    
    
};



#endif
