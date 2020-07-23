#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

// this is the node for the binary tree
struct Node {
	char letter;
	Node* left;
	Node* right;
	std::string path; // The morse code for the letter

	// Constructor
	Node() {
		letter = ' ';
		left = nullptr;
		right = nullptr;
		path = "";
	}

	//Destructor
	~Node() {};
};

//class declaration.
class binaryTree {
public:
	binaryTree();
	~binaryTree();

	void encodeSearch(char data, Node* leaf);
	void encodeSearchString(std::string data, Node* leaf);
	void decodeSearch(std::string path);
	void decodeSearchString(std::string paths);
	void destroyTree();
	Node* getRoot() { return root; }
	std::string getTree(Node* leaf);

private:
	Node* root;
	void insert(char data, std::string path);
	void destroyTree(Node* leaf);
	void buildTree();
};