/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 17, 2016
 
 ** Title: Program 1
 
 ** Description: This program is an implementation of Conways game of 
 life.
 
 *********************************************************************/
#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

#include "conway.hpp"

/*****************************************************************
 *
 *                      Conway::Conway
 *  Constructor to initialize vectors, coordinates, and sets the size
 *
 *****************************************************************/

Conway::Conway(){
    
    const int SIZE = 50;
    
    xCoord = 25;
    yCoord = 15;
    
    // Initialize the world 2d vector
    world.resize(SIZE);
    for(int i=0;i<SIZE;i++){
        world[i].resize(SIZE);
    }
    
    // Initialize the mirror 2d vector
    mirror.resize(SIZE);
    for (int i=0;i<SIZE;i++){
        mirror[i].resize(SIZE);
    }
    
    // Initialize the vectors with O values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            
            world[i][j] = 'O';
            mirror[i][j] = 'O';
            
            }
        }
    
}
/*****************************************************************
 *
 *                      Conway::setXCoord(int x)
 *  Setter Function for the X Coordinate with validation Checking
 *
 *****************************************************************/
void Conway::setXCoord(int x){
    if(x < 1 || x > 30){
        
        x = 20;
        
        cout << "\nyou've chosen a bad value;" << endl;
        cout << "X now equals 20.\n" << endl;
        
    }
    
        
    xCoord = x + 5;
    
    
}
/*****************************************************************
 *
 *                      Conway::setXCoord(int y)
 *  Setter Function for the X Coordinate with validation Checking
 *
 *****************************************************************/
void Conway::setYCoord(int y){
    if(y < 1 || y > 20){
        
        y = 10;
        
        cout << "\nyou've chosen a bad value;" << endl;
        cout << "Y now equals 10.\n" << endl;
        
    }

    yCoord = y + 5;
}
/*****************************************************************
 *
 *                      Conway::printWorld()
 *  void function that prints a smaller than actual size of the 
 *  vector, to allow for seemingly continuous functionality
 *
 *****************************************************************/


void Conway::printWorld(){
    
    cout << "\n";
    // Iterate through Rows
    for (int i = 5; i < 25; i++) {
        
        // Iterate through columns
        for (int j = 5; j < 45; j++) {
            
           cout << world[i][j] << " ";
            
            if (j % 44 == 0) {
                
                cout << "\n";
            }
        }
    }
}

/*****************************************************************
 *
 *                      Conway::ScanWorld()
 *  This function implements conways game of life logic, to determine
 *  if a cell lives or dies, then copies a vector to another vector 
 *  so that the generation cycle may create an animation
 *****************************************************************/

void Conway::scanWorld(){

    char cc, ul, uc, ur, ml, mr, ll, lc, lr;
    
    // indicates number of rows, or Y = i
    for (int i = 1; i < 34; i++) {
        
        // indicates number of columns or X = j
        for (int j = 1; j < 50; j++) {
         
            int count = 0;
            
            // Center Cell
            cc = world[i][j];
            
            // upper left
            ul = world[i-1][j-1];
           
            if (ul == 'X') {
                count++;
            }
            
            // upper center
            uc = world[i-1][j];
            
            if (uc == 'X') {
                count++;
            }
            
            // upper right
            ur = world[i-1][j+1];
            
            if (ur == 'X') {
                count++;
            }
            
            // middle left
            ml = world[i][j-1];
            
            if (ml == 'X') {
                count++;
            }
            
            // middle right
            mr = world[i][j+1];
            
            if (mr == 'X') {
                count++;
            }
            
            // lower left
            ll = world[i+1][j+1];
            
            if (ll == 'X') {
                count++;
            }
            
            // lower center
            lc = world[i+1][j];
            
            if (lc == 'X') {
                count++;
            }
            
            // lower right
            lr = world[i+1][j-1];
        
            
            if (lr == 'X') {
                count++;
            }
            
            // The logic to determine a cells fate
            
            if (count < 2) {
                
                mirror[i][j] = 'O' ;

            }else if(count == 2 && world[i][j] == 'X'){
                
                mirror[i][j] = 'X';
                
            }else if(count > 3){
                
                mirror[i][j] = 'O';
            }
            
            else if(count == 3){
                
                mirror[i][j] = 'X';
                
            }else{
                
                mirror[i][j] = 'O';
            }
        }
    }
    
    // This copies the mirror vector with new values to the world array
    // and allows the printWorld to print an updated image of the matrix
    world = mirror;

}

