#include <iostream>
#include "infixToPrefix.cpp"

using namespace std;
int main(){
    InfixToPrefix infix;
    string p =infix.infixToPrefix("a+b*(c/d)");
    cout<<p<<endl;
}