/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 31, 2016
 
 ** Title: Items.cpp
 
 ** Description: This program is a simple list creation application.
 
 *********************************************************************/

#include "Items.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

const string uName[] = {"Case", "Box", "Pound", "Ounce", "Quart"};

/*****************************************************************
 *
 *                      Items::printItem()
 *           Prints an item when called; no parameters
 *
 *****************************************************************/

void Items::printItem(){
    
    cout << "The item name is:" << name << endl;
    cout << "The Quantity is:" << quantity << endl;
    cout << "The Unit price is: $" << showpoint << setprecision(2) << fixed << price << endl;
    cout << "The Unit type is:  " << uName[unit] << endl;
    cout << "The extended price is: $:" << extendedPrice() << "\n" << endl;
    
}
// Setter-Getter functions for Name
void Items::setName(string n){
    name = n;
}

string Items::getName(){
    return name;
}
// Setter-Getter functions for quantity
void Items::setQuantity(int q){
    
    quantity = q;
}

int Items::getQuantity(){
    return quantity;
}
// Setter-Getter functions for price
void Items::setPrice(double p){

    price = p;
}

double Items::getPrice(){
    return price;
}
// Setter-Getter functions for units

void Items::setUnit(Units u){
    
    unit = u;

}

Units Items::getUnit() const{
    
    return unit;
}
/*****************************************************************
 *
 *                      Items::exendedPrice()
 * Prints the total cost of an item * quantity to return its total price.
 *
 *****************************************************************/

double Items::extendedPrice(){
    double total;
    total = quantity * price;
    return total;
}
