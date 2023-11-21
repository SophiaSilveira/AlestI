#include "NodeCharTree.hpp"
#include <sstream>
  
NodeCharTree::NodeCharTree(char i){
    info = i;
    parent = nullptr;
}; // Cria um nodo com o caractere i, e sem pai

NodeCharTree::~NodeCharTree(){
    for(int i = 0; i < childs.size(); i++)
        delete childs[i];

} // Destrói o nodo atual e seus descendentes
 
char NodeCharTree::getInfo() const{
    return info;
} // Retorna o caractere armazenado no nodo atual

void NodeCharTree::setInfo(char i){
    info = i;
} // Altera o caractere armazenado no nodo atual
NodeCharTree*  NodeCharTree::getParent() const{
    return parent;
}  // Retorna a referência para o nodo-pai do nodo atual

NodeCharTree * NodeCharTree::getChild(int index) const{
    if(index >= childs.size() || index < 0) return nullptr;
    return childs[index];
} // Retorna a referência para o nodo-fiho de índice index ou nullptr

bool NodeCharTree::isRoot() const{
    return parent == nullptr;
}  // Retorna true se o nodo for raiz

bool NodeCharTree::isInternal() const{
    return parent != nullptr && childs.size() != 0;
} // Retorna true se o nodo for interno

bool NodeCharTree::isExternal() const{
    return childs.size() == 0;
}  // Retorna true se o nodo for externo

int NodeCharTree::degree() const{
    return childs.size();
}  // Retorna o grau (número de filhos) do nodo atual

int NodeCharTree::depth() const{
    NodeCharTree * aux = parent;
    int depth = 0;
    while (aux != nullptr){
        depth++;
        aux = aux->getParent();
    }
    
    return depth;
}  // Retorna o nível do nodo atual

int NodeCharTree::height() const{
    int res = 0;
    for ( int i=0; i < childs.size(); ++ i) {
        int h = 1+ childs[i]->height();
        if (h > res ) res = h;
    }
    return res ;
}// Retorna a altura da subárvore/árvore a partir do nodo atual

int NodeCharTree::size() const{
    int size = 1;
    for ( int i=0; i < childs.size(); ++ i) {
        size += childs[i]->size();
    }
    return size;
} // Retorna o número de nodos a partir do nodo atual

void NodeCharTree::addSubtree(NodeCharTree *subtree){
    if(subtree == nullptr) return;
    childs.push_back(subtree);
    subtree->parent = this;
}// Adiciona uma subárvore como filho do nodo atual

bool NodeCharTree::removeSubtree(NodeCharTree *subtree){
    for ( int i=0; i < childs.size(); ++ i) {
       if(subtree == childs[i]) {
        childs.erase(childs.begin() + i);
        return true;
       }
    }

    return false;
}// Remove a subárvore dentre os filhos do atual (true indica sucesso)

bool NodeCharTree::contains(char i) const{
    if (info == i) return true;

    for ( int i=0; i < childs.size(); ++ i) {
       if(i == childs[i]->info) {
        return true;
       }
    }

    return false;
}// Retorna true se o nodo atual ou algum de seus descendentes contivere i

NodeCharTree const * NodeCharTree::find(char i) const{
    if (info == i) return this;

    for ( int i=0; i < childs.size(); ++ i) {
        NodeCharTree const * child = childs[i]-> find (i );
        if ( child != nullptr ) return child ;
    }

    return nullptr;
}    // Retorna a referência para o nodo, a partir do atual, que contém i ou nullptr

string NodeCharTree :: strGraphVizNode ( NodeCharTree const * node ) const {
    stringstream ss ;
    for ( int i =0; i < node -> childs.size (); ++ i)
    ss << " " << node -> info << " -- " << node -> childs [i ]-> info << endl <<    strGraphVizNode ( node -> childs [i ]);
    return ss . str ();
}

string NodeCharTree :: strGraphViz () const {
    stringstream ss ;
    ss << " graph NodeCharTree {" << endl << " node [ shape = circle ]" << endl <<  strGraphVizNode ( this ) << "}" << endl ;
    return ss . str ();
}