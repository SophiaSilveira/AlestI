#include <iostream>

using namespace std;

struct Nodo {
    char letra ;
    Nodo * prox ;
    Nodo ( char l) { letra = l ; prox = nullptr ; cout << " Nodo " << letra << " criado ... " << endl ; }
    ~Nodo () { cout << " Nodo " << letra << " destruido ..." << endl ; }
};

int main () {
   // Nodo * nodo1 = new Nodo ('A');
   // Nodo * nodo2 = new Nodo ('B');
   // Nodo * nodo3 = new Nodo ('C');
   // Nodo * nodo4 = new Nodo ('D');
   // Nodo * nodo5 = new Nodo ('E');

   // Nodo * primeiro = nodo1;
   // nodo1 -> prox = nodo2;
   // nodo2 -> prox = nodo3;
   // nodo3 -> prox = nodo4;
   // nodo4 -> prox = nodo5;

    Nodo * primeiro = nullptr, *ultimo = nullptr;

    for(char c = 'A'; c <= 'E'; ++c){
        Nodo * novo = new Nodo(c);
        if( primeiro == nullptr) primeiro = ultimo = novo;
        else{
            ultimo->prox =novo;
            ultimo = novo;
        }
        //novo->prox = primeiro;
       // primeiro = novo;
    }

    for ( Nodo * aux = primeiro ; aux != nullptr ; aux = aux -> prox )
        cout << aux -> letra << endl;
        while ( primeiro != nullptr ) {
            Nodo * aux = primeiro;
            primeiro = primeiro -> prox;
            delete aux;
        }
    return 0;
}