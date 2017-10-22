//
//  GameRender.cpp
//  MySnake
//
//  Created by JiangZhongjin on 2017/10/10.
//  Copyright © 2017年 JiangZhongjin. All rights reserved.
//

#include "GameRender.hpp"
#ifdef __APPLE__
#  include <OPENGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/GLUT.h>
#endif
#include <stdlib.h>
#include <math.h>
#include "GameDirector.hpp"

/* Static fields initialization */
int GameRender::grFrame = 0;
float GameRender::grAngle = 0.0f;

/* Static constant fields initialization */
const float GameRender::PI = 3.14159265358979323846f;
const char *GameRender::TITLE = "Gradyjiang's Snake";

void GameRender::rdInitialize(int argc, char **argv)
{
    /* Initialising */
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(WIDTH, HEIGHT);
        glutCreateWindow(TITLE);
    }
    
    /* Function regestration */
    {
        glutDisplayFunc(grRender);
        glutReshapeFunc(grWindowResize);
        glutKeyboardFunc(grKeyPressed);
        glutSpecialFunc(grSpecialKeyPressed);
        glutTimerFunc(1000/GlobalConfig::FRAME_RATE, grFrameControl, 0);
    }
    
    /* Initialisation */
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glViewport(0, 0, WIDTH, HEIGHT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, WIDTH, 0, HEIGHT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
    
    /* Options */
    {
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glShadeModel(GL_SMOOTH);
    }
    
    /* Start main loop */
    glutMainLoop();
}

void GameRender::grRender()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glBegin(GL_QUADS);
    grRenderFood();
    grRenderWall();
    grRenderSnake(GameDirector::gdGetSnake());
    glEnd();
    
    /* Rendering finished */
    glutSwapBuffers();
}

void GameRender::grWindowResize(GLsizei W, GLsizei H)
{
    glutReshapeWindow(WIDTH, HEIGHT);
    int left = (glutGet(GLUT_SCREEN_WIDTH) - WIDTH) / 2;
    int top = (glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) / 2;
    glutPositionWindow(left, top);
}

void GameRender::grKeyPressed(unsigned char pressedKey, int x, int y)
{
    switch (pressedKey)
    {
        case 'w':
            GameDirector::gdKeyPressed(key_up);
            break;
        case 'd':
            GameDirector::gdKeyPressed(key_right);
            break;
        case 's':
            GameDirector::gdKeyPressed(key_down);
            break;
        case 'a':
            GameDirector::gdKeyPressed(key_left);
            break;
        case 27: // stands for ESC
            grAngle = 0;
            GameDirector::gdKeyPressed(key_esc);
            break;
    }
}

void GameRender::grSpecialKeyPressed(int pressedKey, int x, int y)
{
    switch (pressedKey)
    {
        case GLUT_KEY_UP:
            GameDirector::gdKeyPressed(key_up);
            break;
        case GLUT_KEY_RIGHT:
            GameDirector::gdKeyPressed(key_right);
            break;
        case GLUT_KEY_DOWN:
            GameDirector::gdKeyPressed(key_down);
            break;
        case GLUT_KEY_LEFT:
            GameDirector::gdKeyPressed(key_left);
            break;
    }
}

void GameRender::grFrameControl(int arg)
{    
    if (grFrame == 60)
    {
        grFrame = 0;
    }
    
    grFrame += 1;
    grAngle += PI / (GlobalConfig::FRAME_RATE / 2);
    
    if (grFrame % (GlobalConfig::FRAME_RATE / GlobalConfig::SNAKE_SPEED) == 0)
        GameDirector::gdProcess();
    
    glutPostRedisplay();
    glutTimerFunc(1000 / GlobalConfig::FRAME_RATE, grFrameControl, 0);
}

