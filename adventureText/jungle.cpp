/*
 *  jungle.cpp
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

#include "jungle.hpp"

#include <iostream>
#include "inventory.hpp"
#include "player.hpp"
#include <ctime>


using namespace std;

// virtual enterLocation Function for jungle
PlayerStatus Jungle::enterLocation(Player *player){
    
    
    // check timer
    if(player->outOfTime()){
        
        return NO_TIME;
        
    }
    
    int choice;
    Item itemName;
    
    do{
        
        clearScreen();
        
        cout << "     You've finally arrived by train to the Amazon rainforest         \n"
             << "    up until now you\'ve only heard stories and read accounts         \n"
             << "     of explorers traveling to this remote part of the world.         \n\n";
        
        cout << "    Finally, it\'s your turn to leave a legacy and make your          \n"
             << "                        grandfather proud.                            \n\n";
        
        usleep(900000);
        
        cout << "   First things first, you\'re going to have to decide where to       \n"
             << "                             go next.                                 \n\n";
        
        cout << "   Legend has it that Tulalula holds a secret, and the tribespeople    \n"
             << "       only respect outsiders who wield this precious secret.         \n\n";
        
        cout << "Press Enter...\n";
        
        cin.get();
        cin.ignore();
        
        clearScreen();
        
        if(player->getInventory()->checkInventory(MACHETTE) == false){
            
            player->setHealth(player->getHealth()-rolldie());
            
            cout << " You knew you were going through the jungle...\n\n";
            cout << " You really should have bought a machette, but you didn\'t\n\n";
            
            cout << " so, all that bushwacking has left you badly battered\n\n";
            
            cout << " you\'re new health is " << player->getHealth() << "\n\n";
            
            if(player->getInventory()->checkInventory(MEDKIT) == true){
                
                cout << "at least you bought a med kit\n\n";
                
                usleep(900000);
                
                player->setHealth(player->getHealth()+25);
                
                cout << " health is restored to" << player->getHealth() << endl;
                
                
            }
            
            if (player->getHealth() < 0) {
                
                cout << " You should have bought a Machette, you might have gotten out unscathed.\n";
                
                return DEAD;
            }
        
        }
        printMenu();
        
        cout << "Input:";
        
        cin >> choice;
        
        
        switch (choice) {
                // set location to the ruins
            case 1: player->setLocation(north);
                break;
                //set location to the village
            case 2: player->setLocation(west);
                break;
            case 3: return QUIT;
                break;
                
            default: cout << "Choose one or the other!\n";
                break;
        }
        

}while (choice < 1 || choice > 3);
    
    return ALIVE;
}

void Jungle::printMenu(){
    
    cout << " \n\nMake a choice:\n\n";
    
    cout << " 1) Go to the ancient ruins of Tulalula.\n";
    cout << " 2) Visit the village. \n";
    cout << " 3) Go Home. \n\n";
    
}


