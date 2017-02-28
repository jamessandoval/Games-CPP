/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 20, 2016
 
 ** Title: Lab 3
 
 ** Description: This program is an implementation of a simple die game using
 the design from lab 2 and specifically shows a simple instance of inheritance
 and the "is-a", and "has-a" relationships.
 
 *********************************************************************/

#include <iostream>
#include "gameplay.hpp"


/*****************************************************************
 *
 *                     Function Main()
 *  The main function houses the initial greeting, and initial input
 *  from the user. After the user completed inputting information,
 *  the program then calls the game.play() function.
 *
 *****************************************************************/

int main(){
    
    int rounds, p1Die, p2Die;
    char dieChoice;
    bool ldie1, ldie2;
    
    // This class won't be used unless both users have loaded die
    
    std::cout << "*****************************************************************************" << std::endl;
    std::cout << "*****************************************************************************" << std::endl;
    std::cout << "**********                                                         **********" << std::endl;
    std::cout << "******                       Die Challenger 3000                       ******" << std::endl;
    std::cout << "**********                                                         **********" << std::endl;
    std::cout << "*****************************************************************************" << std::endl;
    std::cout << "*****************************************************************************" << std::endl;
    
    std::cout << "\n\n  Welcome to Die Challenger 3000" << std::endl;
    
    // Go ahead and use input validation this time
    
    std::cout << "How many rounds do you want to play? \nRounds: ";
    std::cin >> rounds;
    std::cout << "How many sides will player 1's die have? \nPlayer 1 Sides:" << std::endl;
    std::cin >> p1Die;
    
    std::cout << "Is the die loaded? (y or n):";
    std::cin >> dieChoice;
    
    // logic to determine if die is loaded or not
    if(dieChoice == 'y' || dieChoice == 'Y'){
        
        ldie1 = true;
    }else{
        ldie1 = false;
    }
    
    std::cout << "How many sides will player 2's die have? \nPlayer 2 Sides:" << std::endl;
    std::cin >> p2Die;
    
    std::cout << "Is the die loaded? (y or n):";
    std::cin >> dieChoice;
    // logic to determine if die is loaded or not
    if(dieChoice == 'y' || dieChoice == 'Y'){
        
        ldie2 = true;
    }
    else{
        ldie2 = false;
    }
    
    GamePlay game(rounds,p1Die,p2Die,ldie1,ldie2);
    
    std::cout << "\nLet's Play!\n" << std::endl;
    
    game.play();
    
    
    return 0;
}


