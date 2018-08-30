#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>

//ÿ�ٵ�һ��ʳ��ĵ÷�
#define STEPSCORE 5
//��Ϸ��ʼʱ�ߵ�λ��
#define STARTPOSX 10
#define STARTPOSY 10
//���屳�� �Ĵ�С
#define BGWIDTH 32
#define BGHIGHT 32

//λ��
typedef struct Position
{
	int x;
	int y;
} Position;

//�ߵĽڵ�
typedef struct SnakeNode
{
	Position pos;
	struct SnakeNode *pNext;
}	SnakeNode;

//���ƶ��ķ���
typedef enum Direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	Direction;

//������
typedef struct Snake
{
	SnakeNode *pFirst;
	SnakeNode *pLast;
	Direction direct;
}	Snake;

//��Ϸ����
typedef struct Game
{
	Snake snake;
	//ÿ��ʳ��ĵ÷�
	int scoreStep;
	//�ܵ÷�
	int score;
	Position foodPos;
	//��ǰ��Ϸ״̬ 0���������� 1�����������У� 2������ͣ
	int stat;
	int speed;
	int foodNum;
}	Game;


//��ʼ����Ϸ����(�����ڵ�)
void InitGame(Game *pGame);

//�õ���һ��λ��
Position GetNextPos(Game *pGame);

//��������
void Over(Game *pGame);

//��ȡһ��ʳ���λ��
void GetFoodPositioin(Game *pGame);

//�Ƿ�Ե�ʳ��
int IsGetedFood(Game *pGame);

//�ӷ��Լ�����
int AddScoreAndChangeSpeed(Game *pGame);

//��һ��λ���Ƿ�����
int NextPosIsDeath(Game *pGame, Position pos);

//��ɾβ
void DelSnakeRear(Game *pGame);

//�߼�ͷ
void AddSnakeNode(Game *pGame, Position pos);
