#include <sstream>
#include "IntLinkedQueue.hpp"

IntLinkedQueue::IntLinkedQueue (){
    int numElements = 0;
    queueHead = queueTail = 0;
}

IntLinkedQueue::~ IntLinkedQueue (){
    clear();
}

int IntLinkedQueue:: size () const {
    return numElements;
}

bool IntLinkedQueue:: isEmpty () const {
    if(numElements == 0 ) return true;
    return false;    
}

void IntLinkedQueue:: enqueue ( const int e ){
    Reg * aux = new Reg(e);

    if(numElements == 0){
        queueHead = queueTail = aux;
        return;
    }

    queueTail->next = aux;
    queueTail = aux;
    ++numElements;
}

bool IntLinkedQueue:: dequeue ( int & e ){
    if(isEmpty() == true) return false;

    Reg * aux = new Reg(e);

    
}

bool IntLinkedQueue:: head ( int & e) const{

}

void IntLinkedQueue::clear (){

}

string IntLinkedQueue:: str () const{

}