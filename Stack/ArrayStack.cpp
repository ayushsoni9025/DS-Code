#include <iostream>
using namespace std;

class Stack{
    int top;
    int size;
    int * arr;
    public:
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    ~Stack(){
        delete arr;
        arr = NULL;
    }

    void push(int item);
    void pop();

    void printStack();
};

void Stack :: push(int item){
    if(top == size-1){
        throw invalid_argument("Stack Overflow");
    }
    top++;
    *(arr+top) = item;
}

void Stack :: pop(){
    if(top == -1){
        throw invalid_argument("Stack Empty");
    }
    top--;
}
void Stack :: printStack(){
    for (int i = 0; i <= top; i++)
    {
        cout<<*(arr+i)<<endl;
    }
}
