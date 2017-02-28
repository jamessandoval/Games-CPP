/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 20, 2016
 
 ** Title: Lab 3
 
 ** Description: This program is an implementation of a simple die game using
 the design from lab 2 and specifically shows a simple instance of inheritance
 and the "is-a", and "has-a" relationships.
 
 *********************************************************************/

// define Gameplay class

#include "Die.hpp"


class GamePlay{
private:
    int  rounds;
    int  player1Score;
    int  player2Score;
    Die  die1;
    Die  die2;
    bool loadedDie1;
    bool loadedDie2;
    
public:
    GamePlay(int rounds, int die1, int die2, bool ld1, bool ld2):
    die1(die1),
    die2(die2)
    {
        this->rounds = rounds;
        player1Score = 0;
        player2Score = 0;
        loadedDie1 = ld1;
        loadedDie2 = ld2;
    }
    void play();
};
