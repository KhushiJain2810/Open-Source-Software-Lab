#include <iostream>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

struct Node* flatten(struct Node* node)
{
	if(!node) 
        return NULL;

    struct Node* temp = node->right;
    node->right = flatten(node->left);
    node->left = NULL;

    Node* r_end = node;
    while(r_end->right)
        r_end = r_end->right;
    if(temp)
        r_end->right = flatten(temp);
    return node;
}

void inorder(struct Node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

int main()
{
	// Node* root = newNode(1);
	// root->left = newNode(3);
	// root->right = newNode(4);
	// root->right->left = newNode(2);
	// root->right->left->right = newNode(5);
    
    Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(3);
	root->left->left->left = newNode(4);
	root->left->left->left->left = newNode(5);
	Node* node = flatten(root);

	cout << "The Inorder traversal after "
			"flattening binary tree ";
	inorder(node);
	return 0;
}
