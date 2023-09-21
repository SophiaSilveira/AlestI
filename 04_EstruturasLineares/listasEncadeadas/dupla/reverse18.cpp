#include <iostream>

using namespace std;

struct Node {
    int info ; Node * prev , * next ;
    Node ( int i ) { info = i ; next = nullptr ; }
};

void reverse ( Node ** head , Node ** tail );

int main(){
    Node *head = nullptr , *tail = nullptr ; 


    for ( int n = 10; n < 60; n += 10) {
        Node * nodo = new Node (n);
        if ( tail == nullptr ) { head = tail = nodo;}
        else { tail->next = nodo ; tail = nodo; }
    }

}