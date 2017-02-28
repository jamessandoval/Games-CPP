//
//  search.cpp
//  lab7
//
//  Created by James Sandoval on 2/16/16.
//
//

#include <iostream>
#include "search.hpp"

using namespace std;


/**************************************************************
 *
 *     int linearSearch(int array, int, int)
 *
 *  This function uses a linear search algorithm
 *  to sequentially step through an array,
 *  it passes an array, the arrays size, and the
 *  value to be searched as parameters.
 *
 *  Source: (Pg. 595, "Starting Out with C++")
 *
 ***************************************************************/
int linearSearch(int numbers[], int size, int value)
{
    
    int index  = 0;
    int position = -1;
    bool found = false;
    
    while(index < size && !found)
    {
        
        if(numbers[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

/***************************************************************
 *
 *             int selectionSort(int array, int)
 *
 * This function uses a selection sort algorithm to sequentially
 * step through an array, and place the appropriate value in position,
 * it passes the array and its size as parameters.
 *
 *         Source: (Pg. 609, "Starting Out with C++")
 *
 ***************************************************************/
void selectionSort(int numStorage[], int size)
{
    int minIndex, minValue;
    
    for (int i = 0; i < (size - 1); i++)
    {
        minIndex = i;
        minValue = numStorage[i];
        
        for(int index = i + 1; index < size; index++)
        {
            if(numStorage[index] < minValue)
            {
                minValue = numStorage[index];
                minIndex = index;
                
            }
        }
        numStorage[minIndex] = numStorage[i];
        numStorage[i] = minValue;
    }
}

/****************************************************************
 *
 *     int searchOutput(int array, int size, int value)
 *
 * This function simply prints the result of a linear search
 * algorithm when its called. it's parameters are
 * the array, size, and the number of the file to be searched.
 *
 *****************************************************************/

void searchOutput(int searchO[], int size, int num){
    
    int results;
    
    cout << "\n\nSearch results for file #" << num << endl;
    
    results = linearSearch(searchO, size, 0);
    
    if(results == -1)
        
    {
        cout << "The number 0 was not found." << endl;
    }
    
    else
    {
        cout << "The first 0 is located at position: #" << results << "." << endl;
    }
    
}

/******************************************************************
 *
 *         int binarySearch(int array, int size, int value)
 *
 *   This functin uses a binary search algorithm to search through a
 *   sorted array. Its benefit is that it starts in the middle and
 *   if the value is not found it then makes a comparison and determines
 *   which half of the array to search. It continues to search halves
 *   intil the value is found. Parameters are an array, its size, and
 *   the value to be searched.
 *
 *            Source: (Pg. 598, "Starting Out with C++")
 *
 *****************************************************************/


int binarySearch(int sortedArray[], int size, int value){
    
    
    int first = 0, last = size - 1, middle, position = -1;
    bool found = false; // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Determine midpoint
        
        if (sortedArray[middle] == value) // If value is found at midpoint
        {
            found = true;
            position = middle;
        }
        else if (sortedArray[middle] > value) // Value = half
            last = middle - 1;
        else
            first = middle + 1; // Value = upper half
    }
    return position;
    
    
}






