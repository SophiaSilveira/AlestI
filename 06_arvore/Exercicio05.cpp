#include <iostream>
#include <sstream>

using namespace std;

struct Node {
  char info;  
  Node *left, *right, *parent;
  Node(char i, Node *l = nullptr, Node *r = nullptr) {
    info = i;  left = l;  right = r;
    parent = nullptr;

    if(left != nullptr) left->parent = this;
    if(right != nullptr) right->parent = this;

    cerr << "+ Node("<< info << ") criado..." << endl;
  }
  ~Node() { 
        if(left != nullptr) delete left;
        if(right != nullptr) delete right;
        cerr << "- Node("<< info << ") destruido..." << endl; 
    }	
};

string strChild( Node * root){
    stringstream ss;
    if(root->left != nullptr){
        ss << " " << root->info << " -- " << root->left->info << endl << strChild(root->left);
    } 
    if(root->right != nullptr){
        ss << " " << root->info << " -- " << root->right->info << endl << strChild(root->right);
    } 
    return ss.str();
};

string strGraphViz ( Node * root ) { 
    stringstream ss;

    ss << "graph \"Árvore\" {" << endl << " node[shape=circle]" << endl;
    ss << strChild(root) << "}" << endl;

    return ss.str(); 
}

//criar método para contar os nodos de uma subárvore

int size(Node *subtree){
    if(subtree == nullptr) return 0;
    return int res = 1 + size(subtree->left) + size(subtree->right);
}

//contar filhos
int degree(Node *subtree){
    return 0;
}

//dizer o profundidade;
int depth(Node *subtree){
    return 0;
}

//profundidade da arvore;
int treeDepth(Node *subtree){
    return 0;
}

int main() { 
  Node *b = new Node('B',new Node('D'),new Node('E'));
  Node *f = new Node('F', new Node('H'));
  Node *c = new Node('C', f, new Node('G')); 
  Node *root = new Node('A', b, c);      

  cout << strGraphViz(root) << endl;
  
  cout << "Quantidade de nodos da arvore = " << size(root) << endl;
  cout << "Nivel de nodos da arvore = " << treeDepth(root) << endl;
  cout << "Grau do nodo (" << f->info << ") = " << degree(f) << endl;
  cout << "Nivel do nodo (" << f->info << ") = " << depth(f) << endl;

  delete root;
  return 0;
}
