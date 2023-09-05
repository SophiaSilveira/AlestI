#include <sstream>
#include "IntQueue.hpp"

IntQueue :: IntQueue (int mxSz ) {
    numElements = insertPos = removePos = 0; maxElements = ( mxSz < 1 ) ? 10 : mxSz ; queue = new int [ maxElements ];
}

IntQueue ::~ IntQueue () { delete [] queue ; }

int IntQueue :: size () const { return numElements ; }

int IntQueue :: maxSize () const { return maxElements ; }

bool IntQueue :: isEmpty () const { return numElements == 0; }

bool IntQueue :: isFull () const { return numElements == maxElements ; }

void IntQueue :: clear () { numElements = insertPos = removePos = 0; }

bool IntQueue :: enqueue ( const int &e ) {
    if ( numElements == maxElements ) return false ;
    else { queue [ insertPos ++ ] = e ; insertPos %= maxElements ; ++ numElements ; return true ; }
}

bool IntQueue :: dequeue ( int &e) {
    if ( numElements == 0 ) return false ;
    else { e = queue [ removePos ++ ]; removePos %= maxElements ; -- numElements ; return true ; }
}

bool IntQueue :: head ( int & e) const {
    if ( numElements < 1 ) return false ;
    else { e = queue [ removePos ]; return true ; }
}

string IntQueue :: str () const {
    stringstream ss ; ss << "|";
    for ( int i =0; i < maxElements ; ++ i )
    if ( ( removePos == insertPos && numElements != 0) ||
        ( removePos < insertPos && (i >= removePos && i < insertPos )) ||
        ( removePos > insertPos && (i >= removePos || i < insertPos )) ) ss << queue [i] << "|";
    else ss << " |";
    return ss . str ();
}