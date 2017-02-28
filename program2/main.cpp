/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 31, 2016
 
 ** Title: Program 2 - main.cpp 
 
 ** Description: This program is a simple list creation application.
 
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include "List.hpp"

using namespace std;

int main(){
    
    // Create the list object
    List list1;
    
    
    int choice = 0;
    
    // Program Greeting
    cout << "Hello, Welcome to List-O-Mania." << endl;
    cout << "The program where you can create a shopping list." << endl;
    
    // Program Menu
    
    while (choice != 5 ) {
    
    cout << "\nWhat would you like to do?\n" << endl;
    cout << "1. Create a list." << endl;
    cout << "2. Add Item(s) to the list" << endl;
    cout << "3. Remove an Item from the list" << endl;
    cout << "4. print the list" << endl;
    cout << "5. Exit the program" << endl;
    cout << "input(1 - 5): ";
    cin  >> choice;
    
    switch (choice) {
        case 1: cout << "You\'ve chosen to create a list. Please add item(s) to your list." << endl;
            list1.addItem(); 
            break;
            
        case 2: cout << "You\'ve chosen to add items to your list. Add item(s)." << endl;
            list1.addItem();
            break;
        case 3: cout << "You\'ve chosen to delete items from your list. remove item(s)." << endl;
            list1.removeItem();
            break;
        case 4: cout << "You\'ve chosen to print your list." << endl;
            list1.printList();
            break;
        case 5: cout << "You\'ve chosen to exit the program." << endl;
            cout << "Goodbye." << endl;
            
            break;
        default: cout << "you've made an incorrect choice, please try again." << endl;
            break;
       }
    }
    
    return 0;
}
