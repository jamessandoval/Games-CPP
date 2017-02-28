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
 *                      Die::rolldie
 *  The rolldie function emulates the regular rolling of dice by
 *  using a random number gerenator, and the max value of the die
 *  is passed as a parameter and the result is returned as an int.
 *
 *****************************************************************/

#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "die.hpp"


int Die::rollDie(int dieValue){
    
    int die;
    
    // Just a little delay to increase the randomability of the generator
    usleep(100000);
    
    // Get the system time and processor time to ensure quick random number generator
    unsigned seed = time(0) + clock();
    
    // Seed the random number generator
    srand(seed);
    
    die = (rand() % (dieValue - 2)) + 1;
    
    return die;
}
