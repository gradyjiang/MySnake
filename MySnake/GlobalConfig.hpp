//
//  GlobalConfig.hpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/20.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#ifndef GlobalConfig_hpp
#define GlobalConfig_hpp

#include <stdio.h>

class GlobalConfig
{
    
public:
    static const int FRAME_RATE = 60;
    static const int SQUARE_SIZE = 32;
    static const float SQUARE_DELTA;
    static const int SNAKE_SQUARE_DELTA = 2;
    static const int SNAKE_SPEED = 12; // Snake's movement per second
    static const int PROCESS_INTERVAL = 15;
};

#endif /* GlobalConfig_hpp */
