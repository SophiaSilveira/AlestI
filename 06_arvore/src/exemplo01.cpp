#include <iostream>

using namespace std;

struct Node {
  char info;  Node *child1, *child2, *child3;
  Node(char i, Node *c1 = nullptr, Node *c2 = nullptr, Node *c3 = nullptr) {
    info = i;  child1 = c1;  child2 = c2;  child3 = c3;
    cout << "+ Node("<< info << ") criado..." << endl;
  }
  ~Node() { cout << "- Node("<< info << ") destruido..." << endl; }	
};

int main() {
  Node *b    = new Node('B'),        *e = new Node('E'),
       *f    = new Node('F'),        *g = new Node('G');    // Cria folhas
  Node *c    = new Node('C',e,f),    *d = new Node('D',g);  // Cria intermediarios
  Node *root = new Node('A',b,c,d);                         // Cria raiz

  delete b;  delete e;  delete f;  delete g;  // Desaloca folhas
  delete c;  delete d;                        // Desaloca intermediarios
  delete root;                                // Desaloca raiz

  return 0;
}
