#include <iostream>
#include <iomanip>
#include "NodeTree.hpp"

int main() {
  NodeTree<char> *b = new NodeTree<char>('B');
  b->addSubtree( new NodeTree<char>('E') );
  b->addSubtree( new NodeTree<char>('F') );
  NodeTree<char> *c = new NodeTree<char>('C');
  c->addSubtree( new NodeTree<char>('G') );
  c->addSubtree( new NodeTree<char>('H') );
  c->addSubtree( new NodeTree<char>('I') );
  NodeTree<char> *root = new NodeTree<char>('A');
  root->addSubtree(b);
  root->addSubtree(c);
  root->addSubtree( new NodeTree<char>('D') );
  cout << "pre-order:   " << (root->preorder()   == "A\nB\nE\nF\nC\nG\nH\nI\nD\n" ? "OK" : "ERROR") << endl;
  cout << "post-order:  " << (root->postorder()  == "E\nF\nB\nG\nH\nI\nC\nD\nA\n" ? "OK" : "ERROR") << endl;
  cout << "level-order: " << (root->levelorder() == "A\nB\nC\nD\nE\nF\nG\nH\nI\n" ? "OK" : "ERROR") << endl;
  delete root;
  return 0;
}
