#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(){
        next = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    Node * head;
    public:
    void push(int data);
    void pop();
    void printStack();

};

void Stack :: push(int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node * p = new Node(data);
    p->next = head;
    head = p;
}

void Stack :: pop(){
    if(head == NULL){
        throw invalid_argument("Empty Stack");
    }
    Node * p = head;
    head = head->next;
    delete p;
    p = NULL;
}

void Stack :: printStack(){
    Node * p = head;
    while(p->next != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
}