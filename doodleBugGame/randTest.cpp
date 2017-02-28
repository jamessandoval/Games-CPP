//
//  randTest.cpp
//  Lab5
//
//  Created by James Sandoval on 2/6/16.
//
//


int randNum(int);

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>

using namespace std;



int main(){
    
    int maxValue;
        
    int output;

        usleep(100);
        
    srand(rand() + time(0) + clock());
        
    output = rand() % maxValue + 1;
        
    

    return 0;
}









