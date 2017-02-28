//
//  doodleBug.h
//  Lab5
//
//  Created by James Sandoval on 2/7/16.
//
//



#include <iostream>

using namespace std;

class DoodleBug{
private:
    int** dbreed;
    int** starve;
public:
    DoodleBug();
    void doodleMove();
    void doodleBreed();
    void doodleStarve();
    ~DoodleBug();
    
};




