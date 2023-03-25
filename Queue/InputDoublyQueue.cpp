#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue{
    Node * front = NULL;
    Node * rare = NULL;
    public:
    void enqueue(int data);
    void dequeue();
    void dequeue(int);
    void printQueue();
};

void Queue :: enqueue(int data){
    Node * newNode = new Node(data);
    if(rare == NULL && front == NULL){
        front = newNode;
        rare = newNode;
        return;
    }
    rare->next = newNode;
    rare = newNode;
}

void Queue :: dequeue(){
    if(front == NULL && rare == NULL){
        throw invalid_argument("Empty list");
    }
    Node * p = front;
    if(front == rare){
        delete p;
        front = NULL;
        rare = NULL;
        p = NULL;
        return;
    }
    front = front->next;
    delete p;
    p = NULL;
}

void Queue :: dequeue(int arg){
    if(arg != -1){
        throw invalid_argument("Invalid argument arg");
    }
    if(front == NULL && rare == NULL){
        throw invalid_argument("Empty list");
    }
    Node * p = front;
    if(front == rare){
        delete p;
        front = NULL;
        rare = NULL;
        p = NULL;
        return;
    }
    while(p->next != rare){
        p = p->next;
    }
    rare = p;
    p = p->next;
    rare->next = NULL;
    delete p;
    p = NULL;
}

void Queue ::printQueue()
{
    Node *p = front;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}