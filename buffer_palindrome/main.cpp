/******************************************
*
*  main.cpp
*  Lab9
*
*  Created by James Sandoval on 3/1/16.
*
* Description: This program uses STL containers to
* implement a queue and a stack. The Queue portion
* simulates a user defined buffer. The Stack portion
* generates a user inputted palindrome.
*******************************************/

#include "palindrome.hpp"
#include "buffer.hpp"
#include <iostream>
using namespace std;

/******************************************
 *
 *               Main Function
 * Description: Main function implements a menu,
 * that allows user to select a buffer simulator 
 * or a palindrome generator.
 *******************************************/

int main(){
    
    int choice;

    do{
        cout << " Please make a selection:\n"
             << " 1. Test Buffer\n"
             << " 2. Create a palindrome\n"
             << " 3. Quit\n";
    
    cout << "input:";
    cin >> choice;
    
    switch (choice) {
            // Test buffer
        case 1: bufferSim();
            break;
            // Test Palindrome
        case 2: palindromeGen();
            break;
            // quit
        case 3: cout << "\nGoodbye\n";
            break;
        default: cout << "\nPlease choose a valid integer: 1, 2, or 3.\n";
            break;
    }
    
    }while (choice != 3);
    
    return 0;
}







