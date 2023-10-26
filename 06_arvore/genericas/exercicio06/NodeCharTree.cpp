
#include "NodeCharTree.hpp"
#include <sstream>

NodeCharTree::NodeCharTree(char i){

}   // Cria um nodo com o caractere i, e sem pai

NodeCharTree::~NodeCharTree(){

}                    // Destrói o nodo atual e seus descendentes

char NodeCharTree::getInfo() const{
    return ' ';
}                        // Retorna o caractere armazenado no nodo atual

NodeCharTree *NodeCharTree::getParent() const{
    return nullptr;
}             // Retorna a referência para o nodo-pai do nodo atual

NodeCharTree *NodeCharTree::getChild(int index) const{
    return nullptr;
}     // Retorna a referência para o nodo-fiho de índice index ou nullptr

bool NodeCharTree::isRoot() const{
    return false;
}                         // Retorna true se o nodo for raiz

bool NodeCharTree::isInternal() const{
    return false;
}                     // Retorna true se o nodo for interno


bool NodeCharTree::isExternal() const{
    return false;
}                     // Retorna true se o nodo for externo

int NodeCharTree::degree() const{
    return 0;
}                          // Retorna o grau (número de filhos) do nodo atual

int NodeCharTree::depth() const{
    return 0;
}                           // Retorna o nível do nodo atual

int NodeCharTree::size() const{
    return 0;
}                            // Retorna o número de nodos a partir do nodo atual

void NodeCharTree::addSubtree(NodeCharTree *subtree){
    if(subtree == nullptr) return;

    childs.push_back(subtree);
    subtree->parent = this;
}      // Adiciona uma subárvore como filho do nodo atual

bool NodeCharTree::removeSubtree(NodeCharTree *subtree){
    return false;
}   // Remove a subárvore dentre os filhos do atual (true indica sucesso)

bool NodeCharTree::contains(char i) const{
    return false;
}                 // Retorna true se o nodo atual ou algum de seus descendentes contivere i

NodeCharTree const *NodeCharTree::find(char i) const{
    return nullptr;
}      // Retorna a referência para o nodo, a partir do atual, que contém i ou nullptr

string NodeCharTree::strGraphViz() const{
    stringstream ss;
    ss << " graph \" Arvore Binária \" {" << endl << " Node [ shape = circle ]" << endl << strNode ( root ) << "}" << endl ;
    return ss . str ();
}                  // Gera uma representação da árvore a partir do nodo atual no formato GraphViz

