#include "priorityQueue.cpp"
#include <iostream>
using namespace std;
int main(){
    Queue list;


    list.enqueue(1,6);
    list.enqueue(5,5);
    list.enqueue(5,1);
    list.enqueue(2,5);
    list.enqueue(6,2);
    list.enqueue(7,3);
    list.enqueue(9,4);

    list.printQueue();
}