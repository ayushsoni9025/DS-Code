#include <iostream>
#include "LinkedlistStack.cpp"
using namespace std;
int main(){
    Stack list;
    
    list.push(5);
    list.push(5);
    list.push(5);
    list.printStack();
    list.pop();
    list.printStack();
}