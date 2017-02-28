/*
 *  store.cpp
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

#include "store.hpp"
#include <iostream>
#include "inventory.hpp"
#include "player.hpp"
#include "playGame.hpp"


using namespace std;

// virtual enterLocation Function for store
PlayerStatus Store::enterLocation(Player *player){
    
    if(player->outOfTime()){
        
        return NO_TIME;
        
    }
    
    int choice;
    Item itemName;
    
    int buyChoice;
    
    do{
        
        // use printMenu when you have this working.
        
        clearScreen();
        
        cout << "So, you\'ve made it to the store, hopefully unscathed.\n"
             << "It\'s dangerous out here in South America and you\'re\n"
             << "going to need some supplies." << endl;
        
        cout << "Press Enter...\n";
        cin.get();
        clearScreen();
        
        cout << "*******************************************************************************\n"
             << "************                                                       ************\n"
             << "******                      PABLOS GENERAL STORE                         ******\n"
             << "***                                                                         ***\n"
             << "*                                    OF                                       *\n"
             << "***                                                                         ***\n"
             << "******                   THINGS YOU MIGHT JUST NEED                      ******\n"
             << "************                                                       ************\n"
             << "*******************************************************************************\n";
        
        do{
            
        cout << " \n**** Choose an item to Purchase: **** \n\n"
             << " 1) Knife --------------- 5 Gold Coins \n"
             << " 2) Machette ------------ 3 Gold Coins \n"
             << " 3) Pistol -------------- 5 Gold Coins \n"
             << " 4) Compass ------------- 2 Gold Coins \n"
             << " 5) Med Kit ------------- 2 Gold Coins \n"
             << " 6) Done Shopping ";
            
            
        cout << "\n\nMake a purchase or go on your way!\n";
            
        cout << "Input:";
            
        cin  >> buyChoice;
            
            clearScreen();
            
            switch (buyChoice) {
                case 1: buyItem(KNIFE, player);
                    break;
                case 2: buyItem(MACHETTE, player);
                    break;
                case 3: buyItem(PISTOL, player);
                    break;
                case 4: buyItem(COMPASS, player);
                    break;
                case 5: buyItem(MEDKIT, player);
                    break;
                case 6: cout << "Finish Shopping!\n";
                    break;
                default:
                    break;
            }
            
            
        if(player->getGoldCoins() == 0){
                
            cout << "\n\n...Well, you\'re out of funds....so get out!\n";
        }
            
        }while(buyChoice != 6);
        
        cout << "\n\nDo you want to go back to the City or \n"
             << "are you ready for the jungle?\n\n";
        
        printMenu();
        
        cout << "Input:";
        
        cin >> choice;
    
        clearScreen();
        
        switch (choice) {
                // set location back to the city
            case 1: player->setLocation(west);
                break;
                //set location to the jungle
            case 2: player->setLocation(north);
                break;
            case 3: return QUIT;
                break;
                
            default: cout << "Make another choice.\n";
                break;
        }
        
    }while (choice < 1 && choice > 3);
    
    return ALIVE;
}
/*********************************************
 *           Name: printMenu()
 *    Description: prints custome menu
 *     Parameters: None
 *********************************************/


void Store::printMenu(){
    
    cout << " Where do you want to go next?\n\n";
    cout << " 1) Back to the city.\n";
    cout << " 2) Head to the jungle.\n\n";
    cout << " 3) Go Home.";
    
}
/*********************************************
 *           Name: buyItem()
 *    Description: checks inventory and funds
 *  and buys item if able
 *     Parameters: item, player
 *********************************************/

void Store::buyItem(Item item, Player *shopper){
    
    // This might just create  a new object.
    // So the solution will be to make this a friend function
    // and allow it to access the private member of the playGame class.
    
    int cost;
    
    if (item == KNIFE) {
        cost = 5;
        
        if(shopper->getInventory()->checkInventory(KNIFE) == false){
                
            if(checkFunds(cost, shopper) == true){
                
            shopper->getInventory()->addItem(KNIFE);
                
            cout << "\nYou just bought a knife.\n";
            cout << "Might just be the only thing you need.\n";
            }
        }
        else{
            
            cout << "You already have this item.\n";
        }
        
    }
    if (item == MACHETTE) {
        cost = 3;
        
        if(shopper->getInventory()->checkInventory(MACHETTE) == false){
            
            if(checkFunds(cost, shopper) == true){
                
                shopper->getInventory()->addItem(MACHETTE);
                
                cout << "\nYou just bought an old rusty machette.\n";
            }
        }
        else{
            
            cout << "You already have this item.\n";
        }

    }
    if (item == PISTOL) {
        cost = 5;
        
        if(shopper->getInventory()->checkInventory(PISTOL) == false){
            
            if(checkFunds(cost, shopper) == true){
                
                shopper->getInventory()->addItem(PISTOL);
                
                cout << "\nYou just bought a pistol.\n";
                cout << "...a water pistol\n";
            }
        }
        else{
            
            cout << "You already have this item.\n";
        }
    }
    if (item == COMPASS) {
        cost = 2;
        
        if(shopper->getInventory()->checkInventory(COMPASS) == false){
            
            if(checkFunds(cost, shopper) == true){
                
                shopper->getInventory()->addItem(COMPASS);
                
                cout << "\nYou just bought a compass.\n";
                cout << "...Does this thing even work?\n";
            }
        }
        else{
            
            cout << "You already have this item.\n";
        }
    }

       if (item == MEDKIT) {
        cost = 2;
           
           if(shopper->getInventory()->checkInventory(MEDKIT) == false){
               
               if(checkFunds(cost, shopper) == true){
                   
                   shopper->getInventory()->addItem(MEDKIT);
                   
                   cout << "\nYou just bought a medkit.\n";
                   cout << "...this really might be the only thing you should buy...maybe.\n";
               }
           }
           else{
               
               cout << "You already have this item.\n";
           }
    }
    
    usleep(900000);
    
    
}
/*********************************************
 *           Name: checkFunds()
 *    Description: compares available funds
 *   to purchase an item and buys if available
 *     Parameters: item, player
 *********************************************/


bool Store::checkFunds(int cost, Player *shopper){
    
    int money = shopper->getGoldCoins();
    
    if(money >= cost){
        
        int newFunds;
        
        newFunds = money - cost;
        
        shopper->setGoldCoins(newFunds);
        
        cout << "\nGold coins left over: " << newFunds << endl;
        
        return true;
        
    }
    
    else{
        
        cout << "\n\nSorry, you don\'t have enough funds.\n";
        
        return false;
    }
    


}




















