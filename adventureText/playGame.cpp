/*
 *  playGame.cpp
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
#include <string>

#include "playGame.hpp"
#include "player.hpp"
#include "location.hpp"
#include "city.hpp"
#include "jungle.hpp"
#include "store.hpp"
#include "ruins.hpp"
#include "village.hpp"
#include "cave.hpp"
#include "lostCity.hpp"

using namespace std;

PlayGame::PlayGame(){
    
    // create new player
    player = new Player();
    
    // create locales
    city = new City();
    jungle = new Jungle();
    store = new Store();
    village = new Village();
    ruins = new Ruins();
    cave = new Cave();
    lostCity = new LostCity();
    
//city locales
    city->setNorth(jungle);
    city->setEast(store);
 //store locales
    store->setWest(city);
    store->setNorth(jungle);
 //jungle locales
    jungle->setNorth(ruins);
    jungle->setWest(village);
 //ruins locales
    ruins->setSouth(village);
    ruins->setNorth(cave);
 //village locales
    village->setWest(cave);
    village->setEast(ruins);
 //cave locales
    cave->setEast(village);
    cave->setNorth(lostCity);
    cave->setWest(city);
    cave->setSouth(ruins);
 //lost city locales
   lostCity->setSouth(cave);
    
 // starting location
    player->setLocation(city);
    
}
/********************************************************
 *        Name: begin();
 * Description: 1st page after intro, starts gameplay
 * Parameters: None
 * Returns: None
 ********************************************************/

void PlayGame::begin(){
    
        cout << "   You\'re first destination is Cuzco, Peru. You\'re armed only with a map  \n"
             << "    and since you\'re family is part of a long line of explorers you only   \n"
             << " carry gold coins as currency. So you\'ll need to find a shop that takes them. \n\n";
    
        cout << "       You\'ll start health with 100 points and you've got 25 gold coins.        \n"
             << "                 Oh, and before I forget, you have 15 minutes.                   \n\n";
    
        cout << "Are you ready to go? If so...\n\nPress Enter...\n" << endl;
        cin.get();
    
        clearScreen();
    
        play();
}

/********************************************************
 *        Name: play()
 * Description: sets new location and determines gamestatus
 * after each round.
 * Parameters: None
 * Returns: None
 ********************************************************/
           
void PlayGame::play(){
    
    
    Location *currentLocation;
    PlayerStatus status;
    
    do{
        
        currentLocation = player->getLocation();
        
        status = currentLocation->enterLocation(player);
        
    }while (status == ALIVE);
    
    if(status == WON){
        
        PlayGame::win();
    }
    
    else if(status == DEAD){
        
        PlayGame::lose();
        
    }else if(status == NO_TIME ){
        
        PlayGame::noMoreTime();
    }else{
    
    PlayGame::quitter();
        
    }
}
/********************************************************
 *        Name: win()
 * Description: prints win message
 * Parameters: None
 * Returns: None
 ********************************************************/

void PlayGame::win(){
    
    cout << "                            CONGRATULATIONS!!!                                  \n\n"
    
         << "       You\'ve successfully found the lost city of Paititi and cemented          \n"
         << "         your family name into the history books along with Columbus             \n"
         << "          and Hiram Bingham.You can choose to keep your immense new              \n"
         << "            found Wealth, or donate it to museums so scientists can              \n"
         << "                        study it for years to come.                              \n\n";

}
/********************************************************
 *        Name: lose()
 * Description: prints lose message
 * Parameters: None
 * Returns: None
 ********************************************************/

void PlayGame::lose(){
    
    cout << "\n\n    Sorry, you\'ve failed...all you had to do was find the lost city.         \n"
         << "                         and unfortunately your...                                \n\n";
    
    usleep(900000);
    
    cout << "                                  DEAD.                                          \n\n\n";
    
}
/********************************************************
 *        Name: noMoreTime()
 * Description: prints noMoreTime message
 * Parameters: None
 * Returns: None
 ********************************************************/

void PlayGame::noMoreTime(){
    
    cout << "\n\n    Sorry, you\'ve failed...all you had to do was find the lost city.         \n"
    << "                           and unfortunately your...                                 \n\n";
    
    usleep(900000);
    
    cout << "                               Out of Time.                                      \n\n\n";
    
}
/********************************************************
 *        Name: quitter()
 * Description: prints quitter message
 * Parameters: None
 * Returns: None
 ********************************************************/

void PlayGame::quitter(){
    
    cout << "\n\n    Sorry, you\'ve failed...all you had to do was find the lost city.         \n"
    << "                          and unfortunately your...                            \n\n";
    
    usleep(900000);
    
    cout << "                                a Quitter.                                        \n\n\n";
    
}







