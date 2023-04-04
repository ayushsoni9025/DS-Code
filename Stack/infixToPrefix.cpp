#include <iostream>
using namespace std;

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


class InfixToPrefix : public Stack{
    public:
    string infix;
    string infixToPrefix(string s);
    // InfixToPrefix(string infix){
    //     this->infix = infix;
    // }
    int precidence(char c);
    string reverse(string s);
};

int InfixToPrefix :: precidence(char c){
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

string InfixToPrefix :: reverse(string s){
    char c;
    for (int i = 0; i < s.length()/2; i++)
    {
        c=s[i];
        s[i]=s[s.length()-i-1];
        s[s.length()-i-1]=c; 
    }
    return s; 
}

string InfixToPrefix :: infixToPrefix(string s){
    s = reverse(s);
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            result += s[i];
        }
        else if(s[i] == ')'){
            push(s[i]);
        }
        else if(s[i]=='('){
            while (head != NULL && head->data!=')')
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
    
    result = reverse(result);
    return result;
}