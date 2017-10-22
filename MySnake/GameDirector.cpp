//
//  GameDirector.cpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/10.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#include "GameDirector.hpp"
#include "GameRender.hpp"
#include <iostream>

/* static field initialization */
std::vector<Food> GameDirector::m_vFood;
Wall *GameDirector::m_pWall = nullptr;
Snake GameDirector::m_snake;

void GameDirector::gdStart(int argc, char **argv)
{
    gdAddFood();
    gdCreatWall();
    GameRender::rdInitialize(argc, argv);
}

void GameDirector::gdProcess()
{
    handleCollisionAffair();
    
    if (!checkSnakeAlive())
        return;
    
    m_snake.move();
}

void GameDirector::gdKeyPressed(key pressedKey)
{
    switch (pressedKey)
    {
        case key_up:
            m_snake.turn(UP);
            break;
        case key_down:
            m_snake.turn(DOWN);
            break;
        case key_left:
            m_snake.turn(LEFT);
            break;
        case key_right:
            m_snake.turn(RIGHT);
            break;
        case key_esc:
            break;
        default:
            break;
    }
}

Food GameDirector::gdGetFood(size_t n)
{
    return m_vFood[n];
}

size_t GameDirector::gdGetFoodLength()
{
    return m_vFood.size();
}

void GameDirector::gdAddFood()
{
    int32_t foodX = 0;
    int32_t foodY = 0;
    
    do
    {
        foodX = rand() % FIELD_WIDTH;
        foodY = rand() % FIELD_HEIGHT;
    } while (false);
    
    m_vFood.push_back(Food(foodX, foodY));
}

void GameDirector::gdCreatWall()
{
    int width = GameRender::WIDTH;
    int height = GameRender::HEIGHT;
    
    m_pWall = new Wall(0, height, width, 0);
}

Wall *GameDirector::gdGetWall()
{
    return m_pWall;
}

Snake GameDirector::gdGetSnake()
{
    return m_snake;
}

bool GameDirector::checkSnakeAlive()
{
    return m_snake.isAlive();
}

void GameDirector::handleCollisionAffair()
{    
    //检测是否撞墙
    if (isPunchWall())
    {
        m_snake.setSnakeIsAlive(false);
    }
}

bool GameDirector::isPunchWall()
{
    Food headBody = m_snake.getScale(m_snake.getScaleSize() - 1);
    //direction tDirection = m_snake.getDirection();
    int32_t leftButtomX = headBody.X() * GlobalConfig::SQUARE_SIZE + GlobalConfig::SQUARE_DELTA;
    int32_t leftButtomY = headBody.Y() * GlobalConfig::SQUARE_SIZE + GlobalConfig::SQUARE_DELTA;

    return m_pWall->isPunchWall(leftButtomX, leftButtomY);
}
