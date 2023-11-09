#include <vector>

using namespace std;

#ifndef _INTBTREE_HPP
#define _INTBTREE_HPP
class IntBTree {
private:
  struct Node {
    int info;
    Node *parent, *left, *right;
    Node(int i) { info = i;  parent = left = right = nullptr; }
    ~Node() { delete left; delete right; }
  };
  Node *root;
public:
  IntBTree();                        // Cria a árvore de inteiros vazia (root = nullpr;)
  ~IntBTree();                       // Desaloca os nodos da árvore de inteiros (clear();)
  bool addRoot(int info);            // Adiciona info como raiz (false se a árvore não está vazia)
  int  getRoot();                    // Retorna o elemento armazenado na raiz
  void setRoot(int info);            // Altera o elemento armazenado na raiz
  bool addLeft(int node, int info);  // Adiciona info como filho da esquerda de node (false se node não existir)
  bool addRight(int node, int info); // Adiciona info como filho da direita de node (false se node não existir)
  bool hasLeft(int info);            // Retorna true se info possui subárvore na esquerda
  bool hasRight(int info);           // Retorna true se info possui subárvore na direita
  int getLeft(int info);             // Retorna o filho à esquerda de info
  int getRight(int info);            // Retorna o filho à direita de info
  int getParent(int info);           // Retorna o pai do nodo que contém info
  bool isRoot(int e);                // Retorna true se o elemento info está armazenado na raiz
  bool isInternal(int info);         // Retorna true se o elemento info está armazenado em um nodo interno
  bool isExternal(int info);         // Retorna true se o elemento info está armazenado em um nodo externo
  bool isEmpty();                    // Retorna true se a árvore está vazia (return root==nullptr;)
  bool contains(int info);           // Retorna true se a árvore contém o elemento info
  int removeBranch(int info);        // Remove o elemento que contém info e seus filhos
  int size();                        // Retorna o número de elementos armazenados na árvore
  void clear();                      // Remove todos os elementos da árvore (delete root;)
  vector<int> preorder();            // Retorna um vetor com todos os elementos da árvore na ordem pré-fixada
  vector<int> postorder();           // Retorna um vetor com todos os elementos da árvore na ordem pos-fixada
  vector<int> inorder();             // Retorna um vetor com todos os elementos da árvore na ordem in-fixada
  vector<int> levelorder();          // Retorna um vetor com todos os elementos da árvore na ordem em largura
};
#endif
