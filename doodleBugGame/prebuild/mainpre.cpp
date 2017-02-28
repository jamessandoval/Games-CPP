//
//  main.cpp
//  Lab5
//
//  Created by James Sandoval on 2/3/16.
//
//

int randNum(int);


#include <iostream>
// This is for the random number gen
#include <cstdlib>
#include <unistd.h>

using namespace std;


int main(){
    int rows = 20;
    int cols = 20;
    
    char** world;
    char** mirror;
    int** abreed;
    int** dbreed;
    int** starve;
    
    // Initialize the arrays
    world = new char*[rows];
    mirror = new char*[rows];
    abreed = new int*[rows];
    dbreed = new int*[rows];
    starve = new int*[rows];
    
    for (int i = 0; i < rows; i++) {
        
        world[i] = new char[cols];
        mirror[i] = new char[cols];
        abreed[i] = new int[cols];
        dbreed[i] = new int[cols];
        starve[i] = new int[cols];
        
    }
    // Allocate the array
    for (int j = 0; j < rows; j++) {
        for (int i = 0; i < rows; i++) {
            world[i][j] = ' ';
            mirror[i][j] = ' ';
            abreed[i][j] = 0;
            dbreed[i][j] = 0;
            starve[i][j] = 0;
        }
    }
        
    // initialize the cells with 100 ants and 5 doodlebugs.
    
    int antCount = 0;
    int doodleCount = 0;
    int ants = 100;
    int doodlebugs = 5;
    
    int totalCells = rows * cols;
    
    for (int j = 0; j < rows; j++) {
        
        for (int i = 0; i < cols; i++) {
            
            // Basically, Flip a coin to determine whether to set and to set a somewhat even distrbiution
            if ((randNum(7) == 1 && antCount < ants) || ((antCount % (totalCells / ants) == 0) && (antCount < ants)) ){
                world[i][j] = 'O';
                antCount++;
                
            }
            else if((randNum(22) == 1 && doodleCount < doodlebugs)){
                world[i][j] = 'Y';
                doodleCount++;
                
            }
            else{
                
                world[i][j] = ' ';
                
            }
            
        }
    }
    
    // initialize the cells with ants
    
    for (int i = 0; i < 100; i++) {
   
    // Print the array after its been initialized
    for (int j = 0; j < rows; j++) {
        
        for (int i = 0; i < cols; i++) {
            
            if((i % cols == 0) && (j != 0)){
                cout << endl;
            }
            
            cout << world[i][j];
            cout << "  ";
        }
    }
    
    cout << endl;
    

    cout << "The doodle Count is: " << doodleCount << endl;
    
    cout << "The ant count is: " << antCount << endl;
    // Print the array after its been initialized

    // Ants move/behavior function
    bool move = false;
    
    // create a third array, that establishes a counter then
    
    for (int j = 0; j < rows; j++) {
        
        for (int i = 0; i < cols; i++) {
            // if an ant is present, he needs to move somewhere
            if (world[i][j] == 'O'){
                
                switch (randNum(6)){ // The generator returns ints 1 - 4
                // Move up - world[i][j-1]
                case 1:
                    if(j != 0){
                    mirror[i][j-1] = 'O';
                    mirror[i][j] = ' ';
                    
                        move = true;
                        abreed[i][j-1] = abreed[i][j] + 1;
                        abreed[i][j] = 0;
                }
                    break;
                    
                // Move right - // world[i+1][j]
                case 2:
                    if(i != (cols-1)){
                    mirror[i+1][j] = 'O';
                    mirror[i][j] = ' ';
                        
                         move = true;
                         abreed[i+1][j] = abreed[i][j] + 1;
                         abreed[i][j] = 0;
                }
                    break;
                // Move Down - world[i][j+1]
                case 3:
                    if(j != (rows-1)){
                    mirror[i][j+1] = 'O';
                    mirror[i][j] = ' ';
                        
                        move = true;
                        abreed[i][j+1] = abreed[i][j] + 1;
                        abreed[i][j] = 0;
                    }
                    break;
                    
                // Move left - world[i-1][j]
                case 4:
                    if(i != 0){
                    mirror[i-1][j] = 'O';
                    mirror[i][j] = ' ';
                        
                        move = true;
                        abreed[i-1][j] = abreed[i][j] + 1;
                        abreed[i][j] = 0;
                    }
                    break;
                
                }
            }
            
            if(world[i][j]== 'O' && move == false){
                
                abreed[i][j] += 1;
                
            }
            
            // Doodle Eat
            else if(world[i][j] == 'Y'){
                
              
                if(i != 0 && i != (cols-1)){
                    
                    if (world[i+1][j] == 'O')    {
                        
                        // right
                        mirror[i+1][j] = 'Y';
                        starve[i+1][j] = 0;
                        
                        
                    }
                    else if(world[i-1][j] == 'O'){
                        
                        // left
                        mirror[i-1][j] = 'Y';
                        starve[i-1][j] = 0;
                    
                    // if the doodlebug doesn't eat, increment the counter
                    }else if(world[i][j]){
                        
                        starve[i][j] = starve[i][j] + 1;
                    }
                }
                
                if(starve[i][j] == 3){
                    
                   mirror[i][j] = ' ';
                   starve[i][j] = 0;
                
                    
                }
            // dooodle move
                
                switch (randNum(6)){ // The generator returns ints 1 - 4
                        // Move up - world[i][j-1]
                    case 1:
                        if(j != 0){
                            mirror[i][j-1] = 'Y';
                            mirror[i][j] = ' ';
                            
                            move = true;
                            dbreed[i][j-1] = dbreed[i][j] + 1;
                            dbreed[i][j] = 0;
                            
                        }
                        break;
                        
                        // Move right - // world[i+1][j]
                    case 2:
                        if(i != (cols-1)){
                            mirror[i+1][j] = 'Y';
                            mirror[i][j] = ' ';
                            
                            move = true;
                            dbreed[i+1][j] = dbreed[i][j] + 1;
                            dbreed[i][j] = 0;
                        }
                        break;
                        // Move Down - world[i][j+1]
                    case 3:
                        if(j != (rows-1)){
                            mirror[i][j+1] = 'Y';
                            mirror[i][j] = ' ';
                            
                            move = true;
                            dbreed[i][j+1] = dbreed[i][j] + 1;
                            dbreed[i][j] = 0;
                        }
                        break;
                        
                        // Move left - world[i-1][j]
                    case 4:
                        if(i != 0){
                            mirror[i-1][j] = 'Y';
                            mirror[i][j] = ' ';
                            
                            move = true;
                            dbreed[i-1][j] = dbreed[i][j] + 1;
                            dbreed[i][j] = 0;
                        }
                        break;
                        
                }
                if(world[i][j]== 'Y' && move == false){
                    
                    dbreed[i][j] += 1;
                    
                }
                
            // doodle move
           
            } // end of else if for Y
            
         
            
            // breed function called inside step function
          if(abreed[i][j] == 3){
                
                // top
                if((world[i][j-1] == ' ') && (j != 0)){
                    
                    mirror[i][j-1] = 'O';
                }
                
                // right
                else if(i != (rows-1)){
                    
                    if(world[i+1][j] == ' '){
                        
                       mirror[i+1][j] = 'O';
                    }
                    
                }
                
                // bottom
                else if((world[i][j+1] == ' ') && (j != (rows-1))){
                    
                    mirror[i][j+1] = 'O';
                }
                
                // left
                else if(i != 0){
                    
                    if(world[i-1][j] == ' '){
                    
                    mirror[i-1][j] = 'O';
                        
                    }
            
                    
                }
          }
            
        
      
            // doodle breed here
        if(dbreed[i][j] == 8){
                
                // top
                if(world[i][j-1] == ' '){
                    
                    mirror[i][j-1] = 'Y';
                }
                
                // right
                else if(world[i+1][j] == ' ') {
                    
                    mirror[i+1][j] = 'Y';
                }
                
                // bottom
                else if(world[i][j+1] == ' '){
                    
                    mirror[i][j+1] = 'Y';
                }
                
                // left
                else if (world[i-1][j] == ' '){
                    
                    mirror[i-1][j] = 'Y';
                }
                
        }
            
            else if(world[i][j] == ' '){
                
                mirror[i][j] = ' ';
            }
        if(world[i][j]== ' '){
                
            mirror[i][j] = ' ';
            
            }

            // doodle breed here
        } // this is the last bracket inside the i loop
        
        
                        
    } // this is the last bracket inside the j loop
    // Ants Move/behavior function
        
          world[cols] = mirror[cols];
          usleep(100000);
        
    } // I think this is the end of the loop

 
    
    // Deallocate the arrays
    for (int i = 0; i < rows; i++) {
        delete [] world[i];
        delete [] mirror[i];
        delete [] abreed[i];
        delete [] dbreed[i];
        delete [] starve[i];
       // delete [] mirror[i]; // This wasn't created with new, and all you do when you
    
    }
    
    return 0;
    }

// Random Number generator

int randNum(int num){
    
    int die;
    // Get the system time and processor time to ensure quick random number generator
    unsigned seed = time(0) + clock();
    
    // Seed the random number generator
    srand(seed);
    
    die = (rand() % (num - 2))+1;
    
    // Roll the Dice
    return  die;// Just add +1 if you don't want to include 0
}

// Random Number generator Ends here



