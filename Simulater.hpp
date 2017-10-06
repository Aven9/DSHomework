//
//  Simulater.hpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/6.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#ifndef Simulater_hpp
#define Simulater_hpp

#include "Type.hpp"
#include "Query.hpp"
#include "User.hpp"
#include "BankWindow.hpp"
#include "NormalBankWindow.hpp"
#include "VIPBankWindow.hpp"
#include "OfficialBankWindow.hpp"

class Simulater {
    int maxSize;
    
    Query<User> *queryNormal;
    Query<User> *queryVIP;
    Query<User> *queryOfficial;
    
    int workTime;
    
    NormalBankWindow *windowNormal;
    VIPBankWindow *windowVIP;
    OfficialBankWindow *windowOfficial;
public:
    Simulater(int time = 120, Query<User> *q = 0){
        workTime = time;
        maxSize = MaxSize+1;
        
        queryNormal = new Query<User>;
        queryVIP = new Query<User>;
        queryOfficial = new Query<User>;
        User user;
        while (q&&((q->isEmpty())==false)) {
            if (user.getUserType()==Normal) {
                queryNormal->enQuery(user);
            }else if (user.getUserType()==VIP)
                queryVIP->enQuery(user);
            else if (user.getUserType()==Official)
                queryOfficial->enQuery(user);
        }
        
        windowNormal = new NormalBankWindow[baseWindow*3];
        windowVIP = new VIPBankWindow[baseWindow];
        windowOfficial = new OfficialBankWindow[baseWindow];
        for (int i=0; i < baseWindow * 5; i++) {
            if (i< baseWindow * 3) {
                windowNormal[i].setBankID(i);
            }else if (i>=baseWindow*3&&i<baseWindow*4)
                windowVIP[i%(baseWindow*3)].setBankID(i);
            else
                windowOfficial[i%(baseWindow*4)].setBankID(i);
        }
    }
    
    int getWorktime();
    void customerCome(User &user);
    void handleCustomer();
    void callCustomer(BankWindow &window);
    
};
#endif /* Simulater_hpp */
