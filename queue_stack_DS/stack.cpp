//
//  queue.cpp
//
//  Created by James Sandoval on 2/10/16.
//  CS 162 Lab# 6 - Linked Structures
//  Description: This program demonstrates the use of a linked
//  structure and more specifically highlights its stack functionality.

#include "stack.hpp"
#include <iostream>

using namespace std;

// This function adds a node to the linked list passing an integer as a parameter

void Stack::add(int num){
    
    head = new StackNode(num, head);
}

// This function removes a node from the linked list
int Stack::remove(){
    
    int num;
    StackNode *temp;
    
    num = head->value;
    temp = head;
    head = head->next;
    delete temp;
    
    return num;

}

// This function displays the linked list
void Stack::displayStack() const {
    
    StackNode *nodePtr = head;
 
    while(nodePtr){
    
        cout << nodePtr->value << "     ";
        nodePtr = nodePtr->next;
        
    }
    
}

