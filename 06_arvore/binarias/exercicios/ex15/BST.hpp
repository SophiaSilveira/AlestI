#ifndef _BST_HPP
#define _BST_HPP
#include "NodeBT.hpp"

using namespace std;
template <typename T>
class BST {
    private :
        void add ( NodeBT <T > * node , NodeBT <T > * newNode );
        bool contains ( NodeBT <T > * node , const T &e );
        NodeBT <T > * root ;
    public :
        BST ();
        ~BST ();
        string strGraphViz () const ;
        void add ( const T &e );
        bool contains ( const T & e );
};

template <typename T>
    BST <T>::BST () {
    root = nullptr ;
}

template <typename T>
BST <T>::~BST () {
    if ( root != nullptr ) delete root ;
}

template <typename T>
string BST <T>::strGraphViz () const {
    if ( root == nullptr ) return ""; else return root -> strGraphViz ();
}

template <typename T>
void BST <T>::add ( NodeBT <T> * node , NodeBT <T> * newNode ) {
    if ( newNode->getInfo() < node->getInfo() ) { // Left
        NodeBT <T> * left = node->getLeft();
        if ( left == nullptr ) node->setLeft( newNode );
        else add ( left , newNode );
    }
    else { // Right
        NodeBT <T> * right = node -> getRight ();
        if ( right == nullptr ) node -> setRight ( newNode );
        else add ( right , newNode );
    }
}

template <typename T>
void BST <T>::add ( const T &e) {
    NodeBT <T> * newNode = new NodeBT <T >( e );
    if ( root == nullptr ) root = newNode ;
    else add ( root , newNode );
}

template <typename T>
bool BST <T>::contains ( NodeBT <T> * node , const T &e) {
    if ( e == node - > getInfo () ) return true ;
    if ( e < node -> getInfo () ) { // Left
        NodeBT <T> * left = node -> getLeft ();
        if ( left == nullptr ) return false ;
        else return contains ( left ,e );
    }
    else { // Right
        NodeBT <T> * right = node -> getRight ();
        if ( right == nullptr ) return false ;
        else return contains ( right ,e );
    }
}

template <typename T>
bool BST <T>::contains ( const T &e) {
    if ( root == nullptr ) return false ;
    return contains ( root , e );
}
# endif