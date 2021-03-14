//#include "arrayQueue.h"
using namespace std;

template<class T>
ArrayQueue<T>::ArrayQueue(){
    frontIndex = 0;
    backIndex = -1;
    itemCount = 0;
    T items[DEFAULT_CAPACITY - 1];
}


template<class T>
bool ArrayQueue<T>::isEmpty() const{
    return itemCount == 0;
}

template<class T>
bool ArrayQueue<T>::enqueue(const T& entry){
    T newEntry = entry;
    bool canNQ = itemCount < DEFAULT_CAPACITY - 1;
    if(canNQ){
        if(isEmpty()){
            backIndex = (backIndex + 1) % DEFAULT_CAPACITY;
            items[backIndex] = newEntry;
            itemCount++;
        }else if(newEntry < items[frontIndex]){
            for(int i = (backIndex + 1) % DEFAULT_CAPACITY; i > 0; i--){
                items[i] = items[i - 1];
            }
            items[frontIndex] = newEntry;
            backIndex = (backIndex + 1) % DEFAULT_CAPACITY;
            itemCount++;
        }else{
            int tracker = frontIndex;
            while(tracker != backIndex && !(newEntry < items[tracker])){
                tracker++;
            }
            if(tracker != backIndex){
                for(int i = (backIndex + 1) % DEFAULT_CAPACITY; i > tracker; i--){
                    items[i] = items[i - 1];
                }
                items[tracker] = newEntry;
                backIndex = (backIndex + 1) % DEFAULT_CAPACITY;
                itemCount++;
            }else if(tracker == backIndex && newEntry < items[tracker]){
                items[tracker + 1] = items[tracker];
                items[tracker] = newEntry;
                backIndex = (backIndex + 1) % DEFAULT_CAPACITY;
                itemCount++;
            }else{
            backIndex = (backIndex + 1) % DEFAULT_CAPACITY;
            items[backIndex] = newEntry;
            itemCount++;
            }
        }
    }
    return canNQ;
}

template<class T>
bool ArrayQueue<T>::dequeue(){
    bool canDQ = !isEmpty();
 
    if(canDQ){
    frontIndex = (frontIndex + 1) % DEFAULT_CAPACITY;
    itemCount --;
    }

    return canDQ;
}

template<class T>
T ArrayQueue<T>::peekFront() const{
    bool canPeek = !isEmpty();

    if(canPeek){
        return items[frontIndex];
    }else{
        throw "Empty queue";
    }
}

template<class T>
ArrayQueue<T>::~ArrayQueue(){
    while(dequeue());
}