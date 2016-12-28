#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

template<class T>
class Stack
{
private:
    T *dataArray;
    int len;
    int currentSize;
    const int DEFAULT_SIZE;
    const int MODIFICATOR;

public:

    Stack() : MODIFICATOR(2), DEFAULT_SIZE(20){
        currentSize = DEFAULT_SIZE;
        dataArray = new T[currentSize];
        len = 0;
    }

    Stack(int modificator) : MODIFICATOR(modificator), DEFAULT_SIZE(20){
        currentSize = DEFAULT_SIZE;
        dataArray = new T[currentSize];
        len = 0;
    }

    ~Stack(){
        delete[] dataArray;
    }

    void push(T val){
        if(len == currentSize){
            T *newArray = new T[currentSize *= MODIFICATOR];
            for(int i = 0; i < len; i++){
                newArray[i] = dataArray[i];
            }
            delete [] dataArray;
            dataArray = newArray;
        }
        dataArray[len++] = val;
    }

    T pop(){
        if(len > 0){
            if(currentSize / MODIFICATOR > len){
                T *newArray = new T[currentSize /= MODIFICATOR];
                for(int i = 0; i < len; i++){
                    newArray[i] = dataArray[i];
                }
                delete [] dataArray;
                dataArray = newArray;
            }
            return dataArray[--len];
        }
    }

    bool isEmpty(){
        if(len > 0){
            return false;
        }
        else{
            return true;
        }
    }

    void print(){
        std::cout<<"[";
        for(int i = 0; i < len; i++){
            cout<<dataArray[i];
            if(i != len - 1){
                std::cout<<", ";
            }
        }
        std::cout<<"]"<<endl;
        std::cout<<"Total : "<<len<<" element in stack."<<endl;
    }
};

#endif // STACK_H
