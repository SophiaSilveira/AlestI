#include <sstream>
#include "IntStack.hpp"

IntStack :: IntStack (int mxSz ) {
    if ( mxSz < 1 ) mxSz = 10;
    maxElements = mxSz ;
    stack = new int [ maxElements ];
    numElements = 0;
}

IntStack ::~ IntStack () { delete [] stack; }

bool IntStack :: push ( const int &e) {
    if ( numElements == maxElements ) return false;
    else { stack [ numElements ++ ] = e; return true; }
}

bool IntStack :: pop ( int &e ) {
    if ( numElements == 0 ) return false ;
    else { e = stack [ -- numElements ]; return true ; }
}

bool IntStack :: top ( int &e ) const {
    if ( numElements < 1 ) return false ;
    else { e = stack [ numElements -1 ]; return true ; }
}

int IntStack :: size () const { return numElements ; }

int IntStack :: maxSize () const { return maxElements ; }

bool IntStack :: isEmpty () const { return numElements == 0; }

bool IntStack :: isFull () const { return numElements == maxElements ; }

void IntStack :: clear () { numElements = 0; }

string IntStack :: str () const {
    int i;
    stringstream ss ;
    ss << "|";
    for (i =0; i < numElements ; ++ i) ss << stack [ i] << "|";
        for (; i < maxElements ; ++ i) ss << " |";
    return ss . str ();
}