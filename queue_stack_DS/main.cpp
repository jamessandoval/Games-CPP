//
//  queue.hpp
//
//  Created by James Sandoval on 2/10/16.
//  CS 162 Lab# 6 - Linked Structures
//  Description: This program demonstrates the use of a doubly linked
//  structure and a singly linked structure and more specifically highlights
//  each classes functionality.

#include <iostream>
#include "stack.hpp"
#include "queue.hpp"


using namespace std;

int main(){
    
    // Create a stack object and input some numbers and remove one.
    
    Stack stack1;
    
    cout << "Here is the stuck functionality: " << endl;
    
    stack1.add(5);
    stack1.add(2);
    stack1.add(3);
    stack1.add(2);
    stack1.add(1);
    stack1.displayStack();
    cout << endl;
    cout << "The element removed is: " << stack1.remove() << endl;
    stack1.displayStack();
    cout << endl;
    
     
    // Create a queue object and input some numbers and remove one.
    cout << "Here is the Queue functionality: " << endl;
    Queue queue1;
    
    queue1.add(3);
    queue1.add(4);
    queue1.add(2);
    queue1.add(7);
    queue1.add(8);
    queue1.displayQueue();
    cout << endl;
    cout << "The number removed is: " << queue1.remove() << endl;
    queue1.displayQueue();
    cout << endl;
    

    return 0;
}
