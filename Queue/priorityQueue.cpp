#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int prior;
    Node * next;
    Node(int data, int prior){
        this->data = data;
        this->prior = prior;
        next = NULL;
    }
};

class Queue{
    Node * front = NULL;
    Node * rare = NULL;
    public:
    void enqueue(int data, int prior);
    void dequeue();
    void printQueue();
};

void Queue :: enqueue(int data, int prior){
    Node * newNode = new Node(data,prior);
    if(front == NULL){
        front = newNode;
        rare = newNode;
        return;
    }
    if(front->prior < prior){
        newNode->next = front;
        front = newNode;
        return;
    }
    Node * p = front->next;
    Node * p1 = front;
    while(p != NULL && p->prior > prior){
        p1 = p;
        p = p->next;
    }
    p1->next = newNode;
    newNode->next = p;
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

void Queue ::printQueue()
{
    Node *p = front;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}