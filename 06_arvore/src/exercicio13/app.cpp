#include <iostream>
#include <iomanip>
#include "NodeBT.hpp"

void showTree(NodeBT<char> *root) {
  string s = "XYEZDAWBC*";  char c = 'C', l = 'L';
  cout << endl << root->strGraphViz() << endl;
  cout << "N Pa iR iI iE dg dp hg sz fC fL" << endl;	
  for (int i=0; i<s.length(); ++i) {
      char letter = s[i];
      NodeBT<char> const *node = root->find(letter);
      if (node == nullptr) { cout << letter << "  *  *  *  *  *  *  *  *  *  *" << endl; continue; }
      NodeBT<char> *parent = node->getParent();
      char parentInfo = (node->getParent() == nullptr)?'*':parent->getInfo();
      cout << letter << " " << setw(2) << parentInfo << " ";
      cout << setw(2) << node->isRoot() << " " << setw(2) << node->isInternal() << " " << setw(2) << node->isExternal() << " ";
      cout << setw(2) << node->degree() << " " << setw(2) << node->depth() <<  " " << setw(2) << node->height() <<  " ";
      cout << setw(2) << node->size() << " " << setw(2) << node->contains(c) << " " << setw(2) << node->contains(l) << endl;
  }
}

int main() {
  NodeBT<char> *w    = new NodeBT<char>('W');  w->addLeft ( new NodeBT<char>('B') );  w->addRight( new NodeBT<char>('C') );
  NodeBT<char> *z    = new NodeBT<char>('Z');  z->addLeft ( new NodeBT<char>('A') );  z->addRight( w );
  NodeBT<char> *y    = new NodeBT<char>('Y');  y->addLeft ( z );                      y->addRight( new NodeBT<char>('D') );
  NodeBT<char> *root = new NodeBT<char>('X');  root->addLeft ( y );                   root->addRight( new NodeBT<char>('E') );
  cout << "pre-order:   " << (root->preorder()   == "X\nY\nZ\nA\nW\nB\nC\nD\nE\n" ? "OK" : "ERROR") << endl;
  cout << "post-order:  " << (root->postorder()  == "A\nB\nC\nW\nZ\nD\nY\nE\nX\n" ? "OK" : "ERROR") << endl;
  cout << "in-order:    " << (root->inorder()    == "A\nZ\nB\nW\nC\nY\nD\nX\nE\n" ? "OK" : "ERROR") << endl;
  cout << "level-order: " << (root->levelorder() == "X\nY\nE\nZ\nD\nA\nW\nB\nC\n" ? "OK" : "ERROR") << endl;
  showTree( root );
  z->removeRight();    showTree( root );
  root->removeLeft();  showTree( root );
  delete root;
  return 0;
}
