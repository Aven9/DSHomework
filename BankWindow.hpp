//
//  BankWindow.hpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#ifndef BankWindow_hpp
#define BankWindow_hpp

#include "User.hpp"

class BankWindow {
    
    bool isBusy;
    int ID;
    User* client;
    
public:
    
    BankWindow(int bankID = 0){
        isBusy = false;
        ID = bankID;
        client = nullptr;
    }
    
    bool getStatus();
    int getID();
    void setBankID(int id);
    void setClient(User &user);
    void setFree();
    User* getClient();
};

#endif /* BankWindow_hpp */
