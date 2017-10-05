//
//  main.cpp
//  BankSystem
//
//  Created by 刘丰恺 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#define servetime 7
#define MaxSize 100
using namespace std;
typedef enum : unsigned int {
    Normal = 0,
    VIP = 1,
    Official = 2,
} Type;
class User {
    int ID;
    bool isWait;
    int arriveTime;
    int serveTime;
    Type userType;
public:
    User(Type type = Normal){
        srand((int)time(0));
        ID = rand()%100000000;
        isWait = true;
        arriveTime = rand()%121;
        serveTime = servetime;
        userType = type;
    }
    Type getUserType();
};
Type User::getUserType(){
    return userType;
}
class BankWindow {
    bool isBusy;
    int ID;
    Type bankType;
    
public:
    BankWindow(Type type = Normal, int bankID = 0){
        bankType = type;
        isBusy = false;
        ID = bankID;
    }
    void handleUser();
};
void BankWindow::handleUser(){
    //handleUser
}
class Simulater {
    int maxSize;
    User *queryNormal;
    int queryNormalFront;
    int queryNormalRear;
    
    User *queryVIP;
    int queryVIPFront;
    int queryVIPRear;
    
    User *queryOfficial;
    int queryOfficialFront;
    int queryOfficialRear;
    
    int workTime;
public:
    Simulater(int time = 120){
        workTime = time;
        maxSize = MaxSize+1;
        queryNormal = new User[maxSize];
        queryNormalFront = queryNormalRear = 0;
        
        queryVIP = new User[maxSize];
        queryVIPFront = queryVIPRear = 0;
        
        queryOfficial = new User[maxSize];
        queryOfficialFront = queryOfficialRear = 0;
    }
    void customerCome(User user);
    void callCostomer(User user);
    bool enQueryNormal(const User user);
    bool enQueryVIP(const User user);
    bool enQueryOfficial(const User user);
    bool deQueryNormal(User&user);
    bool deQueryVIP(User&user);
    bool deQueryOfficial(User&user);
    bool getFrontNormal(User &user);
    bool getFrontVIP(User &user);
    bool getFrontOfficial(User &user);
};
bool Simulater::enQueryNormal(const User user){
    if ((queryNormalRear + 1)%maxSize == queryNormalFront) {
        cout<<"Normal Query is full"<<endl;
        return false;
    }
    queryNormal[queryNormalRear]=user;
    queryNormalRear = (queryNormalRear+1)%maxSize;
    return true;
}
bool Simulater::enQueryVIP(const User user){
    if ((queryVIPRear + 1)%maxSize == queryVIPFront) {
        cout<<"VIP Query is full"<<endl;
        return false;
    }
    queryVIP[queryVIPRear]=user;
    queryVIPRear = (queryVIPRear+1)%maxSize;
    return true;
}
bool Simulater::enQueryOfficial(const User user){
    if ((queryOfficialRear + 1)%maxSize == queryOfficialFront) {
        cout<<"Official Query is full"<<endl;
        return false;
    }
    queryOfficial[queryOfficialRear]=user;
    queryOfficialRear = (queryOfficialRear+1)%maxSize;
    return true;
}
bool Simulater::deQueryNormal(User &user){
    if (queryNormalFront==queryNormalRear) {
        cout<<"Normal Query is empty"<<endl;
        return false;
    }
    user = queryNormal[queryNormalFront];
    queryNormalFront = (queryNormalFront+1)%maxSize;
    return true;
}
bool Simulater::deQueryVIP(User &user){
    if (queryVIPFront==queryVIPRear) {
        cout<<"VIP Query is empty"<<endl;
        return false;
    }
    user = queryVIP[queryVIPFront];
    queryVIPFront = (queryVIPFront+1)%maxSize;
    return true;
}
bool Simulater::deQueryOfficial(User &user){
    if (queryOfficialFront==queryOfficialRear) {
        cout<<"Official Query is empty"<<endl;
        return false;
    }
    user = queryOfficial[queryOfficialFront];
    queryOfficialFront = (queryOfficialFront+1)%maxSize;
    return true;
}
bool Simulater::getFrontNormal(User &user){
    if (queryNormalFront==queryNormalRear) {
        cout<<"Normal Query is empty"<<endl;
        return false;
    }
    user = queryNormal[queryNormalFront];
    return true;
}
bool Simulater::getFrontVIP(User &user){
    if (queryVIPFront==queryVIPRear) {
        cout<<"VIP Query is empty"<<endl;
        return false;
    }
    user = queryVIP[queryVIPFront];
    return true;
}
bool Simulater::getFrontOfficial(User &user){
    if (queryOfficialFront==queryOfficialRear) {
        cout<<"Official Query is empty"<<endl;
        return false;
    }
    user = queryOfficial[queryOfficialFront];
    return true;
}
void Simulater::customerCome(User user){
    if (user.getUserType()==Normal) {
        <#statements#>
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
