//
//  Critter.h
//  Lab5
//
//  Created by James Sandoval on 2/3/16.
//
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>


class Critter{
    
        friend class Ant;
        friend class Doodlebug;
    
    public:
        static char** world;
        static char** mirror;
        static int rows;
        static int cols;
    
    public:
        Critter(int r, int c);
        ~Critter();
        void printWorld();
        void copyWorld();
        void loadWorld(int, int);
        static int randNum(int num);
};