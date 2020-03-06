#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
    
}

Node::Node(int val) {
    value = val;
    left = NULL;
    right = NULL;
}

Node::~Node() {
	    
}
	
int Node::getData() const {
    return value;
}

Node* Node::getLeftChild() const {
    return left;  
}

Node* Node::getRightChild() const {
    return right;
}