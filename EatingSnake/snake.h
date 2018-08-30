#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

//每迟到一个食物的得分
#define STEPSCORE 5
//游戏开始时蛇的位置
#define STARTPOSX 10
#define STARTPOSY 10
//定义背景 的大小
#define BGWIDTH 32
#define BGHIGHT 32

//位置
typedef struct Position
{
	int x;
	int y;
} Position;

//蛇的节点
typedef struct SnakeNode
{
	Position pos;
	struct SnakeNode *pNext;
}	SnakeNode;

//蛇移动的方向
typedef enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	Direction;

//蛇整体
typedef struct Snake
{
	SnakeNode *pFirst;
	SnakeNode *pLast;
	Direction direct;
}	Snake;

//游戏整体
typedef struct Game
{
	Snake snake;
	//每个食物的得分
	int scoreStep;
	//总得分
	int score;
	Position foodPos;
	//当前游戏状态 0代表死亡， 1代表正在运行， 2代表暂停
	int stat;
	int speed;
	int foodNum;
}	Game;


//初始化游戏数据(三个节点)
void InitGame(Game *pGame);

//得到下一个位置
Position GetNextPos(Game *pGame);

//死亡处理
void Over(Game *pGame);

//获取一个食物的位置
void GetFoodPositioin(Game *pGame);

//是否吃到食物
int IsGetedFood(Game *pGame);

//加分以及变速
int AddScoreAndChangeSpeed(Game *pGame);

//下一个位置是否死掉
int NextPosIsDeath(Game *pGame, Position pos);

//蛇删尾
void DelSnakeRear(Game *pGame);

//蛇加头
void AddSnakeNode(Game *pGame, Position pos);
