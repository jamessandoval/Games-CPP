/*********************************************************************
 
 ** Author: James E. Sandoval
 
 ** Date: January 31, 2016
 
 ** Title: Items.hpp
 
 ** Description: This program is a simple list creation application.
 
 *********************************************************************/
#include <iostream>
#include <string>
#include <iomanip>

#ifndef Items_HPP
#define Items_HPP

using namespace std;

// Create constants for unit type
enum Units {CASE, BOX, POUND, OUNCE, QUART};

class Items{
    private:
        string name;
        int quantity;
        double price;
        Units unit;
    
    public:
    // Constructor to set defaults
    Items(){
        name = "\"\"";
        quantity = 0;
        price = 0.0;
        unit = CASE;
        
    }
        // Setter-Getter functions
        void setName(string n);
        string getName();
        void setQuantity(int q);
        int getQuantity();
        void setPrice(double p);
        double getPrice();
    void setUnit(Units u);
        Units getUnit() const;
        void printItem();
        double extendedPrice();
};

#endif


















