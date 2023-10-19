# include <iostream>
# include <sstream>

using namespace std;
struct Node {
    char info ; Node * child1 , * child2 , * child3 ;
    Node ( char i , Node * c1 = nullptr , Node * c2 = nullptr , Node * c3 = nullptr ) {
    info = i ; child1 = c1 ; child2 = c2 ; child3 = c3 ;
    cerr << "+ Node (" << info << ") criado ... " << endl ;
}

    ~ Node () { cerr << "- Node (" << info << ") destruido ... " << endl ; }
};

string strChild( Node * root){
    stringstream ss;
    if(root->child1 != nullptr){
        ss << " " << root->info << " -- " << root->child1->info << endl;
        ss << strChild(root->child1);
    } 
    if(root->child2 != nullptr){
        ss << " " << root->info << " -- " << root->child2->info << endl;
        ss << strChild(root->child2);
    } 
    if(root->child3 != nullptr){
        ss << " " << root->info << " -- " << root->child3->info << endl;
        ss << strChild(root->child3);
    } 

    return ss.str();
};

string strGraphViz ( Node * root ) { 
    stringstream ss;

    ss << "graph \"Árvore\" {" << endl;
    ss << " node[shape=circle]" << endl;
    ss << strChild(root);
    ss << "}" << endl;

    return ss.str(); 
}

void clean ( Node * root ) { 
    if(root == nullptr) return;
    clean(root->child1);
    clean(root->child2);
    clean(root->child3);
    delete root;
}

int main () {
    Node *b = new Node ('B'), *e = new Node ('E'),
    *f = new Node ('F'), * g = new Node ('G'); // Folhas
    Node *c = new Node ('C',e ,f), *d = new Node ('D',g ); // Intermediarios
    Node * root = new Node ('A',b ,c ,d ); // Raiz
    cout << strGraphViz ( root );
    clean ( root );
    return 0;
}