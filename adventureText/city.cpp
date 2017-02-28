/*
 *  city.cpp
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

#include "city.hpp"
#include "location.hpp"
#include <iostream>
#include "jungle.hpp"


using namespace std;
// virtual enterLocation Function for city
PlayerStatus City::enterLocation(Player *player){
    
    // check timer
    if(player->outOfTime()){
        
        return NO_TIME;
        
    }

    int choice;
    Item itemName;
    
do{
    
    // city location text:
    
    cout << "            You\'ve just arrived in Cusco, Peru                \n"
         << "        where the beginning of your journey starts.            \n\n";
    
    cout << "     Legend has it that the natives in a village deep          \n"
         << "  in the Amazon jungle know exactly where the lost city is,    \n"
         << "  but they\'re sworn to secrecy, unless you can prove you      \n"
         << "                        are worthy.                            \n\n"
    
         << "  Before you set out on your way your going to need to go to   \n"
         << "           the store to pick up a few supplies.                \n\n"
    
         << "  But if you think you can rough it without supplies you might \n"
         << "                    be able to make it...                      \n\n";
    
    
        cout << "Press Enter...\n";
    
        cin.get();
        cin.ignore();
    
        clearScreen();
    
        if(rolldie() < 50){
            
        cout << "*#* Hate to tell you this, but you\'ve been robbed and beaten up. *#*\n\n";
            
            
            player->setHealth(player->getHealth() - 25);
            player->setGoldCoins(player->getGoldCoins() - (player->getGoldCoins()*.20));
            
            cout << " health takes 25 damage, health is now " << player->getHealth() << endl;
            
            if(player->getInventory()->checkInventory(MEDKIT) == true){
                
                usleep(900000);
                
                cout << "\n\ngood thing you bought a med kit\n\n";
                
                usleep(900000);
                
                player->setHealth(player->getHealth()+25);
                
                cout << " health is restored to" << player->getHealth() << endl;
                
                
            }
            
            if(player->getHealth() < 0){
                
                return DEAD;
            }
            
            
            cout << " Some gold was taken, you now have " << player->getGoldCoins() << endl;
            
            cout << " Despite your minor setback you\'re still in good shape.\n\n";
            
            cout << " Lets get out of here!\n\n";
        
        }
    
    printMenu();
    
    cout << "Input:";
    
    cin >> choice;
    
    switch (choice) {
            // set location to the jungle
        case 1: player->setLocation(north);
            break;
            //set location to the store
        case 2: player->setLocation(east);
            break;
        case 3: return QUIT;
            break;
            // special instructions for grader
        case 4: clearScreen();
                cout << " Instructions: \n\n";
            
                cout << " The player must travel to the locations and acquire specific items\n"
                     << " in orderto progress.\n\n"
            
                     << " Instructions(must be done in order):\n"
                     << " 1. Go to the store and purchase a machette and a med kit.\n"
                     << " 2. Go to ruins prior to visiting village to acquire\'s \"Panther Stone\"\n"
                     << " 3. Visit Village and obtain \"Magic Toad\n"
                     << " 4. Proceed to cave, and automaticlly travel to lost city to win game.\n\n";
            
            cout << "Press Enter to continue...\n";
            
            cin.get();
            cin.ignore();
            
            clearScreen();
            break;
        
        default: cout << "You have two choices, either the jungle or the store. Make a choice!" << endl;
    }
    
    
}while (choice < 1 || choice > 3);
    
    return ALIVE;
}

void City::printMenu(){
    
    cout << "Make a choice:\n\n";
    cout << " 1) Head to the jungle.\n";
    cout << " 2) Visit the store.\n";
    cout << " 3) Go Home.\n";
    cout << " 4) Player Goal/Game Solution.\n\n";
    

}





