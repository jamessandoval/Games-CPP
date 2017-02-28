//
//  main.cpp
//  lab7
//
//  Created by James Sandoval on 2/16/16.
//
//

#include <iostream>
#include <fstream> // for file input operation
#include <string>
#include "search.hpp"

const int SIZE = 20;

using namespace std;

int main()
{

    int num;
    char comma;
    
    string outputFile1;
    ofstream oFile1;
    
    // define arrays to store file info //
    // -------------------------------- //
    int numStorage1[SIZE];
    int numStorage2[SIZE];
    int numStorage3[SIZE];
    int numStorage4[SIZE];
    
    // create ifstream objects and open files //
    // -------------------------------------- //
    
    ifstream inputFile1("early.txt");
    ifstream inputFile2("middle.txt");
    ifstream inputFile3("late.txt");
    ifstream inputFile4("none.txt");
    
    // read data from input files  //
    // --------------------------- //
    
    // File 1
    for (int i = 0; inputFile1 >> num; i++) {
        numStorage1[i] = num;
        inputFile1 >> comma;
    }
    
    // File 2
    for (int i = 0; inputFile2 >> num; i++) {
        numStorage2[i] = num;
        inputFile2 >> comma;
    }
    
    // File 3
    for (int i = 0; inputFile3 >> num; i++) {
        numStorage3[i] = num;
        inputFile3 >> comma;
    }
    
    // File 4
    for (int i = 0; inputFile4 >> num; i++) {
        numStorage4[i] = num;
        inputFile4 >> comma;
    }

    
    // Introduction //
    cout << "Hello, and welcome to lab #7.\n"
         << "This program takes 4 files, allows you to search the contents of each file.\n"
         << "It also sorts a file, writes the results to a new file, and finally the\n"
         << "program will use a binary search algorithm to find a target value." << endl;
    
    // Menu Selection //
    
    int choice;
    
    while(choice != 4)
    {
    
        cout << "\nPlease choose from the menu below:\n\n"
        << "1. Search for target value of 0\n"
        << "2. Sort a set of values\n"
        << "3. Search for a target value using binary search.\n"
        << "4. Quit the program\n\n\n";
        
        cout << "Enter an integer value:";
        cin >> choice;
    
        switch (choice) {
            case 1:
                // Search for target value of 0 in each file, using linear search
                searchOutput(numStorage1, SIZE, 1);
                searchOutput(numStorage2, SIZE, 2);
                searchOutput(numStorage3, SIZE, 3);
                searchOutput(numStorage4, SIZE, 4);
                
                
                break;
            case 2:
                // Sort a set of values
                selectionSort(numStorage1,SIZE);
                
                cout << "\nYour file has been sorted.\n" << endl;
                
                // File Output operations //
                
                cout << "What would you like to name your sorted output file?\n"
                     << "name:";
                cin >> outputFile1;
                
                oFile1.open(string(outputFile1+".txt").c_str());
                
                for (int i = 0; i < SIZE; i++) {
                    
                    oFile1 << numStorage1[i];
                    oFile1 << ", ";
                }
                
                oFile1.close(); // close the output file
                
                cout <<"\nYour file has been saved.\n" << endl;
            
                break;
            case 3:
                // Search for target value using binary search
                int bSearchValue;
                int binaryResult;
                
                // File input from latee.txt must be sorted first:
                selectionSort(numStorage3,SIZE);
                
                cout << "Enter the value you want to find?\n"
                     << "input:";
                cin  >> bSearchValue;
                
                // call binary search
                binaryResult = binarySearch(numStorage3,SIZE,bSearchValue);
                
                if (bSearchValue == -1) {
                    
                    cout << "The value was not found.\n";
                }
                else{
                    
                    cout << "\nthe value is found at position: " << binaryResult << endl;
                }
                
                break;
            case 4:
                // Quit the program
                cout << "Goodbye\n";
                break;
                
            default: cout << "Please choose a valid integer or 0 to quit\n";
                break;
        }
    }
    

    return 0;
}













