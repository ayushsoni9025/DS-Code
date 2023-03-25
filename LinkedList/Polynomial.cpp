#include <iostream>
using namespace std;

class Node{
    public:
    int coefficient, degree;
    Node * next;
    Node(int coefficient,int degree){
        this->coefficient = coefficient;
        this->degree = degree;
        next = NULL;
    }
};


class Polynomial{
    public:
    Node * head = NULL;
    int counter = 0;
    void add(int coefficient, int degree); 
    void printPolynomial();
};

void Polynomial :: add(int coefficient, int degree){
    Node * newNode = new Node(coefficient,degree);
    if(head == NULL){
        head = newNode;
        return;
    }
    if(head->degree < degree){
        newNode->next = head;
        head = newNode;
        return;
    }
    if(head->degree == degree){
        head->coefficient += coefficient;
        return;
    }
    Node * p = head->next;
    Node * p1 = head;
    while(p->next != NULL && p->degree > degree){
        p1 = p;
        p = p->next;
    }
    if(p->degree == degree){
        p->coefficient += coefficient; 
        return;
    }
    p1->next = newNode;
    newNode->next = p;
}

void Polynomial :: printPolynomial()
{
    Node *p = head;
    while (p != NULL)
    {
        if(p != head){
            cout<<"+";
        }
        cout <<p->coefficient<<"x^"<<p->degree;
        p = p->next;
        
    }
    cout<<endl;
}

