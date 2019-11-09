#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
using namespace std;

template <typename T>
class BinaryTree {
private:

    //Node definition
    struct Node {
        T info;
        Node *left, *right;
    };
    
    Node *root;
    int _size;

    //Methods
    int size(const Node *node) const {
        return node ? size(node->left) + size(node->right) + 1 : 0;
    }

    bool search(Node *node, const T& info) const {
        while(node){
            if(info == node->info) return true;
            else if(info < node->info) node = node->left;
            else node = node->right;
        }
        return false;
        
    }
    //Pass through the nodes
    void preorder(Node *node) const {
        if(node){
            cout << node->info << endl;
            preorder(node->left);
            preorder(node->right);
        }
    }

public:

    //Constructor
    BinaryTree() : root(nullptr), _size(0) {}

    //Size O(n)
    int size() const { return size(root); }

    //Size O(1)
    int showSize() { return _size; }

    //Insertion
    void insert(const T& info){

        Node *node = root, *prev = nullptr;

        // Search the previous node to branch
        while(node){
            prev = node;
            if(node->info == info) return;
            else if(node->info > info) node = node->left;
            else node = node->right;
        }

        //Create the object node
        node = new Node{ info, nullptr, nullptr };

        //Insert in the previous node found
        if(!root) root = node;
        else if(info < prev->info) prev->left = node;
        else prev->right = node;

        _size++;
    }

    //Search
    bool search(const T& info) const { return search( root, info); }

    //Show the nodes of the binary tree
    void show() const { return preorder(root); }

};

#endif