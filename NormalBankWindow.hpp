//
//  NormalBankWindow.hpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#ifndef NormalBankWindow_hpp
#define NormalBankWindow_hpp

#include "Type.hpp"
#include "BankWindow.hpp"
class NormalBankWindow: public BankWindow {
    Type bankType;
public:
    NormalBankWindow(){
        bankType = Normal;
    }
};
#endif /* NormalBankWindow_hpp */
