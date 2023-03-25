#include "DoublyLinkedList.cpp"
#include <iostream>
using namespace std;
int main(){
    DoublyLinkedList list;
    list.insertAtFirst(52);
    list.insertAtFirst(53);
    list.insertAtFirst(54);
    list.insertAtFirst(55);
    list.insertAtFirst(56);
    list.printReverse();
    cout<<"next"<<endl;

    list.insertAtEnd(58);
    list.insertAtEnd(54);
    list.insertAtEnd(50);

    list.deleteLast();

    list.printFarward();
    cout<<"aksdjasfks"<<endl;
    list.deleteNode(2);
    list.printFarward();


}