/*****************************************************************
 *
 *                      Conway::oscillator()
 *  This function simply places the oscillator values in the user defined
 *  location in the matrix.
 *****************************************************************/

void Conway::oscillator(){
    
    int x,y;
    
    x = xCoord;
    y = yCoord;
    
    // Set living cells
    world[y][x-1] = 'X'; // center left
    world[y][x] = 'X';   // Reference
    world[y][x+1] = 'X'; // center right

}
/*****************************************************************
 *
 *                      Conway::glider()
 *  This function simply places the glider values in the user defined
 *  location in the matrix.
 *****************************************************************/
void Conway::glider(){
    
    int x,y;
    
    x = xCoord;
    y = yCoord;
    
    // Set living cells
    world[y][x-1] = 'X'; // center left
    world[y][x] = 'X';   // Reference
    world[y][x+1] = 'X'; // center right
    world[y-2][x] = 'X';   // two above center
    world[y-1][x+1] = 'X'; // above right

}
/*****************************************************************
 *
 *                      Conway::gliderCannon()
 *  This function simply places the glider Cannon values in the user
 *  defined location in the matrix.
 *****************************************************************/

void Conway::gliderCannon(){
    
    int x,y;
    
    x = xCoord;
    y = yCoord;
    
    // Set living cells
    world[y][x] = 'X';   // Reference
    world[y][x+1] = 'X';  // 1x right of ref
    world[y][x+2] = 'X';  // 2x right of ref
    world[y][x+3] = 'X'; //  3x right of ref
    world[y][x+4] = 'X'; //  4x right of ref
    world[y][x+5] = 'X'; //  5x right of ref
    world[y-1][x+4] = 'X'; //  4x right of ref & 1 up
    world[y+1][x+4] = 'X'; //  4x right of ref & 1 down
    world[y+1][x+7] = 'X'; //  7x right of ref & 1 down
    world[y][x+7] = 'X'; //  7x right of ref
    world[y-1][x+7] = 'X'; //  7x right of ref & 1 up
    world[y][x+8] = 'X'; //  7x right of ref
    
}
/*****************************************************************
 *
 *                      Main Function
 *  Greeting, Menu, and print cycle are implmented in Main
 *****************************************************************/

int main(){
    
    int startX, startY, choice;
    
    Conway world1;
    
    cout << "Hello. Welcome to Conways Game of Life.\n";
    cout << "Please start by choosing your x, y coordinates.";
    cout << "The range is 0-40 for X, and 0-20 for Y.\n";
    cout << "It may be prefferable to start your pattern in the center of the screen\n";
    cout << "(example: X:20, Y:10)\n";
    
    cout << "Enter for X:";
    cin >> startX;
    cout << "Enter for Y:";
    cin >> startY;
    
    world1.setXCoord(startX);
    world1.setYCoord(startY);
    
    cout << "Great! Now choose a pattern." << endl;
    cout << "Menu:" << endl;
    cout << "1. Oscillator" << endl;
    cout << "2. Glider" << endl;
    cout << "3. Glider Cannon" << endl;
    cout << "Enter 1, 2, or 3.\nMake a Choice:";
    cin >> choice;
    
    
    
    switch (choice) {
        case 1:
            cout << "You've selected an oscillator pattern." << endl;
            
            world1.oscillator();
            
            break;
            
            
        case 2:
            cout << "You've selected a Glider pattern." << endl;
            
            world1.glider();
            
            break;
            
            
        case 3:
            cout << "You've selected a Glider Cannnon Pattern" << endl;
            
            world1.gliderCannon();
            
            break;
            
            default:
            cout << "Please enter a valid input, you entered:" << choice << endl;
            cout << "This will do nothing, see:" << endl;
            break;
    }
    
    int printCount = 0;
    
    while (printCount < 30){
        
    printCount++;
    
    world1.scanWorld();
    world1.printWorld();
   
    usleep(10000);
   

    }
    
    
    return 0;
}














