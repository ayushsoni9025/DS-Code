#include <iostream>
using namespace std;

class Node{
    int data;
    Node * Lchild;
    Node * Rchild;
    public:
    Node(int data){
        this->data = data;
        Lchild = NULL;
        Rchild = NULL;
    }

    Node(int data){
        this->data = data;
        Lchild = NULL;
        Rchild = NULL;
    }
};

class BinaryTree{
    Node * root;
};