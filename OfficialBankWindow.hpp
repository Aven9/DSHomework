//
//  OfficialBankWindow.hpp
//  BankSystem
//
//  Created by 张文洁 on 2017/10/5.
//  Copyright © 2017年 lfkdsk. All rights reserved.
//

#ifndef OfficialBankWindow_hpp
#define OfficialBankWindow_hpp

#include <stdio.h>
#include "Type.hpp"
#include "BankWindow.hpp"
class OfficialBankWindow : public BankWindow {
    Type bankType;
    
public:
    OfficialBankWindow(){
        bankType = Official;
    }
};
#endif /* OfficialBankWindow_hpp */
