#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *pre;
    Node()
    {
        next = NULL;
        pre = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
        pre = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node *head = NULL;
    Node *last = NULL;
    void insertAtFirst(int data);
    void insertAtEnd(int data);
    void insertAtIndex(int index,int data);

    void deleteFirst();
    void deleteLast();
    void deleteNode(int index);
    void printFarward();
    void printReverse();
};

void DoublyLinkedList :: insertAtFirst(int data){
    Node * newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        last = newNode;
        return;
    }
    newNode->next = head;
    head->pre = newNode;
    newNode->pre = NULL;
    head = newNode;
}

void DoublyLinkedList :: insertAtEnd(int data){

    Node * newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        last = newNode;
        return;
    }
    newNode->pre = last;
    last->next = newNode;
    last = newNode;
}

void DoublyLinkedList ::insertAtIndex(int index, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *p = head;
    int count = 1;
    while(count < index && p->next != NULL)
    {
        p = p->next;
        count++;
    }
    Node *p1 = new Node(data);
    p1->next = p->next;
    p->next = p1;
}

void DoublyLinkedList ::deleteFirst(){
    if (head == NULL)
    {
        cout << "Empty List Deletion" << endl;
        return;
    }
    Node *p = head;
    head = head->next;
    head->pre = NULL;
    delete p;
    p = NULL;
}

void DoublyLinkedList ::deleteLast()
{
    if (head == NULL)
    {
        cout << "Empty List Deletion" << endl;
        return;
    }
    Node *p = last;
    last = last->pre;
    last->next = NULL;
    delete p;
    p = NULL;
}

void DoublyLinkedList ::deleteNode(int index)
{
    if (head == NULL)
    {
        cout << "Invalid Deletion" << endl;
        return;
    }
    Node *p = head;
    Node *p1;
    int count = 0;
    while (count < index)
    {
        if (p == NULL)
        {
            cout << "Invalid deletion" << endl;
            return;
        }
        p1 = p;
        p = p->next;
        count++;
    }
    p1->next = p->next;
    p->next->pre = p1;
    delete p;
    p = NULL;
}

void DoublyLinkedList :: printFarward(){
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    Node * p = head;
    while(p != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
}

void DoublyLinkedList :: printReverse(){
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    Node * p = last;
    while(p != NULL){
        cout<<p->data<<endl;
        p = p->pre;
    }
}