/**
  CIS 22C
  Homework 5
  // Write a short description of the project below
 
 
  Name:Matthew Hoang
  IDE:Xcode
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Heap.h"
#include <string>
#include <stdlib.h>

using namespace std;

void reading_from_file( ){

    ifstream inputFile;
    inputFile.open("overbooked.txt");
    string testing_file;
    int priority_value;
    
    int a;
    int b;
    int c;
    while(inputFile >> testing_file){
        a = atoi(testing_file.c_str() );
        inputFile >> testing_file;
        
        b = atoi(testing_file.c_str() );
        
        inputFile>>testing_file;
        c = atoi(testing_file.c_str() );
        
        priority_value = a/1000 + b - c;
        getline(inputFile, testing_file);
        
        Heap <int>waiting_list;
        waiting_list.insertHeap(priority_value);
    }
    inputFile.close();

}

int main()
{
    reading_from_file( );
    
    return 0;
}
