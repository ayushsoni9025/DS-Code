#include <iostream>

int fibb(int a){
    if(a == 0){
        return 0;
    }
    else  if(a == 1){
        return 1;
    }
    return fibb(a-1)+fibb(a-2);
}

int main(){
    int a = 7;
    std::cout<<fibb(a)<<std::endl;
}