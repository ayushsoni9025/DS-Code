#include <iostream>
using namespace std;

class Array
{
    int *arr;
    int size, filled = 0;

public:
    Array(int size)
    {
        this->size = size;
        arr = new int(size);
    }

    ~Array(){
        delete [] arr;
        arr = NULL;
    }

    void push(int data);
    void pop();
    void insertion(int data, int index);
    void deletion(int index);
    int getData(int index);
    int searching(int data);
    int min();
    int max();
    void sort();
    void printArray();
    void merging(Array a,Array b);
};

void Array ::insertion(int data, int index)
{
    if (index > filled)
    {
        cout << "Invalid insertion" << endl;
        return;
    }
    // if(index == filled){
    //     push(data);
    //     return;
    // }
    int i = filled;
    for (; i > index; i--)
    {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + i) = data;
    filled++;
}

void Array ::deletion(int index)
{
    if (index >= filled)
    {
        cout << "invalid deletion" << endl;
        return;
    }
    cout << *(arr + index) << " has been succesfully deleted" << endl;
    for (int i = index; i < filled; i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    filled--;
}

void Array ::push(int data)
{
    if (filled >= size)
    {
        cout << "Array Overflow" << endl;
        return;
    }
    *(arr + filled) = data;
    filled++;
}

void Array ::pop()
{
    if (filled == 0)
    {
        cout << "Array underflow" << endl;
        return;
    }
    cout << *(arr + filled - 1) << " has been remmoved from array" << endl;
    filled--;
}

void Array ::printArray()
{
    if (filled == 0)
    {
        cout << "Empty Array" << endl;
        return;
    }
    for (int i = 0; i < filled; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int Array ::getData(int index)
{
    if (index >= filled)
    {
        cout << "Empty Index" << endl;
        return 0;
    }
    return *(arr + index);
}

int Array ::searching(int data)
{
    for (int i = 0; i < filled; i++)
    {
        if (*(arr + i) == data)
        {
            return i;
        }
    }
    return -1;
}

int Array ::min()
{
    int min = *arr;
    for (int i = 1; i < filled; i++)
    {
        if (min > *(arr + i))
        {
            min = *(arr + i);
        }
    }
    return min;
}

int Array ::max()
{
    int max = *arr;
    for (int i = 1; i < filled; i++)
    {
        if (max < *(arr + i))
        {
            max = *(arr + i);
        }
    }
    return max;
}

void Array ::sort()
{
    for (int i = 0; i < filled; i++)
    {
        for (int j = i + 1; j < filled; j++)
        {
            if (*(arr + i) > *(arr + j))
            {
                *(arr + i) = *(arr + i) + *(arr + j);
                *(arr + j) = *(arr + i) - *(arr + j);
                *(arr + i) = *(arr + i) - *(arr + j);
            }
        }
    }
}

void Array :: merging(Array a, Array b){
    int i,j,k = 0;
    for (i = 0; i < a.size; i++,k++)
    {
        *(arr+k) = *(arr+i);
    }
    for ( j = 0; j < b.size; j++,k++)
    {
        *(arr+k) = *(arr+j);
    }
}
