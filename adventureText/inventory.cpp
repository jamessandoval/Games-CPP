/*
 *  inventory.cpp
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

#include "inventory.hpp"

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

using namespace std;

/*********************************************
 *           Name: addItem
 *    Description: add an item to inventory
 *     Parameters: Item
 *********************************************/

void Inventory::addItem(Item itemName)
{
    items.push_back(itemName);
}

/*********************************************
 *           Name: removeItem
 *    Description: remove an item from inventory
 *     Parameters: Item
 *********************************************/

void Inventory::removeItem(Item itemName)
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i) == itemName)
            items.erase(items.begin() + i);
    }
}

/********************************************************
*          Name: useItem
*   Description: displays the player's inventory, and
*   let's them choose an item
    returns: item
*   Parameters: None
********************************************************/

Item Inventory::useItem(){
    
    int id;
    
    int choice;
    
    if (items.size() == 0) {
        
        cout << "Your inventory is empty.\n" << endl;
        
        return NO_ITEM;
    }
    
    
    do{
        
        // Print Items
        cout << "you have: \n";
        
        for (id = 0; id < items.size(); id++) {
            
            cout << "   " << id + 1 << ". ";
            printItem(items.at(id));
            
        }
        
        cout << "   " << id +1 << ". Go Back\n"
             << "     >> ";
        
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            choice = -1;
        }
        
        cin.ignore(999, '\n');
        
        if (choice == 1 || choice > items.size() + 1)
        {
            cout << " You need to pick an item." << endl;
            
        }
        
    }while (choice < 1 || choice > items.size() +1);
        
        
        if(choice <= items.size()){
            
        return items.at(choice -1);
        }
        
        return NO_ITEM;
    }


/********************************************************
*          Name: getSize
*   Description: Get the size of the inventory
*   Parameters: None
*   returns: size
********************************************************/
    
int Inventory::getSize(){
        
        return items.size();
        
}
/********************************************************
 *          Name: checkInventory
 *   Description: Checks for an item
 *    Parameters: Item
 *       returns: bool if found
 ********************************************************/

bool Inventory::checkInventory(Item itemName){
    
    for (int i = 0; i < items.size(); i++) {
        
        if (itemName == items.at(i)) {

            return true;
        }
    }
    return false;
}
    
/********************************************************
*          Name: printItem
*   Description: prints the item name and description
*    Parameters: Item
********************************************************/

void Inventory::printItem(Item itemName){
    
    switch(itemName){
            
        case KNIFE:
            cout << "KNIFE               Every explorer has one...and this one is no ordinary knife.\n";
            break;
            
        case MACHETTE:
            cout << "MACHETTE            In the jungle...you'/re gonna need this bad boy.\n";
            break;
            
        case PISTOL:
            cout << "PISTOL              A small arm for serious protection.\n";
            break;
            
        case COMPASS:
            cout << "COMPASS             This will help you find your way.\n";
            break;
            
        case TOAD:
            cout << "TOAD                This special toad might just turn out to be useful.\n";
            break;
            
        case ELIXIR:
            cout << "ELIXIR              Your only hope for survival if your bitten by the Assasin bug.\n";
            break;
            
        case MEDKIT:
            cout << "MEDKIT              Could save your life if used properly.\n";
            break;
            
        case STONE:
            cout << "PANTHER STONE       This legendary stone is the only way to earn the villagers respect.\n";
            break;
            
        case NO_ITEM:
            break;
            
    }

}









