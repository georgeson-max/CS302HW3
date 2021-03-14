#include "customer.h"

Customer::Customer(){
    arrivalTime = 0;
    waitTime = 0;
}

Customer::Customer(int newArrival, int newWait){
    arrivalTime = newArrival;
    waitTime = newWait;
}


int Customer::getArrival() const{
    return arrivalTime;
}

int Customer::getWait() const{
    return waitTime;
}


void Customer::setArrival(int newArrival){
    arrivalTime = newArrival;
}

void Customer::setWait(int newWait){
    waitTime = newWait;
}


bool Customer::operator<(const  Customer& rhs){
    if(arrivalTime < rhs.arrivalTime){
        return true;
    }else{
        return false;
    }

}
