#ifndef BST_H
#define BST_H

#include "Node.h"
#include "BSTInterface.h"

using namespace std;

class BST : public BSTInterface {
    
private:
    Node* root = NULL;
    
public:
	BST();
	~BST();
    
    Node * getRootNode() const;

    bool add(int data);
    
    bool insert(Node* &T, int data);

	bool remove(int data);
	
	bool removerecursive(Node* &T, int data);
	
	void replace_parent(Node*& old_root, Node*& local_root);

	void clear();
	
	bool find(Node* T, int data);
};
#endif