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
#include "Customer.h"

#include <string>
#include <stdlib.h>

using namespace std;

void sort_function(Customer *array, int count_of_array){
    int i,j, key;
    for(int i = 1; i < count_of_array;i++){
        int key = array[i].getPriorityValue();
        int milage_key = array[i].getMilage();
        string name_key = array[i].getName();
        int waitlist_key = array[i].getWaitlist();
        int years_key = array[i].getYears();

        j = i - 1;
        while(j >=0 && array[j].getPriorityValue() > key){
            int temp = array[j].getPriorityValue();
            int milage_temp = array[j].getMilage();
            int years_temp = array[j].getYears();
            int waitlist_temp = array[j].getWaitlist();
            string name_temp = array[j].getName();
            
            array[j+1].setPriorityValue(temp);
            array[j+1].setMilage(milage_temp);
            array[j+1].setName(name_temp);
            array[j+1].setWaitlist(waitlist_temp);
            array[j+1].setYears(years_temp);
            j = j - 1;
        }
        array[j+1].setPriorityValue(key);
        array[j+1].setMilage(milage_key);
        array[j+1].setName(name_key);
        array[j+1].setWaitlist(waitlist_key);
        array[j+1].setYears(years_key);

    }
}
void print_function(Customer *print_array, int counter){
    for(int i = 0; i < counter; i ++){
        cout<<print_array[i].getPriorityValue()<<" "<<print_array[i].getMilage()<<" "<<print_array[i].getName()<<" "<<print_array[i].getWaitlist()<<" "<<print_array[i].getYears()<<endl;
    }
}

int main()
{
    ifstream inputFile;
    inputFile.open("overbooked.txt");
    string testing_file;
    int priority_value;
    
    int a;
    int b;
    int c;
    Customer customer_array[999];
    int i = 0;
    string getline_name;
    Heap <int>waiting_list;

    while(inputFile >> testing_file){
        a = atoi(testing_file.c_str() );
        inputFile >> testing_file;
        
        b = atoi(testing_file.c_str() );
        
        inputFile>>testing_file;
        c = atoi(testing_file.c_str() );
        
        priority_value = a/1000 + b - c;
        getline(inputFile, testing_file);
        
        waiting_list.insertHeap(priority_value);
        
        customer_array[i].setMilage(b);
        customer_array[i].setYears(a);
        customer_array[i].setWaitlist(c);
        customer_array[i].setName(testing_file);
        customer_array[i].setPriorityValue(priority_value);
        i++;
        
    }
    inputFile.close();
    //sort_function(customer_array,i);
    //print_function(customer_array,i);
    waiting_list.printHeap();
    
    return 0;
}
