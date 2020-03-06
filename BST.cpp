#include <iostream>

#include "BST.h"

using namespace std;

BST::BST() {
	
}

BST::~BST() {
    clear();
}
    
Node* BST::getRootNode() const {
    return root;
}

bool BST::add(int data) {
	return insert(root, data);
}

bool BST::insert(Node* &T, int data) {
	if (T == NULL) {
		T = new Node(data);
		return true;
	}
	if (T->value == data) {
		return false;
	}
	if (data > T->value) {
		return insert(T->right, data);
	}
	else {
		return insert(T->left, data);
	}
}

bool BST::remove(int data) {
	return removerecursive(root, data);
}

bool BST::removerecursive(Node* &T, int data) {
    if (T == NULL) {
		return false;
	}
	if (T->value == data) {
		// I need to erase this node
		Node *victim = T;
		if (T->left == NULL) {
			T = T->right;
		}
		else if (T->right == NULL) {
			T = T->left;
		}
		else {
			replace_parent(victim, victim->left);
		}
		delete victim;
		return true;
	}
	if (data > T->value) {
		return removerecursive(T->right, data);
	} else {
		return removerecursive(T->left, data);
	}
}

void BST::replace_parent(Node* &old_root, Node* &local_root) {
	if (local_root->right != NULL) {
		replace_parent(old_root, local_root->right);
	}
	else {
	    old_root->value = local_root->value;
	    old_root = local_root;
	    local_root = local_root->left;
	}
}

void BST::clear() {
    while (root != NULL) {
    	remove(root->value);
    }
}

bool BST::find(Node* T, int data) {
    if (T == NULL) {
		return false;
	}
	if (T->value == data) {
		return true;
	}
	if (data > T->value) {
		return find(T->right, data);
	}
	else {
		return find(T->left, data);
	}
}