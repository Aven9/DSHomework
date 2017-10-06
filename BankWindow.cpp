//
//  BankWindow.cpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#include "BankWindow.hpp"

bool BankWindow::getStatus(){
    if (client && client->getUserID()) {
        isBusy = true;
    } else {
        isBusy=false;
    } 
    return isBusy;
}
int BankWindow::getID(){
    return ID;
}
void BankWindow::setBankID(int id){
    ID = id;
}
void BankWindow::setClient(User &user){
    isBusy = true;
    client = &user;
}
void BankWindow::setFree(){
    client = nullptr;
    isBusy = false;
}

User* BankWindow::getClient() {
    return client;
}

