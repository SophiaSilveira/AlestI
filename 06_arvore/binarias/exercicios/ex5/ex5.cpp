#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    char info ; Node * parent ; Node * left , * right ;
    Node ( char i , Node *l = nullptr , Node *r = nullptr ) {
        info = i; left = l; right = r; parent = nullptr ;
        if ( left != nullptr ) left -> parent = this ;
        if ( right != nullptr ) right -> parent = this ;
        # ifdef DEBUG
        cerr << "+ Node (" << info << ") criado ... " << endl ;
        # endif
    }

~Node () {
    if ( left != nullptr ) delete left ;
    if ( right != nullptr ) delete right ;
    # ifdef DEBUG
    cerr << "- Node (" << info << ") destruido ..." << endl ;
    # endif
    }
};

string strNode ( Node * Node ) {
    stringstream ss ;
    if ( Node -> left != nullptr ) ss << " " << Node -> info << " -- " << Node -> left -> info << endl << strNode ( Node -> left );
    if ( Node -> right != nullptr ) ss << " " << Node -> info << " -- " << Node -> right -> info << endl << strNode ( Node -> right );
    return ss . str ();
}

string strGraphViz ( Node * root ) {
    stringstream ss ;
    ss << " graph \" Arvore Bin á ria \" {" << endl << " Node [ shape = circle ]" << endl << strNode ( root ) << "}" << endl ;
    return ss . str ();
}

int degree ( Node * subtree ) { 
    int f = 0;
    if(subtree->left != nullptr) f++;
    if(subtree->right != nullptr) f++;
    return f;
} 

int depth ( Node * subtree ) { 
    if (subtree == nullptr) return 0; 
    if (subtree->parent == nullptr) return 0;
    return 1 + depth(subtree->parent);
}

int height ( Node * subtree ) { 
    if (subtree == nullptr) return 0; 
    int esq = 0, dire = 0;

    if (subtree->left != 0) esq = 1 + height(subtree->left);
    if (subtree->right != 0) dire = 1 + height(subtree->right);
    
    return esq > dire ? esq : dire; 
}

int size ( Node * subtree ) { 
    if (subtree == nullptr) return 0;
    return  1 + size(subtree->left) + size(subtree->right); 
}

int main () {
    Node *d = new Node ('D');
    Node *b = new Node ('B',d , new Node ('E'));
    Node *f = new Node ('F',new Node ('H'), new Node ('I'));
    Node *c = new Node ('C',f , new Node ('G'));
    Node * root = new Node ('A',b , c );
    cout << strGraphViz ( root );
    cout << " degree ( root ): " << degree ( root ) << " [2] " << endl ;
    cout << " degree (b): " << degree ( b) << " [2] " << endl ;
    cout << " degree (d): " << degree ( d) << " [0] " << endl ;
    cout << " depth ( root ): " << depth ( root ) << " [0] " << endl ;
    cout << " depth (b): " << depth (b ) << " [1] " << endl ;
    cout << " depth (f): " << depth (f ) << " [2] " << endl ;
    cout << " size ( root ): " << size ( root ) << " [9]" << endl ;
    cout << " size (b): " << size (b) << " [3] " << endl ;
    cout << " size (c): " << size (c) << " [5] " << endl ;
    cout << " height ( root ): " << height ( root ) << " [3] " << endl ;
    cout << " height (b): " << height ( b) << " [1] " << endl ;
    cout << " height (c): " << height ( c) << " [2] " << endl ;
    delete root ;
    return 0;
}