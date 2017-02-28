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
 *                      Die::rollLoadedDie
 *  The rolldie function emulates the Loaded rolling of dice by
 *  using a random number generator, the max value of the die
 *  is passed as a parameter and the result is returned as an int.
 *  The loaded functionality is implemented by comparing the random
 *  number result with half of the size of the max value, and if it
 * is found to be greater, the max value will be used.
 *
 *****************************************************************/
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "Die.hpp"
#include "LoadedDie.hpp"


int LoadedDie::rollLoadedDie(int dieValue){
    
    int die;
    
    // Just a little delay to increase the randomness of the generator
    usleep(100000);
    // Get the system time and processor time to ensure quick random number generator
    unsigned seed = time(0) + clock();
    
    // Seed the random number generator
    srand(seed);
    
    // Roll the Dice
    die = (rand() % (dieValue - 2)) + 1;
    
    // For the loaded die, if it's greater than 1/2, then its = to max value
    if(die >= dieValue/2){
        die = dieValue;
    }
    
    return die;
}
