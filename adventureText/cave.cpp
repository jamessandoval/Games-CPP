/*
 *  cave.cpp
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

#include "cave.hpp"
#include <iostream>
#include "inventory.hpp"

// virtual enterLocation Function for jungle
PlayerStatus Cave::enterLocation(Player *player){
    
    if(player->outOfTime()){
        
        return NO_TIME;
    }
    
    int choice;
    Item itemName;
    
        clearScreen();
        
        if(player->getInventory()->checkInventory(TOAD) == false){
            
        cout << "     Well...there\'s supposed to be a cave here, but      \n"
             << "    if the villagers didn\'t give you something you\'ll   \n"
             << "                 never be able to find it.                \n\n";
            
            do{
                printMenu();
                
                cout << "Input:";
                
                cin >> choice;
                
                switch (choice) {
                        // set location to the village
                    case 1: player->setLocation(east);
                        break;
                        //Set location to City
                    case 2: player->setLocation(west);
                        break;
                        //Set Location to ruins
                    case 3: player->setLocation(south);
                        break;
                    case 4: return QUIT;
                        break;
                        
                    default: cout << "Make a better choice.\n";
                        break;
                }
                
            }while (choice < 1 || choice > 4);
    
                return ALIVE;
        }
    
        cout << "              You\'ve found the Hidden Cave                \n";
        
        usleep(900000);
            
        cout << " You\'re just moments away from making the discovery of a century.\n\n";
            
        usleep(900000);
            
        cout << " Just a little further...\n\n";

        player->setLocation(north);
    
    return ALIVE;
        
}

void Cave::printMenu(){
    
    cout << "Where should you go from here:\n";
    
    cout << " 1) Go back to the village.\n";
    cout << " 2) Go back to the city.\n";
    cout << " 3) Go to the ruins.\n";
    cout << " 4) Just quit already.\n\n";
    
    
}