#include <vector>
#include <string>

using namespace std;

#ifndef _NODECHARTREE_HPP
#define _NODECHARTREE_HPP
class NodeCharTree {
private:
  char info;
  NodeCharTree *parent;
  vector<NodeCharTree *> childs;
  string strGraphVizNode(NodeCharTree const *node) const;       // Imprime as conexões de um nodo com seus filhos em GraphViz
  string strTreeNode(NodeCharTree const *node,string s) const;  // Imprime nodos da árvore
public:
  NodeCharTree(char i);                        // Cria um nodo com o caractere i, e sem pai
  ~NodeCharTree();                             // Destrói o nodo atual e seus descendentes
  char getInfo() const;                        // Retorna o caractere armazenado no nodo atual
  void setInfo(char i);                        // Altera o caractere armazenado no nodo atual
  NodeCharTree *getParent() const;             // Retorna a referência para o nodo-pai do nodo atual
  NodeCharTree *getChild(int index) const;     // Retorna a referência para o nodo-fiho de índice index ou nullptr
  bool isRoot() const;                         // Retorna true se o nodo for raiz
  bool isInternal() const;                     // Retorna true se o nodo for interno
  bool isExternal() const;                     // Retorna true se o nodo for externo
  int degree() const;                          // Retorna o grau (número de filhos) do nodo atual
  int depth() const;                           // Retorna o nível do nodo atual
  int height() const;                          // Retorna a altura da subárvore/árvore a partir do nodo atual
  int size() const;                            // Retorna o número de nodos a partir do nodo atual
  void addSubtree(NodeCharTree *subtree);      // Adiciona uma subárvore como filho do nodo atual
  bool removeSubtree(NodeCharTree *subtree);   // Remove a subárvore dentre os filhos do atual (true indica sucesso)
  bool contains(char i) const;                 // Retorna true se o nodo atual ou algum de seus descendentes contivere i
  NodeCharTree const *find(char i) const;      // Retorna a referência para o nodo, a partir do atual, que contém i ou nullptr
  string strGraphViz() const;                  // Gera uma representação da árvore a partir do nodo atual no formato GraphViz
  string preorder() const;                     // Gera uma cadeia de caracteres (um nodo por linha) em pré-ordem
  string postorder() const;                    // Gera uma cadeia de caracteres (um nodo por linha) em pós-ordem
  string levelorder() const;                   // Gera uma cadeia de caracteres (um nodo por linha) em largura
  string strTree() const;                      // Gera uma representação da árvore usando caracteres
};
#endif
