//
//  Query.hpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#ifndef Query_hpp
#define Query_hpp

#include "Type.hpp"
#include <iostream>
using namespace std;

template <typename T>
class Query {
    T *query;
    int front;
    int rear;
    int maxSize;
    
public:
    Query(){
        maxSize = MaxSize+1;
        query = new T[maxSize];
        front=rear=0;
    }
    bool enQuery(T item);
    T& deQuery();
    bool getFront(T &item);
    bool isEmpty();
};
template<typename T>
bool Query<T>::enQuery(T item){
    if ((rear+1)%maxSize==front) {
        cout<<"Full"<<endl;
        return false;
    }
    query[rear]=item;
    rear=(rear+1)%maxSize;
    return true;
}

template<typename T>
T& Query<T>::deQuery(){
    if (!isEmpty()) {
        front = (front+1)%maxSize;
        return query[front-1];
    }
    return *(new T);
}

template<typename T>
bool Query<T>::getFront(T &item){
    if (rear==front) {
        cout<<"Empty"<<endl;
        return false;
    }
    item = query[front];
    return true;
}
template<typename T>
bool Query<T>::isEmpty(){
    if (front==rear) {
        return true;
    }
    return false;
}


#endif /* Query_hpp */
