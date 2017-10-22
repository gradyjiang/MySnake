//
//  Snake.cpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/20.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#include "Snake.hpp"
#include "GlobalConfig.hpp"

Snake::Snake(size_t size) : mDirection(RIGHT), m_isAlive(true)
{
    Food food(csSnakeInitialPositionX, csSnakeInitialPositionY);
    m_vBody.push_back(food);
    
    for (size_t i = 0; i < size - 1; i++)
    {
        addScale();
    }
}

void Snake::addScale()
{
    size_t endIndex = m_vBody.size() - 1;
    int32_t changeX = 0;
    int32_t changeY = 0;
    
    switch (mDirection)
    {
        case UP:
            changeY = 1;
            break;
        case DOWN:
            changeY = -1;
            break;
        case LEFT:
            changeX = -1;
            break;
        case RIGHT:
            changeX = 1;
            break;
        default:
            break;
    }

    int32_t newX = m_vBody[endIndex].X() + changeX;
    int32_t newY = m_vBody[endIndex].Y() + changeY;
    
    Food newFood(newX, newY);
    m_vBody.push_back(newFood);
}

void Snake::delScale()
{
    m_vBody.erase(m_vBody.begin());
}

size_t Snake::getScaleSize()
{
    return m_vBody.size();
}

Food Snake::getScale(size_t index)
{
    return m_vBody[index];
}

//每次调用在运动方向上加1个像素
void Snake::move()
{
    delScale();
    addScale();
}

void Snake::turn(direction tDirection)
{
    if (mDirection != tDirection)
    {
        switch (tDirection)
        {
            case UP:
                if (mDirection == DOWN)
                    return;
                break;
            case DOWN:
                if (mDirection == UP)
                    return;
                break;
            case LEFT:
                if (mDirection == RIGHT)
                    return;
                break;
            case RIGHT:
                if (mDirection == LEFT)
                    return;
                break;
            default:
                break;
        }
        mDirection = tDirection;
    }
}

bool Snake::isAlive()
{
    return m_isAlive;
}

void Snake::setSnakeIsAlive(bool alive)
{
    m_isAlive = alive;
}

direction Snake::getDirection()
{
    return mDirection;
}
