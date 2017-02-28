/*
 *  village.cpp
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

#include "village.hpp"

#include <iostream>
#include "inventory.hpp"


// virtual enterLocation Function for jungle
PlayerStatus Village::enterLocation(Player *player){
    
    if(player->outOfTime()){
        
        return NO_TIME;
    }
    
    int choice;
    
    clearScreen();

        cout << "      Welcome to the Village of the Great Yanomanos      \n"
             << "    The Tribespeople are immediately curious of you and  \n"
             << "                   your fellow travelers...             \n\n";
        
        usleep(900000);

        if(player->getInventory()->checkInventory(STONE) == false){
            
        cout << "   The villagers see that you don\'t have the Panther stone \n"
             << "            and they immediately begin surrounding you...   \n\n"
             << "                       It\'s not looking good.              \n\n";
            
        usleep(900000);
            
        cout << "  The Cheiftan shouts something you can\'t quite understand... \n\n"
             << " Before you know it, you're being attacked by the entire tribe...\n\n";
        
        usleep(900000);
            
            player->setHealth(player->getHealth()-rolldie());
            
        cout << "  Your health is now " << player->getHealth() << "\n\n";
            
            if(player->getInventory()->checkInventory(MEDKIT) == true){
                
                usleep(900000);
                
                cout << "\n\ngood thing you bought a med kit\n\n";
                
                player->setHealth(player->getHealth()+50);
                
                cout << " health is restored to " << player->getHealth() << endl;
                
                
            }
            
            if(player->getHealth() > 50){
                
                cout << " Well, that was close, but you\'re going to be ok.";
            }
        
            else if(player->getHealth() < 50 && player->getHealth() > 0){
                
                cout << "  You\'ve just been beaten within inches of your life,\n"
                     << "  but there\'s a chance you could still make it.\n\n";
                
            }else{
                
                cout << " Well, that\'s too bad, apparently you weren\'t \n"
                     << " cut out for this type of work.";
                
                return DEAD;
            }
        }else{
            
            cout << "       They see that you have the Panther Stone   \n"
                 << "          and they immediately bow down to you      \n"
                 << "                and your fellow travelers...         \n\n";
            
            if(player->getInventory()->checkInventory(TOAD) == false && player->getInventory()->checkInventory(STONE) == true){
            
                    player->getInventory()->addItem(TOAD);
                
            cout << "           You\'ve been given the magic toad....       \n\n"
                 << "      This will enable you to journey through the     \n"
                 << "                     Hidden Caves.                       \n";
                
            }
            
            
        }
    
    
    do{
        
        printMenu();
        
        cout << "Input:";
        
        cin >> choice;
        
        switch (choice) {
                // set location to the cave
            case 1: player->setLocation(west);
                break;
                //set location to the ruins
            case 2: player->setLocation(east);
                break;
                // set location to the store
            case 3: return QUIT;
                break;
                
            default: cout << "Make a choice!\n\n";
                break;
        }
        
        
}while (choice < 1 || choice > 3);
    
    return ALIVE;
}

void Village::printMenu(){
    
    cout << " Where to now?\n\n";
    cout << " 1) Go to the Hidden Caves.\n";
    cout << " 2) Go to the Ruins.\n";
    cout << " 3) I just wanna go home.\n\n";
}
