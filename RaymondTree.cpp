#include "RaymondTree.h"
#include "site.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// creates a new empty tree
RaymondTree::RaymondTree()
{
	root_site = NULL;
	tree_size = 0;
}

// destroy the tree
RaymondTree::~RaymondTree()
{
	if (root_site != NULL)
		delete(root_site);
}

// build a tree of given size
void RaymondTree::build_tree(int size){

	int random_number = 0;
	// ensure the size of the network entered by user is valid
	if (size <= 0) {
		cout << "The size of the network has to be 1 or greater" << endl;
		return;
	}

	srand((unsigned)time(0));
	// generate random IDs for each site based on a seed provided by
	// the system time
	for (int i = 0; i < size; i++) {
		random_number = rand() % 50;
		cout << "DEBUG: node id: " << random_number << endl;
		root_site = insert_node(root_site, random_number);
	}

	print_tree(root_site);
}

// do an insertion into the tree creating
// something similar to a binary tree
Site* RaymondTree::insert_node(Site* node, int data){
	// if it's the first time, input site will
	// be the root site
	if (node == NULL) {
		node = new Site();
		node->id = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

	if (data < node->id ) {
		node->left = insert_node(node->left, data);
	}
	else {
		node->right = insert_node(node->right, data);
	}

	return node;
}

// return the root site
Site* RaymondTree::get_root(){
	return root_site;
}

// set the root site
void RaymondTree::set_root(Site* s) {
	root_site = s;
}

// print the network
void RaymondTree::print_tree(Site* node) {

		// post order traversal
		if (node->left != NULL) {
			print_tree(node->left);
		}
		if (node->right != NULL) {
			print_tree(node->right);
		}
		cout << node->id << " ";
	return;
}