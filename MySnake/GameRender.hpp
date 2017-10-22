//
//  GameRender.hpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/10.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#ifndef GameRender_hpp
#define GameRender_hpp

#include <stdio.h>
#include "Snake.hpp"
#include "GlobalConfig.hpp"

enum color {white, black, red, dark_red, green, dark_green, blue, orange};

class GameRender
{
public:
    static void rdInitialize(int argc, char **argv);
    
    /* Options */
    static const int WIDTH  = 960;
    static const int HEIGHT = 640;
private:
    /* GLUT functions */
    static void grRender();
    static void grWindowResize(int W, int H);
    static void grKeyPressed(unsigned char pressedKey, int x, int y);
    static void grSpecialKeyPressed(int pressedKey, int x, int y);
    static void grFrameControl(int arg);
    
    /* color */
    static void grSetColor(int red, int green, int blue, float alpha = 0.0f);
    static void grPickColor(color newColor, float opacity = 0.0f);
    static float grOpacity(float modifier = 1.0f);

    
    /* Render Object */
    static void grDrawSquare(float x, float y, float size = GlobalConfig::SQUARE_SIZE);
    static void grRenderFood();
    static void grDrawRectangle(float x, float y, float Xlength, float YLength);
    static void grRenderWall(); //画墙
    static void grRenderSnake(Snake snake); //画蛇
    
    /* Fields */
    static int grFrame;
    static float grAngle;
    
private:
    /* Options */
    static const float PI;
    static const char* TITLE;
};

#endif /* GameRender_hpp */
