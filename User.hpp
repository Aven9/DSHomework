//
//  User.hpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Type.hpp"


class User {
    int ID;
    bool isWait;
    int arriveTime;
    int serveTime;
    Type userType;
public:
    User(){
        serveTime = servetime;
    }
    Type getUserType();
    int getArriveTime();
    int getServeTime();
    void getServed();
    void setType(Type type);
    void setID(int);
    void setArriveTime(int);
    int getUserID();
};

#endif /* User_hpp */
