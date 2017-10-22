//
//  GameDirector.hpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/10.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#ifndef GameDirector_hpp
#define GameDirector_hpp

#include <stdio.h>
#include "food.hpp"
#include <vector>
#include "Wall.hpp"
#include "Snake.hpp"

enum key {key_up, key_right, key_down, key_left, key_esc};

class GameDirector
{
public:
    static void gdStart(int argc, char **argv);
    static void gdProcess();
    static Food gdGetFood(size_t n);
    static size_t gdGetFoodLength();
    static void gdAddFood();
    static void gdCreatWall();
    static Wall *gdGetWall();
    static void gdKeyPressed(key pressedKey);
    static Snake gdGetSnake();
    
private:
    static std::vector<Food> m_vFood;
    static Wall *m_pWall;
    static Snake m_snake;
    
    static const size_t FIELD_WIDTH = 30;
    static const size_t FIELD_HEIGHT = 20;
    
    static bool checkSnakeAlive();
    static void handleCollisionAffair();
    static bool isPunchWall();
};

#endif /* GameDirector_hpp */
