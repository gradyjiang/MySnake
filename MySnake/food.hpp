//
//  food.hpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/10.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#ifndef food_hpp
#define food_hpp

#include <stdio.h>

class Food
{
public:
    Food(int32_t x, int32_t y);
    int32_t X();
    int32_t Y();
private:
    int32_t x;
    int32_t y;
};

#endif /* food_hpp */
