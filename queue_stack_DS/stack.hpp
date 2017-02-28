//
//  queue.hpp
//
//  Created by James Sandoval on 2/10/16.
//  CS 162 Lab# 6 - Linked Structures
//  Description: This program demonstrates the use of a linked
//  structure and more specifically highlights its stack functionality.

#include <iostream>

using namespace std;

class Stack{
    
    private:
        class StackNode{
            friend class Stack;
            int value;
            // create pointer object of StackNode
            StackNode *next;
            // take int value and set pointer to null;
            StackNode(int value1, StackNode *next1 = NULL){
                
                value = value1;
                next = next1;
            }
        };
    
    StackNode *head;
    
    public:
    Stack() {
        
        head = NULL;
    }
    ~Stack(){
        
    }
        void add(int number);
        int remove();
        void displayStack() const;
  
};

