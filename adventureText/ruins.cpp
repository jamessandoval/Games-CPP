/*
 *  ruins.cpp
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

#include "ruins.hpp"
#include <iostream>
#include "inventory.hpp"

// virtual enterLocation Function for jungle
PlayerStatus Ruins::enterLocation(Player *player){
    
    
    if(player->outOfTime()){
        
        return NO_TIME;
    }
    
    int choice;
    Item itemName;
    
    do{
        
        clearScreen();
        
        if(player->getInventory()->checkInventory(STONE) == false){
            
        cout << "                          You\'ve found the ruins!                      \n\n";
        
        cout << "   Good Choice....If you would have gone to the village straight from   \n"
             << "    the jungle the village people might have shrunken your head and     \n"
             << "      used your remains in tribal rituals for generations to come.      \n\n";
        
                player->getInventory()->addItem(STONE);
                
        cout << "                       You\'ve found the legendary                       \n"
             << "                          *#* Panther Stone *#*.                         \n\n"
             << "                   Now you are safe to enter the village.                \n"
             << "                 The villagers will now regard you as a God              \n\n";
        }else{
            
        cout << "            You\'ve seen all there is to see here at the ruins!          \n\n";
        
        }
        
        printMenu();
        
        cout << "Input:";
        
        cin >> choice;
        
        switch (choice) {
                // set location to the village
            case 1: player->setLocation(south);
                break;
                // set location to the caves
            case 2: player->setLocation(north);
                break;
            case 3: return QUIT;
                
            default: cout << "Nope, pick another choice.\n";
                break;
        }
        
        
}while (choice < 1 || choice > 3);
    
    return ALIVE;
}

void Ruins::printMenu(){
     cout <<"\nWhere to next?\n\n";
     cout << " 1) Go to the Village\n";
     cout << " 2) Go to the hidden caves\n";
     cout << " 3) Quit already.\n\n";
    
    
}