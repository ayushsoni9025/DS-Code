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
Node *head = NULL;
Node *last = NULL;
// class DoublyLinkedList{
//     public:
//     Node *head = NULL;
//     Node *last = NULL;
//     void insertAtFirst(int data);
//     void insertAtEnd(int data);
//     void insertAtIndex(int index,int data);

//     void deleteFirst();
//     void deleteLast();
//     void deleteNode(int index);
//     void printFarward();
//     void printReverse();
// };

void  insertAtFirst(int data){
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

void  insertAtEnd(int data){

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

void insertAtIndex(int index, int data)
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

void deleteFirst(){
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

void deleteLast()
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

void deleteNode(int index)
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

void  printFarward(){
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

void  printReverse(){
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
int main(){
    insertAtFirst(52);
    insertAtFirst(53);
    insertAtFirst(54);
    insertAtFirst(55);
    insertAtFirst(56);
    printReverse();
    cout<<"next"<<endl;

    insertAtEnd(58);
    insertAtEnd(54);
    insertAtEnd(50);

    deleteLast();

    printFarward();
    cout<<"aksdjasfks"<<endl;
    deleteNode(2);
    printFarward();
}