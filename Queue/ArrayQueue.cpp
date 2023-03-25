#include <iostream>
using namespace std;
class Queue{
    int front=-1,rare=-1;
    int size;
    int * arr;
    public:
    Queue(int size){
        this->size=size;
        arr = new int[size];
    }
    ~Queue(){
        delete arr;
        arr = NULL;
    }

    void enqueue(int data);
    void dequeue();
    void printQueue();
};

void Queue ::enqueue(int data){
    if(front == (rare+1)%size){
        throw invalid_argument("list overflow");
        return;
    }
    if(front==-1 && rare==-1){
        front = 0;
        rare = 0;
    }
    else{
        rare = (rare+1)%size;
    }
    *(arr+rare) = data;
}

void Queue :: dequeue(){
    if(front == -1 && rare == -1){
        throw invalid_argument("list underflow");
        return;
    }
    if(front == rare){
        front = -1;
        rare = -1;
    }
    else{
        front = (front+1)%size;
    }
}

void Queue :: printQueue(){
    int i = front;
    while(true){
        cout<<*(arr+i)<<endl;
        if(i == rare){
            break;
        }
        i = (i+1)%size;
    }
}