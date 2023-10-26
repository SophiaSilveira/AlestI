#include <iostream>
#include "NodeCharTree.hpp"

int main() {
  NodeCharTree *i = new NodeCharTree('I');
  NodeCharTree *j = new NodeCharTree('J');
  NodeCharTree *d = new NodeCharTree('D');
  d->addSubtree(i);
  d->addSubtree(j);
  NodeCharTree *e = new NodeCharTree('E');
  NodeCharTree *f = new NodeCharTree('F');
  NodeCharTree *b = new NodeCharTree('B');
  b->addSubtree(d);
  b->addSubtree(e);
  b->addSubtree(f);	
  NodeCharTree *k = new NodeCharTree('K');
  NodeCharTree *h = new NodeCharTree('H');
  h->addSubtree(k);
  NodeCharTree *g = new NodeCharTree('G');
  NodeCharTree *c = new NodeCharTree('C');
  c->addSubtree(g);
  c->addSubtree(h);
  NodeCharTree *root = new NodeCharTree('A');
  root->addSubtree(b);
  root->addSubtree(c);
  cout << root->strGraphViz() << endl;
  delete root;
  return 0;
}
