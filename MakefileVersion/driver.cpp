//CS 302 Homework 3
//Author: Max Georgeson
//Purpose: Bank Teller with Array Based Queue
//Due Date: 3/14/21

#include <iostream>
#include <string>
#include <fstream>
#include "arrayQueue.h"
#include "customer.h"
#include "event.h"
using namespace std;

#define NUM_ARGS 2

int main(int argc, char const *argv[]){
    if(argc < NUM_ARGS){
		cout <<"Correct usage:" << endl;
		cout << argv[0] <<" filename" << endl;
		return 0;
	}

    string filename = argv[1];
    bool tellerAvail = true;
    int counter = 0;
    float cumulativeWait = 0;
    int tempArrival, tempWait;
 

    ArrayQueue<Event> eventQueue;
    ArrayQueue<Customer> customerQueue;

    ifstream fin(filename);

    if(fin.is_open()){
        while(fin >> tempArrival >> tempWait){
            Event tempEvent("Arrival", tempArrival, tempWait);
            eventQueue.enqueue(tempEvent);
        }
        fin.close();
    }else{
        cout << "Sorry, could not open " << filename << " for reading." << endl;
    }

    cout << "Simulation Begins" << endl;

    while(!eventQueue.isEmpty()){
        Event newEvent = eventQueue.peekFront();
        int time = newEvent.getTime();
        int length = newEvent.getLength();
        if(newEvent.getType() == "Arrival"){
            cout << "Processing an arrival event at time: " << time << endl;
            eventQueue.dequeue();
            if(customerQueue.isEmpty() && tellerAvail){
                int departureTime = time + length;
                Event newDepartureEvent("Departure", departureTime, 0);
                eventQueue.enqueue(newDepartureEvent);
                tellerAvail = false;
            }else{
                Customer tempCustomer(time, length);
                customerQueue.enqueue(tempCustomer);
            }
        }else if(newEvent.getType() == "Departure"){
            cout << "Processing a departure event at time: " << time << endl;
            counter++;
            eventQueue.dequeue();
            if(!customerQueue.isEmpty()){
                Customer newCustomer = customerQueue.peekFront();
                customerQueue.dequeue();
                cumulativeWait += (time - newCustomer.getArrival());
                int departureTime = time + newCustomer.getWait();
                Event newDepartureEvent("Departure", departureTime, 0);
                eventQueue.enqueue(newDepartureEvent);
            }else{
                tellerAvail = true;
            }
        }else{
            cout << "Something went wrong" << endl;
            return 0;
        }
    }
    cout << "Simulation Ends" << endl;
    cout << "Final Statics:" << endl;
    cout << "Total number of people processed: " << counter << endl;
    cout << "Average amount of time spent waiting: " << cumulativeWait/counter << endl;


    return 0;
}