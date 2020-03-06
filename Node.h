#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "NodeInterface.h"

class Node : public NodeInterface {

private:
    friend class BST;
    Node* left;
    Node* right;
    int value;

public:
	Node();
	Node(int val);
	~Node();
	
	int getData() const;

	Node* getLeftChild() const;

	Node* getRightChild() const;

};
#endif