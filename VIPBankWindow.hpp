//
//  VIPBankWindow.hpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#ifndef VIPBankWindow_hpp
#define VIPBankWindow_hpp

#include "Type.hpp"
#include "BankWindow.hpp"
class VIPBankWindow : public BankWindow {
    Type bankType;
    
public:
    VIPBankWindow(){
        bankType = VIP;
    }
};

#endif /* VIPBankWindow_hpp */
