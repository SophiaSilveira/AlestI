#include <iostream>

using namespace std;

struct Node {
  int info;
  Node *prev, *next;
  Node (int i) { info = i; prev = next = nullptr; }
};

int main() {
  Node *head = nullptr , *tail = nullptr;
  char c;
  int v;
  Node *aux;
  bool fim = false;
  while (!fim) {
    cin >> c;
    switch(c) {
      case '<':
           cin >> v;
           aux = new Node(v);
           // Insercao no inicio
           if ( head == nullptr )
              head = tail = aux;
           else {
              aux->next = head;
              head->prev = aux;
              head = aux;
           }
           break;
      case '>':
           cin >> v;
           aux = new Node(v);
           // Insercao no final
           if ( head == nullptr )
              head = tail = aux;
           else {
              tail->next = aux;
              aux->prev = tail;
              tail = aux;
           }
           break;
      case '.':
           fim = true;
           break;
    }
    // mostrar
    aux = head;
    while ( aux != nullptr ) {
      cout << "|" << aux->info;
      aux = aux->next;
    }
    cout << "|" << endl;
  }
  // Desalocacao
  while ( head != nullptr ) {
    aux = head;
    head = head->next;
    delete aux;
  }
  return 0;
}
