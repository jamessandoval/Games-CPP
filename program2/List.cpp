/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 31, 2016
 
 ** Title: List.hpp
 
 ** Description: This program is a simple list creation application.
 
 *********************************************************************/

#include <iostream>
#include <string>
#include "List.hpp"
#include <iomanip>

using namespace std;

/*****************************************************************
 *
 *                      List::addItem()
 * Adds an item to the list, and increases array size if needed
 *
 *****************************************************************/


void List::addItem(){
    
    string name;
    int quantity;
    double price;
    Units unit;
    
    int uchoice;
    
    Items* listCopy;
    
    if (numItems == currentSize) {
        
        listCopy = item;
        
        // deallocate the now unused array
        delete [] item;
        item = 0;
        
        // Double the size of the dynamic array
        currentSize *= 2;
        
        //Allocate the new array
        item = new Items[currentSize];
        
        for (int i = 0; i < currentSize/2; i++) {
            item[i] = listCopy[i];
        }
        
    }
    // Ask the user for inputs
    
    cout << "What is the name of the item you\'d like to add?" << endl;
    cin >> name;
    
    cout << "How many?" << endl;
    cin >> quantity;
    
    cout << "Enter a price in the format of $0.00." << endl;
    cin >> price;
    
    Units type;
    
    cout << "what type of unit is your item? (Enter the letter associated with type)" << endl;
    cout << "1. Case " << endl;
    cout << "2. Box " << endl;
    cout << "3. Pound " << endl;
    cout << "4. Ounce " << endl;
    cout << "5. Quart " << endl;
    
    
    
    cin >> uchoice;
    
    switch (uchoice) {
        case 1: type = CASE;
            break;
        case 2: type = BOX;
            break;
        case 3: type = POUND;
            break;
        case 4: type = OUNCE;
            break;
        case 5: type = QUART;
            break;
        default:
            cout << "You've entered an invalid letter, defaulting to case." << endl;
            type = CASE;
            break;
    }
    
    // Call the setter functions to place the item in the list
    
    item[numItems].setName(name);
    item[numItems].setQuantity(quantity);
    item[numItems].setPrice(price);
    item[numItems].setUnit(type);
    numItems++;
    // increment num items by 1 after you've added the item
}
/*****************************************************************
 *
 *                      List::removeItem()
 *  Removes the item from the list, and reduces the size by 1
 *
 *****************************************************************/


void List::removeItem(){
    
    int numToDelete;
    
    cout << "which item would you like to remove: " << endl;
    cout << "Please choose a number corresponding to the name of the item to remove." << endl;
    
    for (int i = 0; i < numItems; i++) {
        
        cout << "\nItem #:" << i+1 << " : ";
        
        cout << item[i].getName();
    }

    
    cout << "input:";
    
    cin >> numToDelete;
    --numToDelete;   // decrement by one because array starts at 0
    
    cout << "You've chosen to remove: " << item[numToDelete].getName();
    
    cout << endl;
    
    int counterDel = numToDelete;
    
    for(int i = numToDelete; i < numItems; i ++){
        
        item[counterDel] = item[counterDel + 1];
        counterDel++;
    }
    // Remove an item from num items, but only after all the items have been removed.
    numItems--;
    
};

/*****************************************************************
 *
 *                      List::printList()
 *  Print the current state of the list and print additional travel cost
 *
 *****************************************************************/

void List::printList(){
    
    double tripcost = .20 * numItems;
    
    for (int i = 0; i < numItems; i++) {
        
        cout << "\nItem #:" << i+1 << "\n" << endl;
        
        item[i].printItem();
    }
    
    if(tripcost == 0){
        
        cout << "The list is empty. please add items to the list." << endl;
    }
    
    cout << showpoint << fixed << setprecision(2);
    cout << "The total cost of the trip is: $" << tripcost << "\n" << endl;
    
};


