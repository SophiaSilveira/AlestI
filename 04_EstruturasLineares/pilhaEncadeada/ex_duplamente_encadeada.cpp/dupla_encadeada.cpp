#include <iostream>

using namespace std;

struct Nodo {
    int num;
    Nodo * ant;
    Nodo * prox;
    Nodo ( int l) { 
        num = l ; ant = nullptr; prox = nullptr;
        cout << " Nodo " << num << " criado ... " << endl; }
    ~Nodo () { cout << " Nodo " << num << " destruido ..." << endl ; }
};

int main () {
    Nodo * primeiro = nullptr;

    int insere = 0;

    cin >> insere;

    while(insere != -1){ 
        Nodo * novo = new Nodo(insere);
        novo->prox = primeiro;
        //primeiro -> ant = novo;
        //primeiro apontar pro novo
        primeiro = novo;
        cin >> insere;
    }


    for ( Nodo * aux = primeiro ; aux != nullptr ; aux = aux -> prox ){
        cout << aux -> ant << " | " << aux -> num << " | " << aux -> prox->num == nullptr ? 0 : aux -> prox->num << endl;
    }
       

    while ( primeiro != nullptr ) {
        Nodo * aux = primeiro;
        primeiro = primeiro -> prox;
        delete aux;
    }

    return 0;
}