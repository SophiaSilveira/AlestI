#include <iostream>
#include <iomanip>
#include "NodeCharTree.hpp"

int main() {
  NodeCharTree *b = new NodeCharTree('B');
  b->addSubtree( new NodeCharTree('E') );
  b->addSubtree( new NodeCharTree('F') );
  NodeCharTree *c = new NodeCharTree('C');
  c->addSubtree( new NodeCharTree('G') );
  c->addSubtree( new NodeCharTree('H') );
  c->addSubtree( new NodeCharTree('I') );
  NodeCharTree *root = new NodeCharTree('A');
  root->addSubtree(b);
  root->addSubtree(c);
  root->addSubtree( new NodeCharTree('D') );
  cout << "pre-order:   " << (root->preorder()   == "A\nB\nE\nF\nC\nG\nH\nI\nD\n" ? "OK" : "ERROR") << endl;
  cout << "post-order:  " << (root->postorder()  == "E\nF\nB\nG\nH\nI\nC\nD\nA\n" ? "OK" : "ERROR") << endl;
  cout << "level-order: " << (root->levelorder() == "A\nB\nC\nD\nE\nF\nG\nH\nI\n" ? "OK" : "ERROR") << endl;
  delete root;
  return 0;
}
