    //
//  twoDArrayFinal.cpp
//  
//
//  Created by James Sandoval on 1/9/16.
//
//

#include <iostream>

using namespace std;

void foo(int**, int);

int main(){
    
    int counter = 0;
    
    int size = 3;
    
    int** arr;
    arr = new int *[3];
    
    
    for(int i=0;i<3;i++)
        
        arr[i] = new int(3);  // now you have the required 2D array
    // enter the values you want in arr[3][3]
    
    for (int i = 0; i < 3 ; i++) {
        
        for (int j = 0; j < 3; j++) {
            
            arr[i][j] = ++counter;
            
            cout << "#" << arr[i][j] << ":  " << i << "  " << j << " " << endl;
        }
    }

    
    foo(arr, size);
    
    
    return 0;
}


void foo(int** a, int size){
    // write the code for the array
    
    int counter = 0;
    
    cout << "This is inside the function" << endl;
    
    for (int i = 0; i < size ; i++) {
        
        for (int j = 0; j < size; j++) {
            
            cout << "#" << a[i][j] << ":  " << i << "  " << j << " " << endl;
        }
    }

}

//print the array here
