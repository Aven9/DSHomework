//
//  main.cpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "Simulater.hpp"
#include "User.hpp"
#include "Query.hpp"

using namespace std;

#define customerNum 10
int main(int argc, const char * argv[]) {
    User *customers = new User[customerNum];
    Query<User>* query = new Query<User>;
    for (int i=0; i < customerNum; i++) {
        if (i < 3) {
            customers[i].setType(Normal);
        }else if (i < 8){
            customers[i].setType(VIP);
        }
        else{
            customers[i].setType(Official);
        }
        customers[i].setID(i+100);
        customers[i].setArriveTime(i%3);
        cout<<customers[i].getUserType();
        //cout<<query->enQuery(customers[i])<<" ";
    }
    
    Simulater simulater = Simulater(120,query);
    
    for (int i = 0; i < simulater.getWorktime(); i++) {
        cout<<" ======= This is "<< i <<" second ======="<< endl;
        for (int j = 0; j < customerNum; j++) {
            if (customers[j].getArriveTime() == i) {
                simulater.customerCome(customers[j]);
            }
        }
        
        simulater.handleCustomer();
    }
    return 0;
}
