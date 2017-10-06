//
//  User.cpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#include "User.hpp"
#include <iostream>
using namespace std;
Type User::getUserType(){
    return userType;
}

int User::getArriveTime(){
    return arriveTime;
}
int User::getServeTime(){
    return serveTime;
}
void User::getServed(){
    serveTime--;
    cout<< ">>> user : " << ID << " serverTime : " << serveTime <<endl;
}
void User::setType(Type type){
    userType = type;
}
int User::getUserID(){
    return ID;
}
void User::setID(int id){
    ID = id;
}
void User::setArriveTime(int time){
    arriveTime = time;
}

