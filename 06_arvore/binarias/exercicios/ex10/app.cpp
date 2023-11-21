#include <iostream>
#include "NodeCharTree.hpp"

int main() {
  NodeCharTree *d = new NodeCharTree('D');
  d->addSubtree( new NodeCharTree('I') );
  d->addSubtree( new NodeCharTree('J') );
  NodeCharTree *b = new NodeCharTree('B');
  b->addSubtree(d);
  b->addSubtree( new NodeCharTree('E') );
  b->addSubtree( new NodeCharTree('F') );	
  NodeCharTree *h = new NodeCharTree('H');
  h->addSubtree( new NodeCharTree('K') );
  NodeCharTree *c = new NodeCharTree('C');
  c->addSubtree( new NodeCharTree('G') );
  c->addSubtree(h);
  NodeCharTree *root = new NodeCharTree('A');
  root->addSubtree(b);
  root->addSubtree(c);
  cout << root->strTree();
  delete root;
  return 0;
}
