#include <sstream>
#include "CharStack.hpp"

CharStack :: CharStack (int mxSz ) {
    if ( mxSz < 1 ) mxSz = 10;
    maxElements = mxSz;
    stack = new char [ maxElements ];
    numElements = 0;
}

CharStack ::~ CharStack () { delete [] stack; }

bool CharStack :: push ( const char &e) {
    if ( numElements == maxElements ) return false;
    else { stack [ numElements ++ ] = e; return true; }
}

bool CharStack :: pop ( char &e ) {
    if ( numElements == 0 ) return false ;
    else { e = stack [ -- numElements ]; return true ; }
}

bool CharStack :: top ( char &e ) const {
    if ( numElements < 1 ) return false ;
    else { e = stack [ numElements -1 ]; return true ; }
}

int CharStack :: size () const { return numElements ; }

int CharStack :: maxSize () const { return maxElements ; }

bool CharStack :: isEmpty () const { return numElements == 0; }

bool CharStack :: isFull () const { return numElements == maxElements ; }

void CharStack :: clear () { numElements = 0; }

string CharStack :: str () const {
    int i;
    stringstream ss ;
    ss << "|";
    for (i =0; i < numElements ; ++ i) ss << stack [ i] << "|";
        for (; i < maxElements ; ++ i) ss << " |";
    return ss . str ();
}