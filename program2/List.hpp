/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 31, 2016
 
 ** Title: Program 2
 
 ** Description: This program is a simple list creation application.
 
 *********************************************************************/

#include <iostream>
#include "Items.hpp"

#ifndef List_HPP
#define List_HPP

class List{
private:
    Items *item;         // This is the dynamic array of pointers
    int currentSize;
    int numItems;
public:
    List(){
        // Initialize the dynamic array to hold 4 Items
        // currentSize is the initital size of the array
        currentSize = 3;
        
        item = new Items[currentSize];
        
        // The number of items in the list to start
        numItems = 0;
        
    }
    ~List(){
        delete [] item;
        item = 0;
        
    }
    void addItem();
    void removeItem();
    void printList();
};

#endif




