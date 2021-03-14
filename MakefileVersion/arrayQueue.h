#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include "queue.h"

template<class T>
class ArrayQueue : public QueueInterface<T> {
protected:
    static const int DEFAULT_CAPACITY = 100;
    int frontIndex;
    int backIndex;
    int itemCount;
    T items[DEFAULT_CAPACITY - 1];
public:
    ArrayQueue();

    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront() const;

    ~ArrayQueue();

};
#include "arrayQueue.cpp"
#endif