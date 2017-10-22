//
//  Wall.hpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/14.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>

typedef struct sPoint
{
    int32_t X;
    int32_t Y;
}Point;


class Wall
{
public:
    const static int32_t WALL_WIDTH = 16;
    Point m_LeftTopPoint;
    Point m_RightTopPoint;
    Point m_LeftBottomPoint;
    Point m_RightBottomPoint;

    Wall(int32_t leftTopX, int32_t leftTopY, int32_t RightBottomX, int32_t RightBottomY);
    bool isPunchWall(int32_t x, int32_t y);

};

#endif /* Wall_hpp */
