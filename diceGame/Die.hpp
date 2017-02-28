/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 20, 2016
 
 ** Title: Lab 3
 
 ** Description: This program is an implementation of a simple die game using
 the design from lab 2 and specifically shows a simple instance of inheritance
 and the "is-a", and "has-a" relationships.
 
 *********************************************************************/

// Define Die Class


class Die{
protected:
    int die;
public:
    Die(int d){
        die = d;
    }
    void setDie(int d){
        die = d;
    }
    int getDie(){
        return die;
    }
    int rollDie(int);
    
};