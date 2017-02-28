/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 20, 2016
 
 ** Title: Lab 3
 
 ** Description: This program is an implementation of a simple die game using
 the design from lab 2 and specifically shows a simple instance of inheritance
 and the "is-a", and "has-a" relationships.
 
 *********************************************************************/

// Define LoadedDie Class, a child of Die

class LoadedDie : public Die{
    
public:
    LoadedDie() : Die(die){
        
    }
    int rollLoadedDie(int);
};