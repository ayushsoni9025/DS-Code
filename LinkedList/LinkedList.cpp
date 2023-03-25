#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head = NULL;
    void append(int data);
    void push(int data);
    void insertAfter(int index, int data);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int index);
    void printList();
};

void LinkedList ::append(int data)
{
    Node *p1 = new Node(data);
    p1->next = NULL;
    if (head == NULL)
    {
        head = p1;
        return;
    }
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = p1;
}

void LinkedList ::push(int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *p = new Node(data);
    p->next = head;
    head = p;
}

void LinkedList ::insertAfter(int index, int data)
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

void LinkedList ::deleteFirst(){
    if (head == NULL)
    {
        cout << "Empty List Deletion" << endl;
        return;
    }
    Node *p = head;
    head = head->next;
    delete p;
    p = NULL;
}

void LinkedList ::deleteLast()
{
    if (head == NULL)
    {
        cout << "Empty List Deletion" << endl;
        return;
    }
    Node *p = head;
    Node *p1;
    while (p->next != NULL)
    {
        p1 = p;
        p = p->next;
    }
    p1->next = NULL;
    delete p;
    p = NULL;
}

void LinkedList ::deleteNode(int index)
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
    delete p;
    p = NULL;
}

void LinkedList ::printList()
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}