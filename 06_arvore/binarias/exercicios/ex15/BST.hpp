#ifndef _BST_HPP
#define _BST_HPP
#include "NoteBT.hpp"

using namespace std;

template <typename T>
class BST {
    private:
        NodeBT<T> *root;
        void add(NodeBT<T> *node, NodeBT<T> *newNode);
    public:
        BST();
        ~BST();
        void add(const T &e);
        bool contains(const T &e);
        string strGraphViz() const;
};

template <typename T>
BST <T>::BST() { root = nullptr; }

template <typename T>
BST<T>::~BST() { if(root != nullptr) delete root; }

template <typename T>
void BST<T>::add(NodeBT<T> *node, NodeBT<T> *newNode){
    if( newNode->getInfo() < node->getInfo()){
        NodeBT<T> *left = node->getLeft();
        if(left == nullptr) node->addLeft(newNode);
        else add(left, newNode);
    }
    else{
         NodeBT<T> *right = node->getRight();
        if(right == nullptr) node->addRight(newNode);
        else add(right, newNode);
    }
}

template <typename T>
void BST<T>::add(const T &e){
    NodeBT<T> *newNode = new NodeBT<T>(e)
    if(root != nullptr) root = newNode;
    else add(root, newNode);
}

template <typename T>
bool BST<T>::contains(const T &e){ return true; }

template <typename T>
string BST<T>::strGraphViz() const {
    if(root != nullptr) return " "; 
    else return root->strGraphViz();
}

#endif