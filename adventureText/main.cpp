/*
*  main.cpp
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

#include <iostream>
#include "playGame.hpp"
#include "location.hpp"

using namespace std;

/***************************************
 *
 *        Main Function
 * Description: Initial intro
 * calls game.begin() function and starts
 * a new game.
 ***************************************/


int main(){
    
    PlayGame game;
    
    cout << "                                                                 \n"
         << "                                 The                             \n"
         << "                      Search for the Lost City                   \n"
         << "                                 of                              \n"
         << "                               Paititi                           \n\n";
    //upause
    cout << "        Legend has it that deep in the Amazon rainforest         \n"
         << "      a lost Inca city of unprecedented wealth and cultural      \n"
         << "               heritage remains to be discovered.                \n\n";
    //upause
    cout << "        You\'re the descendent of a long line of explorers       \n"
         << "        and your grandfather has just revealed to you a life     \n"
         << "       long secret that he has a map to the city long thought    \n"
         << "                           only as myth.                         \n\n";
    //upause
    cout << "     Unfortunately, he\'s just given this map to you on his death \n"
         << "                  bed and with little back story.                \n\n";
    
    cout << "                      His dying words were...                    \n\n";
    
    cout << "       \"It\'s my dying wish that you find this city and reveal its \n"
         << "    rich cultural heritage to the world, you\'ll be rich beyond your\n"
         << "          wildest dreams, and in turn you will have discovered\n"
         << "             the lost secrets of a forgotten civilization.\"\n\n";
    
    cout << "Press Enter...";
    cin.get();
    clearScreen();
    
    game.begin();
    
    return 0;
}



