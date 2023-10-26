#include <iostream>
#include <iomanip>
#include "NodeCharTree.hpp"

void showTree(NodeCharTree *root) {
  cout << root->strGraphViz() << endl;
  cout << "N Pa iR iI iE dg dp sz fJ fL" << endl;	
  for (char letter='A'; letter<='L'; ++letter) {
      NodeCharTree const *node = root->find(letter);
      if (node == nullptr) { cout << letter << "  *  *  *  *  *  *  *  *  *" << endl; continue; }
      NodeCharTree *parent = node->getParent();
      char parentInfo = (node->getParent() == nullptr)?'*':parent->getInfo();
      cout << letter << " " << setw(2) << parentInfo << " ";
      cout << setw(2) << node->isRoot() << " " << setw(2) << node->isInternal() << " " << setw(2) << node->isExternal() << " ";
      cout << setw(2) << node->degree() << " " << setw(2) << node->depth() <<  " " << setw(2) << node->size() << " ";
      cout << setw(2) << node->contains('J') << " " << setw(2) << node->contains('L') << endl;
  }
}

int main() {
  NodeCharTree *d = new NodeCharTree('D');     d->addSubtree( new NodeCharTree('I') );
                                               d->addSubtree( new NodeCharTree('J') );
  NodeCharTree *b = new NodeCharTree('B');     b->addSubtree(d);
                                               b->addSubtree( new NodeCharTree('E') );
                                               b->addSubtree( new NodeCharTree('F') );	
  NodeCharTree *h = new NodeCharTree('H');     h->addSubtree( new NodeCharTree('K') );
  NodeCharTree *c = new NodeCharTree('C');     c->addSubtree( new NodeCharTree('G') );
                                               c->addSubtree(h);
  NodeCharTree *root = new NodeCharTree('A');  root->addSubtree(b);
                                               root->addSubtree(c);
  showTree(root);
  b->removeSubtree(d);
  showTree(root);
  root->removeSubtree(b);
  showTree(root);
  delete root;
  return 0;
}
