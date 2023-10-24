#include <iostream>
#include <sstream>

using namespace std;

struct Node {
  char info;  Node *child1, *child2, *child3;
  Node(char i, Node *c1 = nullptr, Node *c2 = nullptr, Node *c3 = nullptr) {
    info = i;  child1 = c1;  child2 = c2;  child3 = c3;
    cerr << "+ Node("<< info << ") criado..." << endl;
  }
  ~Node() { cerr << "- Node("<< info << ") destruido..." << endl; }	
};

string strGraphViz(Node *root) {  stringstream ss;  /*  IMPLEMENTE AQUI */  return ss.str();  }
	
void clean(Node *root) { /* IMPLEMENTE AQUI */ }

int main() {
  Node *b    = new Node('B'),       *e = new Node('E'),
       *f    = new Node('F'),       *g = new Node('G');    // Folhas
  Node *c    = new Node('C',e,f),   *d = new Node('D',g);  // Intermediarios
  Node *root = new Node('A',b,c,d);                        // Raiz
  strGraphViz(root);
  clean(root);
  return 0;
}
