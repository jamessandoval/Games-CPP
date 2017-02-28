//
//  Critter.cpp
//  Lab5
//
//  Created by James Sandoval on 2/3/16.
//
//


#include "Critter.hpp"

using namespace std;

int Critter::cols = 0;
int Critter::rows = 0;

char** Critter::world = NULL;
char** Critter::mirror = NULL;

Critter::Critter(int r, int c){
    
    rows = r;
    cols = c;
    
    // Initialize the arrays
    world = new char*[rows];
    mirror = new char*[rows];
    
    for (int i = 0; i < rows; i++) {
        
        world[i] = new char[cols];
        mirror[i] = new char[cols];
    }
    
    // Allocate the array
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < rows; i++) {
            
            world[i][j] = ' ';
            mirror[i][j] = ' ';
        }
    }
}

Critter::~Critter(){

    // Deallocate the arrays
    for (int i = 0; i < rows; i++) {
        
        delete [] world[i];
        delete [] mirror[i];
    }
}


void Critter::printWorld(){
    
    int specialAntCount = 0;
    int specialDoodleCount = 0;
    
    // Print the array after its been initialized
    for (int j = 0; j < rows; j++) {
        
        for (int i = 0; i < cols; i++) {
            
            if((i % cols == 0) && (j != 0)){
                cout << endl;
            }
            
            cout << world[i][j];
            cout << "  ";
            
            if (Critter::world[i][j] == 'O') {
                
                specialAntCount++;
            }
            if (Critter::world[i][j] == 'Y') {
                
                specialDoodleCount++;
            }
        }
    }
    cout << endl;
    
    cout << "Output for printWorld:" << endl;
    cout << "The Ant number is: " << specialAntCount << endl;
    cout << "The Doodle Number is:" << specialDoodleCount << endl;

}
void Critter::loadWorld(int ants, int doodlebugs){
    
    int antCount = 0;
    int doodleCount = 0;
    
    int totalCells = rows * cols;
    
    for (int j = 0; j < rows; j++) {
        
        for (int i = 0; i < cols; i++) {
            
            // Basically, Flip a coin to determine whether to set and to set a somewhat even distrbiution
            if ((randNum(3) == 1) && (antCount < ants)){
                world[i][j] = 'O';
                antCount++;
                
            }
            else if(randNum(20) == 1 && doodleCount < doodlebugs){
                world[i][j] = 'Y';
                doodleCount++;
           }
          
            else{
                
                world[i][j] = ' ';
            }
        }
    }
    
    cout << "Output for loadWorld: ants:" << antCount << "doodlebugs:" << doodleCount << endl;
}
void Critter::copyWorld(){
    
    for (int j = 0; j < rows; j++) {
        
        for (int i = 0; i < cols; i++) {
        
            world[i][j] = mirror[i][j];
        }

     }
}


int Critter::randNum(int maxValue){
    
    int output;
    
      usleep(10);
    
            srand(rand() + time(0) + clock());
    
        output = rand() % maxValue + 1;
    
    return output;
    
}

