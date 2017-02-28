//
//  buffer.cpp
//  lab9
//
//  Created by James Sandoval on 3/6/16.
//
//
#include "buffer.hpp"

// Needed to implement the Queue
#include <queue>
// for Randome# generator
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include <iostream>

using namespace std;

/******************************************
 *
 *               void bufferSim()
 * Description: Function simulates a buffer.
 * parameters: none;
 * returns: void
 *******************************************/
void bufferSim(){
    
    // Define Queue STL
    queue<int> rQueue;
    
    // input = percentage to push value into queue
    // input2 = percentage to remove value from queue
    // input 3 = rounds to run simulation
    int input, input2, input3;
    
    cout << "\nBuffer Simulation:\n\nPlease enter a percentage to push a value into queue.\n" << endl;
    
    cout << "input:";
    
    cin >> input;
    
    cout << "\n\nplease enter a percentage to remove a value from the queue.\n" << endl;
    
    cout << "input:";
    
    cin >> input2;
    
    cout << "How many rounds would you like to run the simulation?" << endl;
    
    cin >> input3;
    
    for (int i = 0; i < input3; i++){
        
        if(percentRatio(input) == 1){
            
            rQueue.push(numGenerator());
        }
        
        if(percentRatio(input2) == 1) {
            
            if (rQueue.size() != 0) {
                rQueue.pop();
            }
            
        }
    }
    
    cout << "\nThe Final size of the queue is:\n" << rQueue.size() << " " << endl;
    
}
/******************************************
 *
 *               int percentRatio()
 * Description: calculates the user percentage ratio.
 * parameters: int input
 * returns: input
 *******************************************/
int percentRatio(int input){
    
    input = 100 / input;
    
    usleep(10);
    
    srand(rand() + time(0) + clock());
    
    return rand() % input + 1;
    
}


/******************************************
 *
 *               int numGenerator()
 * Description: generates a number 1 - 100.
 * parameters:
 * returns: a value between 0 - 100.
 *******************************************/
int numGenerator(){
    
    usleep(10);
    
    srand(rand() + time(0) + clock());
    
    return rand() % 100 + 1;
    
}
