//
//  queue.hpp
//
//  Created by James Sandoval on 2/10/16.
//  CS 162 Lab# 6 - Linked Structures
//  Description: This program demonstrates the use of a doubly linked
//  structure and more specifically highlights its queue functionality.

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

using namespace std;

// Queue Class definition
class Queue{
    
private:
    class QueueNode{
        friend class Queue;
        int value;
        
        // Create a pointer object of QueueNode
        QueueNode *next;
        // take an integer and set pointer to Null
        QueueNode(int value1, QueueNode *next1 = NULL)
        {
        
        value = value1;
        next = next1;
            
        }
    };
    
    QueueNode *head;
    QueueNode *tail;

public:
    Queue();
    ~Queue();
    
    void add(int);
    int remove();
    void displayQueue() const;
    bool empty() const;
    
};


#endif