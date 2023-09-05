#include <iostream>
#include "IntQueue.hpp"

using namespace std ;

void print ( IntQueue & queue ) {
    cout << " " << queue . str () << " size =" << queue . size () << "/" << queue . maxSize () << " head =";
    int h; bool res = queue . head (h );
    if ( res ) cout << h; else cout << "X";
        cout << " isEmpty =" << queue . isEmpty () << " isFull =" << queue . isFull () << endl ;
}

int main () {
int e;
bool res ;
cout << " IntQueue (4): "; IntQueue queue (4); print ( queue );
e = 1; cout << " enqueue (" << e << "): "; res = queue . enqueue (e ); cout << ( res ?"OK ":" ERRO "); print ( queue );
e = 2; cout << " enqueue (" << e << "): "; res = queue . enqueue (e ); cout << ( res ?"OK ":" ERRO "); print ( queue );
e = 3; cout << " enqueue (" << e << "): "; res = queue . enqueue (e ); cout << ( res ?"OK ":" ERRO "); print ( queue );
res = queue . dequeue (e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
e = 4; cout << " enqueue (" << e << "): "; res = queue . enqueue (e ); cout << ( res ?"OK ":" ERRO "); print ( queue );
e = 5; cout << " enqueue (" << e << "): "; res = queue . enqueue (e ); cout << ( res ?"OK ":" ERRO "); print ( queue );
e = 6; cout << " enqueue (" << e << "): "; res = queue . enqueue (e ); cout << ( res ?"OK ":" ERRO "); print ( queue );
res = queue . dequeue (e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
res = queue . dequeue (e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
res = queue . dequeue (e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
res = queue . dequeue (e ); cout << " dequeue (" << e << "): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
res = queue . dequeue (e ); cout << " dequeue (X): "; cout << ( res ?"OK ":" ERRO "); print ( queue );
e = 7; cout << " enqueue (" << e << "): "; res = queue . enqueue (e ); cout << ( res ?"OK ":" ERRO "); print ( queue );
cout << " clear (): OK "; queue . clear (); print ( queue );
return 0;
}