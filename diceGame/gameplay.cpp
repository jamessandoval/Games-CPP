/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 20, 2016
 
 ** Title: Lab 3
 
 ** Description: This program is an implementation of a simple die game using
 the design from lab 2 and specifically shows a simple instance of inheritance
 and the "is-a", and "has-a" relationships.
 
 *********************************************************************/

/*****************************************************************
 *
 *                     GamePlay::play()
 *  The Gameplay function is where the actual logic for a round is
 *  implemented. If the user chose a loaded die, or a regular die,
 *  the appropriate function will be called, then the result printed,
 *  Finally after the game is complete, the final verdict will print.
 *
 *****************************************************************/

#include "gameplay.hpp"
#include "LoadedDie.hpp"
#include <iostream>

void GamePlay::play(){
    
    // create a loadedDie obbject to access rollLoadedDie function
    LoadedDie ldObject;
    // Implement Gameplay and iterate through rounds
    for (int i=0; i<rounds; i++) {
        
        if(loadedDie1 == false){
            
            player1Score += die1.rollDie(die1.getDie());
        }
        
        else if(loadedDie1 == true){
            
            player1Score += ldObject.rollLoadedDie(die1.getDie());
        }
        
        if(loadedDie2 == false){
            player2Score += die2.rollDie(die2.getDie());
        }
        
        else if(loadedDie2 == true){
            
            player2Score += ldObject.rollLoadedDie(die2.getDie());
        }
        
        std::cout << "Round " << i+1 << ":" << std::endl;
        std::cout << "PLayer 1 Score is:" << player1Score << std::endl;
        std::cout << "Player 2 Score is:" << player2Score << "\n" << std::endl;
    }
    
    if (player1Score > player2Score) {
        
        std::cout << "Congrats Player 1, you've won the game with a score of: " << player1Score << "\n" << std::endl;
        
    }else if(player1Score < player2Score){
        
        std::cout << "Congrats Player 2, you've won the game with a score of: " << player2Score << "\n" << std::endl;
    }
    else
        std::cout << "You've tied the game with a score of: " << player1Score << "\n" << std::endl;
    
    
    std::cout << "Player 1's die size was " << die1.getDie() << std::endl;
    
    if(loadedDie1 == false){
        std::cout << "Player 1 used a regular die" << std::endl;
    }
    else if(loadedDie1 == true){
        std::cout << "Player 1 used a Loaded die" << std::endl;
    }
    
    std::cout << "Player 2's die size was " << die2.getDie() << std::endl;
    
    if(loadedDie2 == false){
        std::cout << "Player 2 used a regular die" << std::endl;
    }
    else if(loadedDie1 == true){
        std::cout << "Player 2 used a Loaded die\n" <<  std::endl;
    }
}












