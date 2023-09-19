#include <iostream>

using namespace std ;

struct Nodo {
    char letra ; 
    Nodo * prox ;
    Nodo (int l) { letra = l; prox = nullptr ; cout << " Nodo (" << letra << ") criado ... " << endl ; }
    ~ Nodo () { cout << " Nodo (" << letra << ") destruido ... " << endl ; }
};

int main () {
    Nodo * head = nullptr , * tail = nullptr ; // Cria ção

    for ( char l='B'; l <= 'F'; l ++) {
        if (l == 'D') continue ; // Evita que o nodo com a letra 'D' seja inserido na lista ...
        Nodo * nodo = new Nodo ( l );
        if ( tail == nullptr ) { head = tail = nodo ; }
        else { tail -> prox = nodo ; tail = nodo ; }
    }

    char letra;
    cin >> letra;

    Nodo *novo = new Nodo(letra);
    Nodo *ant = nullptr;
    Nodo *aux = head;

    while ( aux != nullptr && aux->letra < letra){
        ant = aux;
        aux = aux->prox;
    }

    

    cout << "head --> "; // Exibição

for ( Nodo * aux = head ; aux != nullptr ; aux = aux -> prox )
    cout << "|" << aux -> letra << ( aux -> prox == nullptr ?"|X| ":"|| -> ");
    cout << " <--tail " << endl ;
    while ( head != nullptr ) { Nodo * aux = head ; head = head -> prox ; delete aux ; } // Desaloca ção
    return 0;
}