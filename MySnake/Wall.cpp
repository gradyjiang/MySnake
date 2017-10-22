//
//  Wall.cpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/14.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#include "Wall.hpp"
#include "GlobalConfig.hpp"
#include <iostream>

Wall::Wall(int32_t leftTopX, int32_t leftTopY, int32_t RightBottomX, int32_t RightBottomY)
{
    m_LeftTopPoint.X = leftTopX;
    m_LeftTopPoint.Y = leftTopY;
    
    m_RightTopPoint.X = RightBottomX;
    m_RightTopPoint.Y = leftTopY;
    
    m_LeftBottomPoint.X = leftTopX;
    m_LeftBottomPoint.Y = RightBottomY;
    
    m_RightBottomPoint.X = RightBottomX;
    m_RightBottomPoint.Y = RightBottomY;
}

bool Wall::isPunchWall(int32_t x, int32_t y)
{
    if (x + GlobalConfig::SQUARE_SIZE - GlobalConfig::SQUARE_DELTA > m_RightTopPoint.X - WALL_WIDTH || x < m_LeftTopPoint.X + WALL_WIDTH)
    {
        std::cout << " x = " << x  << ", " << x + GlobalConfig::SQUARE_SIZE << " right side x = " << m_RightTopPoint.X - WALL_WIDTH << std::endl;
        return true;
    }
    
    if (y  < m_RightBottomPoint.Y + WALL_WIDTH  || y + GlobalConfig::SQUARE_SIZE - GlobalConfig::SQUARE_DELTA > m_RightTopPoint.Y - WALL_WIDTH)
    {
        return true;
    }
    
    return false;
}
