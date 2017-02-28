//
//  ant.cpp
//  Lab5
//
//  Created by James Sandoval on 2/5/16.
//
//

#include <iostream>
#include "critter.hpp"
#include "ant.hpp"

using namespace std;
Ant::Ant(){
    
    // initial
    abreed = new int*[Critter::rows];
    
    // Allocate array
    for (int i = 0; i < Critter::rows; i++) {
        
        abreed[i] = new int[Critter::cols];
    }
    
    // Initialize the ant breed counter to 0 at start of program
    for (int j = 0; j < Critter::rows; j++) {
        for (int i = 0; i < Critter::rows; i++) {
            
            abreed[i][j] = 0;
        }
    }
}

Ant::~Ant(){
    
    for (int i = 0; i < Critter::rows; i++) {
        
       delete [] abreed[i];
    }
}

void Ant::antMove(){
    
    // This needs to reset before each cycle
    for (int j = 0; j < Critter::rows; j++) {
        
        for (int i = 0; i < Critter::cols; i++) {
            
         bool move = false;
            // if an ant is present, he needs to move somewhere
            if (Critter::world[i][j] == 'O'){
              
                switch (Critter::randNum(4)){ // The generator returns ints 1 - 4 //
                    case 1:
                         // Move up - world[i][j-1]
                        if(j > 0){
                            
                            if(Critter::world[i][j-1] == ' ' && Critter::mirror[i][j-1] == ' '){
                            Critter::mirror[i][j-1] = 'O';
                            Critter::mirror[i][j] = ' ';
                            move = true;
                            abreed[i][j-1] = abreed[i][j] + 1;
                            }
                        }
                        break;
           
                        // Move right - // world[i+1][j]
                    case 2:
                       
                        if(i < (Critter::rows-1)){
                            
                             if(Critter::world[i+1][j] == ' ' && Critter::mirror[i+1][j] == ' '){
                            Critter::mirror[i+1][j] = 'O';
                            Critter::mirror[i][j] = ' ';
                            move = true;
                            abreed[i+1][j] = abreed[i][j] + 1;
                             }
                        }
                        break;
              
                        // Move Down - world[i][j+1]
                    case 3:
                        if(j < (Critter::rows-1)){
                            
                             if(Critter::world[i][j+1] == ' ' && Critter::mirror[i][j+1] == ' '){
                            Critter::mirror[i][j+1] = 'O';
                            Critter::mirror[i][j] = ' ';
                            move = true;
                            abreed[i][j+1] = abreed[i][j] + 1;
                             }
                        }
                        break;
                        
                        // Move left - world[i-1][j]
                    case 4:
                        if(i > 0){
                                 if(Critter::world[i-1][j] == ' ' && Critter::mirror[i-1][j] == ' '){
                            Critter::mirror[i-1][j] = 'O';
                            Critter::mirror[i][j] = ' ';
                            move = true;
                            abreed[i-1][j] = abreed[i][j] + 1;
                            }
                        }
                        break;
                }
               
                
                if(move == false){
                        Critter::mirror[i][j] = 'O';
                        abreed[i][j] = 1;
                    }
                if (move == true) {
                    abreed[i][j] = 0;
                }

               
            }
            else if(Critter::world[i][j] == 'Y'){
                
                Critter::mirror[i][j] = 'Y';
                
            }
        }
    }
}

void Ant::antBreed(){
    
for (int j = 0; j < Critter::rows; j++) {
    
    for (int i = 0; i < Critter::cols; i++) {


        if(abreed[i][j] == 3){
    
            // top
            if(j > 0 && Critter::world[i][j-1] == ' ' && Critter::mirror[i][j-1] == ' '){
                    Critter::mirror[i][j-1] = 'O';
                    abreed[i][j-1] = 0;
                    abreed[i][j] = 0;
                
            }

    
            // right
            else if(i < (Critter::rows-1) && Critter::world[i+1][j] == ' ' && Critter::mirror[i+1][j] == ' '){
                    Critter::mirror[i+1][j] = 'O';
                    abreed[i+1][j] = 0;
                    abreed[i][j] = 0;
                
            }
    
            // bottom
            else if(j < (Critter::rows-1) && Critter::world[i][j+1] == ' ' && Critter::mirror[i][j+1] == ' '){
                    Critter::mirror[i][j+1] = 'O';
                    abreed[i][j+1] = 0;
                    abreed[i][j] = 0;
            }
            // left
            else if(i > 0 && Critter::world[i-1][j] == ' ' && Critter::mirror[i-1][j] == ' '){
                    Critter::mirror[i-1][j] = 'O';
                    abreed[i-1][j] = 0;
                    abreed[i][j] = 0;
                
            }
        }

     }
  }

}


