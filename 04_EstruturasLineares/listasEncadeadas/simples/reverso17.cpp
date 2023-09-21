#include <iostream>

using namespace std;

struct Node {
    int info ; Node * next ;
    Node ( int i ) { info = i ; next = nullptr ; }
};

void reverse ( Node **head , Node **tail ){
    /*Node *ant = nullptr;
    Node *aux = *head;
    *head = *tail = nullptr;

    while(aux != nullptr){
        
        Node * node = ;
        node -> next = *head ;
       *head = node;

       if ( tail == nullptr ) *tail = node;
        
       ant = aux;
       aux = aux->next;
       delete ant;
    }*/

    Node *newHead = nullptr; Node *newTail = nullptr;

    while( *head != nullptr){

        Node *aux = *head;
        *head = (*head)->next;

        if(newHead == nullptr) { newHead = newTail = aux; aux->next = nullptr;}
        else{ aux->next = newHead; newHead = aux;}
    }

    *head = newHead;
    *tail = newTail;

}

int main () {
    Node *head = nullptr , *tail = nullptr ; 

    for ( int n = 10; n < 60; n += 10) {
        Node * nodo = new Node (n);
        if ( tail == nullptr ) { head = tail = nodo;}
        else { tail->next = nodo ; tail = nodo; }
    }

    for( Node * aux = head; aux != nullptr; aux = aux->next){
        cout << aux->info << endl;
    }

    cout << endl;

    reverse(&head, &tail);

    for( Node * aux = head; aux != nullptr; aux = aux->next){
        cout << aux->info << endl;
    }

    while( head != nullptr){ Node * aux = head; head = head->next; delete aux;}

return 0;
}