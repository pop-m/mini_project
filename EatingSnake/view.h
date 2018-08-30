#pragma once
#include"snake.h"

//打印蛇（初始化）
void PrintSnake(Game *pGame);

//打印墙（初始化）
void PrintWall();

//打印分数信息
void PrintScore(Game *pGame);

//修改分数信息
void ChangeScore(Game *pGame);

//打印增加蛇的头节点
void PrintAddSnake(Game *pGame);

//打印删除蛇的尾节点
void PrintDelSnakeRear(Game *pGame);

//显示食物
void PrintFood(Position pos);

//死亡信息
void PrintDeath(Game *pGame);

//删除旧的食物位置
void PrintDelFood(Game *pGame);

//打印游戏翻盘
void PrintEnd(Game *pGame);

//光标不显示
void UnvisibleMouse();

//光标显示
void VisibleMouse();

