//
//  doodleBug.cpp
//  Lab5
//
//  Created by James Sandoval on 2/7/16.
//
//

#include "doodleBug.hpp"
#include "critter.hpp"
#include "ant.hpp"

using namespace std;


DoodleBug::DoodleBug(){
    
    // initial
    dbreed = new int*[Critter::rows];
    starve = new int*[Critter::rows];
    
    // Allocate array
    for (int i = 0; i < Critter::rows; i++) {
        
        dbreed[i] = new int[Critter::cols];
        starve[i] = new int[Critter::cols];
        
    }
    
    // Initialize the ant breed counter to 0 at start of program
    for (int j = 0; j < Critter::rows; j++) {
        for (int i = 0; i < Critter::rows; i++) {
            
            dbreed[i][j] = 0;
            starve[i][j] = 0;
        }
    }
}

DoodleBug::~DoodleBug(){
    
    for (int i = 0; i < Critter::rows; i++) {
        
        delete [] dbreed[i];
        delete [] starve[i];
    }
}

void DoodleBug::doodleMove(){
    
    // This needs to reset before each cycle
    for (int j = 0; j < Critter::rows; j++) {
        
        for (int i = 0; i < Critter::cols; i++) {
            
            bool move = false;
            bool feed = false;
            
            if (i > 0 && i < Critter::rows-1) {
                
                if (Critter::world[i][j] == 'Y'){
                    
                    //Check right
                    if(Critter::world[i+1][j] == 'O' && Critter::mirror[i][j] != 'Y'){
                        Critter::mirror[i][j] = ' ';
                        Critter::mirror[i+1][j] = 'Y';
                        starve[i+1][j] = 0;
                        starve[i][j] = 0;
                        feed = true;
                        
                    }
                    //Check left
                    else if(Critter::world[i-1][j] == 'O'){
                        Critter::mirror[i][j] = ' ';
                        Critter::mirror[i-1][j] = 'Y';
                        starve[i-1][j] = 0;
                        starve[i][j] = 0;
                        feed = true;
                    }
                }
            }
            
            // don't forget starve
            

            // if an ant is present, he needs to move somewhere
            if (Critter::world[i][j] == 'Y' && feed == false){
                
                switch (Critter::randNum(4)){ // The generator returns ints 1 - 4 //
                    case 1:
                        // Move up - world[i][j-1]
                        if(j > 0){
                            
                            if(Critter::world[i][j-1] == ' ' && Critter::mirror[i][j-1] == ' '){
                                Critter::mirror[i][j-1] = 'Y';
                                Critter::mirror[i][j] = ' ';
                                move = true;
                                dbreed[i][j-1] = dbreed[i][j] + 1;
                                starve[i][j-1] = starve[i][j] + 1;
                            }
                        }
                        break;
                        
                        // Move right - // world[i+1][j]
                    case 2:
                        
                        if(i < (Critter::rows-1)){
                            
                            if(Critter::world[i+1][j] == ' ' && Critter::mirror[i+1][j] == ' '){
                                Critter::mirror[i+1][j] = 'Y';
                                Critter::mirror[i][j] = ' ';
                                move = true;
                                dbreed[i+1][j] = dbreed[i][j] + 1;
                                starve[i+1][j] = starve[i][j] + 1;
                            }
                        }
                        break;
                        
                        // Move Down - world[i][j+1]
                    case 3:
                        if(j < (Critter::rows-1)){
                            
                            if(Critter::world[i][j+1] == ' ' && Critter::mirror[i][j+1] == ' '){
                                Critter::mirror[i][j+1] = 'Y';
                                Critter::mirror[i][j] = ' ';
                                move = true;
                                dbreed[i][j+1] = dbreed[i][j] + 1;
                                starve[i][j+1] = starve[i][j] + 1;
                            }
                        }
                        break;
                        
                        // Move left - world[i-1][j]
                    case 4:
                        if(i > 0){
                            if(Critter::world[i-1][j] == ' ' && Critter::mirror[i-1][j] == ' '){
                                Critter::mirror[i-1][j] = 'Y';
                                Critter::mirror[i][j] = ' ';
                                move = true;
                                dbreed[i-1][j] = dbreed[i][j] + 1;
                                starve[i-1][j] = starve[i][j] + 1;
                            }
                        }
                        break;
                }
                
                
                if(move == false){
                    Critter::mirror[i][j] = 'Y';
                    dbreed[i][j] += 1;
                    starve[i][j] = 1;
                }
                if(move == true){
                    dbreed[i][j] = 0;
                    starve[i][j] = 0;
                }
                
            }
            else if(Critter::world[i][j] == 'O'){
                
                Critter::mirror[i][j] = 'O';
                
            }
        }
    }
    
}

//doodle breed
void DoodleBug::doodleBreed(){

for (int j = 0; j < Critter::rows; j++) {
    
    for (int i = 0; i < Critter::cols; i++) {
        
        if(dbreed[i][j] == 8){
            
            // top
            if(j > 0 && Critter::world[i][j-1] == ' ' && Critter::mirror[i][j-1] == ' '){
               
                    Critter::mirror[i][j-1] = 'Y';
                    dbreed[i][j-1] = 0;
                    dbreed[i][j] = 0;
                
            }
            
            // right
            else if(i < (Critter::rows-1) && Critter::world[i+1][j] == ' ' && Critter::mirror[i+1][j] == ' '){
              
                    Critter::mirror[i+1][j] = 'Y';
                    dbreed[i+1][j] = 0;
                    dbreed[i][j] = 0;
                
            }
            
            // bottom
            else if(j < (Critter::rows-1) && Critter::world[i][j+1] == ' ' && Critter::mirror[i][j+1] == ' '){
               
                    Critter::mirror[i][j+1] = 'Y';
                    dbreed[i][j+1] = 0;
                    dbreed[i][j] = 0;
                
            }
            // left
            else if(i > 0 && Critter::world[i-1][j] == ' ' && Critter::mirror[i-1][j] == ' '){
            
                    Critter::mirror[i-1][j] = 'Y';
                    dbreed[i-1][j] = 0;
                    dbreed[i][j] = 0;
                
            }
        }
        
    }
}
}

void DoodleBug::doodleStarve(){
    
    for (int j = 0; j < Critter::rows; j++) {
        
        for (int i = 0; i < Critter::cols; i++) {
            
            if(starve[i][j] == 3 && Critter::world[i][j] == 'Y'){
                
                Critter::mirror[i][j] = ' ';
                    
                }
            }
            
        }
    }









