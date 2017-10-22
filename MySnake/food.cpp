//
//  food.cpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/10.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#include "food.hpp"

Food::Food(int32_t x, int32_t y):x(x), y(y)
{
    
}

int32_t Food::X()
{
    return x;
}

int32_t Food::Y()
{
    return y;
}
