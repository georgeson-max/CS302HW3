#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
using namespace std;

class Event{
protected:
    string type;
    int time;
    int length;
public:
    Event();
    Event(string, int, int);

    string getType() const;
    int getTime() const;
    int getLength() const;

    void setType(string);
    void setTime(int);
    void setLength(int);

    bool operator<(const  Event&);
};
#include "event.cpp"
#endif
