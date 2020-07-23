#include "Node.h"

//  Creates tree.
binaryTree::binaryTree(){
    root = new Node;
    buildTree();
}

//  Destroys tree
binaryTree::~binaryTree(){
    destroyTree();
}

//  Destroys tree
void binaryTree::destroyTree() {
    destroyTree(root);
}

//  Deletes entire tree by going through all the nodes and deleting them one by one
void binaryTree::destroyTree(Node* leaf) {
    if (leaf != nullptr) {
        if (leaf->left != nullptr) {
            destroyTree(leaf->left);
        }
        if (leaf->right != nullptr) {
            destroyTree(leaf->right);
        }
        delete leaf;
    }
}

//  Searches through tree for data and prints morse for specific letter
void binaryTree::encodeSearch(char data, Node* leaf) {
    if (leaf->letter == data) { // checks for correct letter at node
        std::cout << leaf->path;
    }
    else { 
        if (leaf->left != nullptr) { // goes left
            encodeSearch(data, leaf->left); // recursive function to search left branch
        }

        if (leaf->right != nullptr) { // goes right
            encodeSearch(data, leaf->right); // recursive function to search right branch
        }
    }
}

//  Encodes a string
void binaryTree::encodeSearchString(std::string data, Node* leaf) {
    std::cout << "\"" << data << "\" encoded is:" << std::endl;
    for (unsigned int i = 0; i < data.size(); i++) {
        encodeSearch(tolower(data[i]), root);
        std::cout << " / ";
    }
    std::cout << std::endl << std::endl;
}

//  Decodes the string of dots and dashes by reading morse code path
void binaryTree::decodeSearch(std::string path) {
    Node* cursor = root;

    //  reads the path of morse code to determine letter
    for (unsigned int i = 0; i < path.size(); i++) {
        if (path[i] == '.') { // goes left
            cursor = cursor->left;
        }
        else { //  goes right
            cursor = cursor->right;
        }
    }

    //  Prints the designated letter
    if (cursor != nullptr)
        std::cout << cursor->letter;
    //  If letter does not exist, print error
    else
        std::cout << "invalid morse code ";
}

//  Decodes a string of dots and dashes
void binaryTree::decodeSearchString(std::string paths) {
    std::cout << paths << " decoded is: ";
    std::string search = "";
    for (unsigned int i = 0; i < paths.size(); i++) {
        if (paths.at(i) != ' ') {
            search += paths.at(i);
            if (i == paths.size() - 1)
                decodeSearch(search);
        }
        else {
            decodeSearch(search);
            search = "";
        }
    }
    std::cout << std::endl;
}

//  Inserts data into leaves, creates path if does not exist
void binaryTree::insert(char data, std::string path) {

    Node* cursor = root; //  Creates a moving pointer

    for (unsigned int i = 0; i < path.size(); i++) { // GO through the morse code sequence.
        if (path[i] == '.') { //  Goes Left
            if(cursor->left != nullptr) { //  Checks if left node is null, if not, moves cursor to node
                cursor = cursor->left;
            }
            else {  //  If left node is empty, creates a new node, then moves cursor to the new node
                cursor->left = new Node();
                cursor = cursor->left;
            }
        }
        else { //  Goes Right
            if (cursor->right != nullptr) { // Checks if right node is null, if not, moves cursor to node
                cursor = cursor->right;
            }
            else {  // If right node is empty, creates a new node, then moves cursor to the new node
                cursor->right = new Node();
                cursor = cursor->right;
            }
        }
    }
    //  Inserts data into designated node
    cursor->letter = data;
    cursor->path = path;
}

//  Builds tree from text file, calling the insert functions
void binaryTree::buildTree() {
    std::ifstream fin("morse.txt");
    char finLetter;
    std::string morseCode;

    //  Reads information from morse.txt
    if(fin.is_open()){
        while(!fin.eof()){
            fin >> finLetter; 
            std::getline(fin, morseCode);
            insert(finLetter, morseCode);
        }
    }
    else
        std::cout <<"Error, file is not open.\n";
        
    fin.close();
}

//  gets Tree in order
std::string binaryTree::getTree(Node* leaf) {
    std::string result;
    if (leaf->left != nullptr) {
        result += getTree(leaf->left);
    }

    result += leaf->letter;
    result += ":";
    result += leaf->path;
    result += "\n";

    if (leaf->right != nullptr) {
        result += getTree(leaf->right);
    }

    return result;
}
