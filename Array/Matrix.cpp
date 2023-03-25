#include <iostream>
using namespace std;

class Matrix{
    public:
    int * arr;
    int row, column;
    Matrix(int row , int column){
        this->column = column;
        this->row = row;
        arr = new int[row*column];
    }

    void cinMatrix();
    void printMatrix();
    void addMat(Matrix a, Matrix b);
    void subMat(Matrix a, Matrix b);
    void mulMat(Matrix a, Matrix b);
    void upperTringular();
    void lowerTringular();
};

void Matrix :: cinMatrix(){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin>>*(arr+i*column+j);
        }
    }
}

void Matrix :: printMatrix(){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout<<*(arr+i*column+j)<<" ";
        }
        cout<<endl;
    }
}

void Matrix :: addMat(Matrix a,Matrix b){
    if(row != a.row || column != a.column || row != b.row || column != b.column){
        cout<<"invalid Operation"<<endl;
        return;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            *(arr+i*column+j)=*(a.arr+i*column+j)+*(b.arr+i*column+j);
        }
    }
}

void Matrix :: subMat(Matrix a,Matrix b){
    if(row != a.row && column != a.column && row != b.row && column != b.column){
        cout<<"invalid Operation"<<endl;
        return;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            *(arr+i*column+j)=*(a.arr+i*column+j)-*(b.arr+i*column+j);
        }
    }
}

void Matrix :: mulMat(Matrix a,Matrix b){
    if(a.column != b.row || row != a.row || column != b.column){
        return;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            *(arr+i*column+j)=(*(a.arr+i*column+j))*(*(b.arr+j*column+i));
        }
    }
}

void Matrix :: upperTringular(){
    if(row != column){
        cout<<"invalid Operation"<<endl;
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            *(arr+i*column+j) = 0;
        }
        
    }
}

void Matrix :: lowerTringular(){
    if(row != column){
        cout<<"invalid Operation"<<endl;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = i+1; j < column; j++)
        {
            *(arr+i*column+j) = 0;
        }
        
    }
}