//
//  Customer.h
//  HW_5
//
//  Created by home on 6/10/19.
//  Copyright © 2019 home. All rights reserved.
//

#ifndef Customer_h
#define Customer_h
#include <string>

class Customer{
private:
    int total_milage;
    int number_of_years;
    int waitlist_number;
    string name;
    int priority_value;
public:
    Customer(){total_milage = 0;number_of_years = 0;waitlist_number = 999;name = "";}
    
    Customer(int a, int b, int c, string customer_name){total_milage = a;number_of_years = b;waitlist_number = c;name = customer_name;}
    
    void setMilage(int milage){total_milage = milage;}
    void setYears(int years){number_of_years = years;}
    void setWaitlist(int waitlist){waitlist_number = waitlist;}
    void setName(string customer_name){name = customer_name;}
    void setPriorityValue(int priority_value_temp){priority_value = priority_value_temp;}
    
    int getMilage(){return total_milage;}
    int getYears(){return number_of_years;}
    int getWaitlist(){return waitlist_number;}
    
    string getName(){return name;}
    int getPriorityValue(){return priority_value;}
    
};
#endif /* Customer_h */
