#include <iostream>
#include "infixToPostfix.cpp"

using namespace std;
int main(){
    InfixToPostfix infix;
    string p =infix.infixToPostfix("a+b*(c/d)");
    cout<<p<<endl;
}