//
//  queue.cpp
//
//  Created by James Sandoval on 2/10/16.
//  CS 162 Lab# 6 - Linked Structures
//  Description: This program demonstrates the use of a doubly linked
//  structure and more specifically highlights its queue functionality.

#include "queue.hpp"
#include <iostream>

using namespace std;

// initialize the head and tail pointers
Queue::Queue(){
    
    head = NULL;
    tail = NULL;
}

// delete the linked list
Queue::~Queue(){
    
    if (!empty()) {
        
        remove();
    }
}
// add an int to the linked list
void Queue::add(int value){
   
    if(empty()){
        
        head = new QueueNode(value);
        tail = head;

    }
    else{
   
        tail->next = new QueueNode(value);
        tail = tail->next;
    }
}


// Remove elements from the list
int Queue::remove(){
    
    int value;
    QueueNode *temp;
    
    if (empty()) {
        cout << "there's nothing to remove." << endl;
    }
    
    else{
        
        value = head->value;
        temp = head;
        head = head->next;
        delete temp;
    }
    
    return value;
}

// Check to see if the list is empty
bool Queue::empty() const{
    
    if (head == NULL) {
        return true;
    }
    else return false;
}

// Display the list
void Queue::displayQueue() const {
    
    QueueNode *nodePtr = head;
    
    while(nodePtr){
        
        cout << nodePtr->value << "     ";
        // move to next node
        nodePtr = nodePtr->next;
        
    }
    
}








