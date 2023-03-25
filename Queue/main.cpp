#include "OutputDoublyQueue.cpp"
#include <iostream>
using namespace std;
int main(){
    Queue list;
    list.enqueue(2);
    list.enqueue(5);
    list.enqueue(6);
    list.enqueue(7);
    list.enqueue(9);

    list.printQueue();

    list.enqueue(5,-1);

    cout<<"next"<<endl;
    list.printQueue();
}