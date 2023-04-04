#include <iostream>
using namespace std;

class Node{
    public:
    char data;
    Node * next;
    Node(){
        next = NULL;
    }
    Node(char data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
    public:
    Node * head;
    void push(char data);
    char pop();
    void printStack();

};

void Stack :: push(char data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node * p = new Node(data);
    p->next = head;
    head = p;
}

char Stack :: pop(){
    if(head == NULL){
        throw invalid_argument("Empty Stack");
    }
    char item = head->data;
    Node * p = head;
    head = head->next;

    delete p;
    p = NULL;
    return item;
}

void Stack :: printStack(){
    Node * p = head;
    while(p->next != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
}


class InfixToPostfix : public Stack{
    public:
    string infix;
    string infixToPostfix(string s);
    int precidence(char c);
};

int InfixToPostfix :: precidence(char c){
    switch (c)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

string InfixToPostfix :: infixToPostfix(string s){
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            result += s[i];
        }
        else if(s[i] == '('){
            push(s[i]);
        }
        else if(s[i]==')'){
            while (head != NULL && head->data!='(')
            {
                result += head->data;
                pop();
            }
            if(head != NULL){
                pop();
            }
            
        }
        else{
            while(head != NULL && precidence(head->data) >= precidence(s[i])){
                result += head->data;
                pop();
            }
            push(s[i]);
        }
    }

    
    result += head->data;
    pop();
    result += head->data;
    pop();

    return result;
}