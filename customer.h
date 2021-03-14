#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
using namespace std;

class Customer{
protected:
    int arrivalTime;
    int waitTime;
public:
    Customer();
    Customer(int, int);

    int getArrival() const;
    int getWait() const;

    void setArrival(int);
    void setWait(int);

    bool operator<(const  Customer&);
};
#include "customer.cpp"
#endif