//
//  main.cpp
//  Lab5
//
//  Created by James Sandoval on 2/3/16.
//
//


#include <iostream>
#include <cstdlib>     // For the random generator
#include <unistd.h>    // For the utime function
#include "critter.hpp"
#include "ant.hpp"
#include "doodleBug.hpp"

using namespace std;

int main(){
    
    Critter world1(20,20);
    Ant colony1;
    DoodleBug hive1;
    
    world1.loadWorld(100,5);
    world1.printWorld();
    
    
    cout << "The moving function:" << endl;
    for(int i = 0; i < 1000; i++)  {
    
    colony1.antMove();
    colony1.antBreed();
    world1.copyWorld(); // you can just use this at the end of the move function
    hive1.doodleMove();
    hive1.doodleBreed();
    hive1.doodleStarve();
    world1.copyWorld(); // you can just use this at the end of the move function
    world1.printWorld();
        
    usleep(10000);
    
    
    }
    
    return 0;
}