void GameRender::grPickColor(color newColor, float opacity)
{
    switch(newColor)
    {
        case white:
            grSetColor(255, 255, 255);
            break;
        case black:
            grSetColor(000, 000, 000, opacity);
            break;
        case red:
            grSetColor(220, 000, 000, opacity);
            break;
        case dark_red:
            grSetColor(175, 000, 000, opacity);
            break;
        case green:
            grSetColor(115, 195, 75, opacity);
            break;
        case dark_green:
            grSetColor(90, 150, 60, opacity);
            break;
        case blue:
            grSetColor(40, 115, 220, opacity);
            break;
        case orange:
            grSetColor(215, 140, 35, opacity);
            break;
    }
}

void GameRender::grSetColor(int red, int green, int blue, float alpha)
{
    GLubyte red_alpha   = (255 - red)   * alpha;
    GLubyte green_alpha = (255 - green) * alpha;
    GLubyte blue_alpha  = (255 - blue)  * alpha;
    glColor3ub(red + red_alpha, green + green_alpha, blue + blue_alpha);
}

float GameRender::grOpacity(float modifier) {
    return (sin(grAngle * modifier + 3*PI/2) + 1) / 2;
}

void GameRender::grRenderFood()
{
    for (int i = 0; i < GameDirector::gdGetFoodLength(); i++)
    {
        int X = GameDirector::gdGetFood(i).X() * GlobalConfig::SQUARE_SIZE;
        int Y = GameDirector::gdGetFood(i).Y() * GlobalConfig::SQUARE_SIZE;
        grPickColor(blue, grOpacity());
        grDrawSquare(X, Y);
    }
}

void GameRender::grRenderSnake(Snake snake)
{
    for (size_t i = 0; i < snake.getScaleSize(); i++)
    {
        int x = snake.getScale(i).X() * GlobalConfig::SQUARE_SIZE;
        int y = snake.getScale(i).Y() * GlobalConfig::SQUARE_SIZE;
        if (i == snake.getScaleSize() - 1)
        {
            if (snake.isAlive())
            {
                grPickColor(dark_green);
            }
            else
            {
                grPickColor(dark_red);
            }
        }
        else
        {
            if (snake.isAlive())
            {
                grPickColor(green);
            }
            else
            {
                grPickColor(red);
            }
        }
        grDrawSquare(x, y);
    }
}


void GameRender::grDrawSquare(float x, float y, float size)
{
    float delta = GlobalConfig::SQUARE_DELTA;
    //实际边长 size - delta
    glVertex2f(x + delta, y + delta);
    glVertex2f(x + size - delta, y + delta);
    glVertex2f(x + size - delta, y + size - delta);
    glVertex2f(x + delta, y + size - delta);
}

void GameRender::grRenderWall()
{
    Wall *pWall = GameDirector::gdGetWall();
    
    grPickColor(orange);
    
    //top horizontal line
    grDrawRectangle(pWall->m_LeftTopPoint.X,
                    pWall->m_LeftTopPoint.Y,
                    pWall->m_RightTopPoint.X - pWall->m_LeftTopPoint.X,
                    Wall::WALL_WIDTH);
    
    //left vertical line
    grDrawRectangle(pWall->m_LeftTopPoint.X,
                    pWall->m_RightTopPoint.Y,
                    Wall::WALL_WIDTH,
                    pWall->m_RightTopPoint.Y - pWall->m_LeftBottomPoint.Y);
    
    //bottom horizontal line
    grDrawRectangle(pWall->m_LeftBottomPoint.X,
                    pWall->m_LeftBottomPoint.Y + Wall::WALL_WIDTH,
                    pWall->m_RightBottomPoint.X - pWall->m_LeftBottomPoint.X,
                    Wall::WALL_WIDTH);
    
    //right vertical line
    grDrawRectangle(pWall->m_RightTopPoint.X - Wall::WALL_WIDTH,
                    pWall->m_RightTopPoint.Y,
                    Wall::WALL_WIDTH,
                    pWall->m_RightTopPoint.Y - pWall->m_RightBottomPoint.Y);
}

void GameRender::grDrawRectangle(float x, float y, float Xlength, float YLength)
{
    glVertex2f(x, y);
    glVertex2f(x + Xlength, y);
    glVertex2f(x + Xlength, y - YLength);
    glVertex2f(x, y - YLength);
}

