#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    Node *head = NULL;
    
    void insertAtBegining(int data);
    void insertAtLast(int data);
    void insertAtIndex(int index,int data);

    void deleteFirst();
    void deleteLast();
    void deleteIndex(int index);
    void printList();
};

void CircularLinkedList ::insertAtBegining(int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        head->next = head;
        return;
    }
    Node * p = head;
    Node * newNode = new Node(data);
    while(p->next != head){
        p = p->next; 
    }
    newNode->next = head;
    p->next=newNode;
    head = newNode;
}

void CircularLinkedList :: insertAtLast(int data){
    if (head == NULL)
    {
        head = new Node(data);
        head->next = head;
        return;
    }
    Node * p = head;
    Node * newNode = new Node(data);
    while(p->next != head){
        p = p->next; 
    }
    newNode->next = head;
    p->next=newNode;
}

void CircularLinkedList ::insertAtIndex(int index,int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        head->next = head;
        return;
    }
    if(index == 0){
        insertAtBegining(data);
    }
    Node * p = head;
    Node * p1;
    int count = 0;
    Node * newNode = new Node(data);
    while(p->next != head){
        if(count == index){
            newNode->next = p;
            p1->next = newNode; 
            return; 
        }
        p1 = p;
        p = p->next; 
        count++;
    }
    newNode->next = head;
    p->next=newNode;
}

void CircularLinkedList ::deleteFirst()
{
    if (head == NULL)
    {
        cout<<"Invalid deletion"<<endl;
        return;
    }
    Node * p = head;
    Node * p1 = head;
    while(p->next != head){
        p = p->next; 
    }
    head = head->next;
    p->next = head;
    delete p1;
    p1=NULL;
}

void CircularLinkedList :: deleteLast(){
    if (head == NULL)
    {
        cout<<"Invalid deletion"<<endl;
        return;
    }
    Node * p = head;
    Node * p1 = head;
    while(p->next != head){
        p1 = p;
        p = p->next; 
    }
    p1->next = head;
    delete p;
    p = NULL;
}

void CircularLinkedList :: deleteIndex(int index){
    
    if (head == NULL)
    {
        cout<<"invalid operation"<<endl;
        return;
    }
    if(index == 0){
        deleteFirst();
    }
    Node * p = head;
    Node * p1;
    int count = 0;
    while(p->next != head){
        if(count == index){
            break;
        }
        p1 = p;
        p = p->next; 
        count++;
    }
    p1->next = p->next;
    delete p;
    p = NULL;
}

void CircularLinkedList ::printList()
{
    if(head == NULL){
        cout<<"List is empty"<<endl;
    }
    Node *p = head;
    do
    {
        cout << p->data << endl;
        p = p->next;
    }while(p!=head);
}