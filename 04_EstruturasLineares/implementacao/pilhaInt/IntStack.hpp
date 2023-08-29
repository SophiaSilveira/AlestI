//  intstack

#ifndef _INTSTACK_HPP
#define _INTSTACK_HPP

#include <string>

using namespace std;

class IntStack {
    private :
        int numElements;
        int maxElements;
        int * stack;

    public:
        IntStack ( int mxSz = 10);
        ~ IntStack ();
        bool push ( const int & e );
        bool pop (int &e );
        bool top (int &e ) const ;
        int size () const ;
        int maxSize () const ;
        bool isEmpty () const ;
        bool isFull () const ;
        void clear ();
        string str () const ;
};

# endif