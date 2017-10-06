//
//  Simulater.cpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/6.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#include "Simulater.hpp"

int Simulater::getWorktime(){
    return workTime;
}

void Simulater::customerCome(User &user){
    switch (user.getUserType()) {
        case Normal:
            queryNormal->enQuery(user);
            break;
        case VIP:
            queryVIP->enQuery(user);
            break;
        case Official:
            queryOfficial->enQuery(user);
            break;
        default:
            break;
    }
    cout<<user.getUserType()<<" comes "<<endl;
}

void Simulater::handleCustomer(){
    for (int i = 0; i < baseWindow * 5; ++i) {
        if (i < baseWindow * 3) {
            if (windowNormal[i].getStatus()) {
                windowNormal[i].getClient()->getServed();
                cout<<i<<" is busy with " <<windowNormal[i].getClient()->getUserID()<<endl;
                
                if (windowNormal[i].getClient()->getServeTime() == 0) {
                    cout << " user : " << windowNormal[i].getClient()->getUserID()
                    << " server stop " << endl;
                    this->callCustomer(windowNormal[i]);
                }
            } else {
                this->callCustomer(windowNormal[i]);
            }
        } else if (i >= baseWindow*3&&i<baseWindow*4){
            if (windowVIP[i%(baseWindow*3)].getStatus()) {
                windowVIP[i%(baseWindow*3)].getClient()->getServed();
                cout<<i<<" is busy with "<<windowVIP[i%(baseWindow*3)].getClient()->getUserID()<<endl;
                if (windowVIP[i%(baseWindow*3)].getClient()->getServeTime() == 0) {
                    cout << " user : " << windowVIP[i%(baseWindow*3)].getClient()->getUserID()
                    << " server stop " << endl;
                    
                    this->callCustomer(windowVIP[i%(baseWindow*3)]);
                }
            }else
                callCustomer(windowVIP[i%(baseWindow*3)]);
        }else{
            if (windowOfficial[i % (baseWindow * 4)].getStatus()) {
                windowOfficial[i % (baseWindow * 4)].getClient()->getServed();
                cout<< i <<" is busy with "<<  windowOfficial[i % (baseWindow * 4)].getClient()->getUserID() << endl;
                if (windowOfficial[i % (baseWindow * 4)].getClient()->getServeTime() == 0) {
                    cout << " user : " << windowOfficial[i % (baseWindow * 4)].getClient()->getUserID()
                    << " server stop " << endl;
                    
                    this->callCustomer(windowOfficial[i % (baseWindow * 4)]);
                }
            }else
                callCustomer(windowOfficial[i%(baseWindow*4)]);
        }
        
    }
}

void Simulater::callCustomer(BankWindow &window) {
    //User user;
    window.setFree();
    if (window.getID() < baseWindow * 3) {
        if(queryNormal->isEmpty()==false){
            window.setClient(queryNormal->deQuery());
        }
    } else if (window.getID() >= baseWindow * 3
              && window.getID() < baseWindow * 4) {
        if (queryVIP->isEmpty()==false) {
            window.setClient(queryVIP->deQuery());
        }else if(queryNormal->isEmpty()==false){
            window.setClient(queryNormal->deQuery());
        }
    }else{
        if (queryOfficial->isEmpty()==false) {
            window.setClient(queryOfficial->deQuery());
        }else if(queryNormal->isEmpty()==false){
            
            window.setClient(queryNormal->deQuery());
        }
    }
}

