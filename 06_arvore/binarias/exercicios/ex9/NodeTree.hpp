//desafio pg 103
#ifndef _NODETREE_HPP
#define _NODETREE_HPP
#ifdef DEBUG
# include <iostream >
#endif
#include <vector >
#include <sstream >
using namespace std ;
template <typename T >
class NodeTree {
private :
T info ; NodeTree * parent ; vector < NodeTree *> childs ;
string strGraphVizNode ( NodeTree const * node ) const ; // Imprime as conex ões de um nodo com seus filhos em GraphViz
public :
NodeTree (T const &i ); // Cria um nodo com o caractere i, e sem pai
~ NodeTree (); // Destr ói o nodo atual e seus descendentes
T getInfo () const ; // Retorna o caractere armazenado no nodo atual
void setInfo ( T &i ); // Altera o caractere armazenado no nodo atual
NodeTree * getParent () const ; // Retorna a refer ê ncia para o nodo - pai do nodo atual
NodeTree * getChild ( int index ) const ; // Retorna a refer ê ncia para o nodo - fiho de í ndice index ou nullptr
bool isRoot () const ; // Retorna true se o nodo for raiz
bool isInternal () const ; // Retorna true se o nodo for interno
bool isExternal () const ; // Retorna true se o nodo for externo
int degree () const ; // Retorna o grau (nú mero de filhos ) do nodo atual
int depth () const ; // Retorna o ní vel do nodo atual
int height () const ; // Retorna a altura da sub á rvore /á rvore a partir do nodo atual
int size () const ; // Retorna o nú mero de nodos a partir do nodo atual
void addSubtree ( NodeTree * subtree ); // Adiciona uma subá rvore como filho do nodo atual
bool removeSubtree ( NodeTree * subtree ); // Remove a sub á rvore dentre os filhos do atual ( true indica sucesso )
bool contains (T &i ) const ; // Retorna true se o nodo atual ou algum de seus descendentes contivere i
NodeTree const * find (T const & i) const ; // Retorna a refer ê ncia para o nodo , a partir do atual , que cont ém i ou nullptr
string strGraphViz () const ; // Gera uma representa ção da á rvore a partir do nodo atual no formato GraphViz
string preorder () const ; // Gera uma cadeia de caracteres (um nodo por linha ) em pré-ordem
string postorder () const ; // Gera uma cadeia de caracteres (um nodo por linha ) em pós- ordem
string levelorder () const ; // Gera uma cadeia de caracteres (um nodo por linha ) em largura
};
