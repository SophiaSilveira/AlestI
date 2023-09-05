#ifndef _INTLINKEDQUEUE_HPP
#define _INTLINKEDQUEUE_HPP

#include <string>

using namespace std ;

class IntLinkedQueue {
    private :
    int numElements ;
    struct Reg {
        int data ;
        Reg * next ;
        Reg ( int d) { data = d; next = nullptr ; }
    };
    
    Reg * queueHead , * queueTail;

    public:
    IntLinkedQueue ();
    ~ IntLinkedQueue ();
    int size () const ;
    bool isEmpty () const ;
    void enqueue ( const int e );
    bool dequeue ( int & e );
    bool head ( int & e) const ;
    void clear ();
    string str () const ;
};
# endif