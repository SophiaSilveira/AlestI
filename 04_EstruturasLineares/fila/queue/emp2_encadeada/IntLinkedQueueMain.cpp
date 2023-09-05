#include <iostream>
#include "IntLinkedQueue.hpp"

using namespace std ;

void print ( IntLinkedQueue & queue ) {
    cout << " " << queue . str () << " size =" << queue . size () << " head =";
    int h; bool res = queue . head (h );
    if ( res ) cout << h; else cout << "X";
    cout << " isEmpty =" << queue . isEmpty () << endl ;
}

int main () {
    int e;
    bool res ;
    cout << " IntLinkedQueue : "; IntLinkedQueue queue ; print ( queue );
    e = 1; cout << " enqueue (" << e << "): "; queue . enqueue (e ); cout << "OK "; print ( queue );
    e = 2; cout << " enqueue (" << e << "): "; queue . enqueue (e ); cout << "OK "; print ( queue );
    e = 3; cout << " enqueue (" << e << "): "; queue . enqueue (e ); cout << "OK "; print ( queue );
    res = queue . dequeue ( e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
    e = 4; cout << " enqueue (" << e << "): "; queue . enqueue (e ); cout << "OK "; print ( queue );
    e = 5; cout << " enqueue (" << e << "): "; queue . enqueue (e ); cout << "OK "; print ( queue );
    e = 6; cout << " enqueue (" << e << "): "; queue . enqueue (e ); cout << "OK "; print ( queue );
    res = queue . dequeue ( e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
    res = queue . dequeue ( e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
    res = queue . dequeue ( e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
    res = queue . dequeue ( e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
    res = queue . dequeue ( e ); cout << " dequeue (X): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
    e = 7; cout << " enqueue (" << e << "): "; queue . enqueue (e ); cout << "OK "; print ( queue );
    cout << " clear (): OK "; queue . clear (); print ( queue );
    return 0;
}