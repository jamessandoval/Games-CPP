//
//  palindrome.cpp
//  lab9
//
//  Created by James Sandoval on 3/6/16.
//
//

#include "palindrome.hpp"
#include <stack>
#include <cstring>

#include <iostream>

using namespace std;

/******************************************
 *
 *               void palindromeGen()
 * Description: Generates a palindrome based on 
 * user string.
 * parameters: none;
 * returns: void
 *******************************************/
void palindromeGen(){
    
    stack<char> palindrome;
    
    const int Slength = 50;
    
    // source
    char sourceArray[Slength];
    
    char destination[Slength];
    
    cout << "\nPalindrome Generator:\n\n";
    
    cout << "Please enter a palindrome." << endl;
    
    cin.ignore();
    
    cin.getline(sourceArray, Slength);
    
    int index = 0;
    
    while(sourceArray[index] != '\0' )
        
    {
        palindrome.push(sourceArray[index]);
        index++;
    }
    
    cout << "The output is: \n";
    
    index = 0;
    
    while(!palindrome.empty()) {
        
        destination[index] = palindrome.top();
        palindrome.pop();
        
        cout << destination[index];
        index++;
    }
    
    if (*sourceArray == *destination) {
        cout << "\n\nYou entered a palindrome\n";
    }
    else{
        
        cout << "\n\nYou failed to enter a palindrome\n";
    }
    
    
    cout << endl;
    
}
