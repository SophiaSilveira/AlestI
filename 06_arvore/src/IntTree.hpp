#include <vector>

using namespace std;

#ifndef _INTTREE_HPP
#define _INTTREE_HPP
class IntTree {
private:
  struct Node {
    int info;
    Node *parent;
    vector<Node *> childs;
    Node(int i) { info = i;  parent = nullptr; }
    ~Node() { for (int i=0; i<childs.size(); ++i) delete childs[i]; }
  };
  Node *root;
public:
  IntTree();                    // Cria a árvore de inteiros vazia (root = nullpr;)
  ~IntTree();                   // Desaloca os nodos da árvore de inteiros (clear();)
  bool add(int node, int info); // Adiciona info como filho de node
  int  getRoot();               // Retorna o elemento armazenado na raiz
  void setRoot(int info);       // Altera o elemento armazenado na raiz
  int getParent(int info);      // Retorna o pai do nodo que contém info
  int removeBranch(int info);   // Remove o elemento que contém info e seus filhos
  bool contains(int info);      // Retorna true se a árvore contém o elemento info
  bool isInternal(int info);    // Retorna true se o elemento info está armazenado em um nodo interno
  bool isExternal(int info);    // Retorna true se o elemento info está armazenado em um nodo externo
  bool isRoot(int e);           // Retorna true se o elemento info está armazenado na raiz
  bool isEmpty();               // Retorna true se a árvore está vazia (return root==nullptr;)
  int size();                   // Retorna o número de elementos armazenados na árvore
  void clear();                 // Remove todos os elementos da árvore (delete root;)
  vector<int> preorder();       // Retorna um vetor com todos os elementos da árvore na ordem pré-fixada
  vector<int> postorder();      // Retorna um vetor com todos os elementos da árvore na ordem pos-fixada
  vector<int> levelorder();     // Retorna um vetor com todos os elementos da árvore na ordem em largura
};
#endif
