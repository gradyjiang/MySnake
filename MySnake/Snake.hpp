//
//  Snake.hpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/20.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include <vector>
#include "food.hpp"

using std::vector;
enum direction {UP, DOWN, RIGHT, LEFT, NONE};

class Snake
{
private:
    direction mDirection;
    vector<Food> m_vBody;
    bool m_isAlive;
    
    static const size_t csSnakeSize = 4;
    static const int csSnakeInitialPositionX = 0;
    static const int csSnakeInitialPositionY = 9;
    
    void addScale();
    void delScale();

public:
    Snake(size_t size = csSnakeSize);
    void turn(direction tDirection);
    Food getScale(size_t index);
    size_t getScaleSize();
    void move();
    bool isAlive();
    void setSnakeIsAlive(bool alive);
    direction getDirection();
    
};

#endif /* Snake_hpp */
