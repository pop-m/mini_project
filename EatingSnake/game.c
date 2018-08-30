#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"


//申请蛇的节点
 static SnakeNode* BuySnakeNode(Position pos)
{
	SnakeNode *pNewNode = (SnakeNode*)malloc(sizeof(SnakeNode));
	pNewNode->pNext = NULL;
	pNewNode->pos.x = pos.x;
	pNewNode->pos.y = pos.y;
	return pNewNode;
}

//蛇加头
void AddSnakeNode(Game *pGame, Position pos)
{
	SnakeNode *pNewNode = BuySnakeNode(pos);
	pNewNode->pNext = pGame->snake.pFirst;
	pGame->snake.pFirst = pNewNode;
}

//蛇删尾
void DelSnakeRear(Game *pGame)
{
	SnakeNode* pCurNode = pGame->snake.pFirst;
	while (pCurNode->pNext->pNext != NULL)
	{
		pCurNode = pCurNode->pNext;
	}
	free(pGame->snake.pLast);
	pCurNode->pNext = NULL;
	pGame->snake.pLast = pCurNode;
}

//初始化游戏数据(三个节点)
void InitGame( Game *pGame)
{
	pGame->score = 0;
	pGame->scoreStep = STEPSCORE;
	Position pos = { STARTPOSX,STARTPOSY };
	pGame->snake.pLast = BuySnakeNode(pos);
	pGame->snake.pFirst = pGame->snake.pLast;
	pos.x++;
	AddSnakeNode(pGame,pos);
	pos.x++;
	AddSnakeNode(pGame,pos);
	//初始方向为向右
	pGame->snake.direct = RIGHT;
	//随机生成一个食物
	GetFoodPositioin(pGame);
	//游戏状态设为运行态
	pGame->stat = 1;
	//初始化没500毫秒向前走一次
	pGame->speed = 500;
	//初始化迟到的食物数为0
	pGame->foodNum = 0;
}

//计算下一个位置
 Position GetNextPos(Game *pGame)
{
	int x = pGame->snake.pFirst->pos.x;
	int y = pGame->snake.pFirst->pos.y;
	Direction direct = pGame->snake.direct;
	switch (direct)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	}
	Position pos = { x,y };
	return pos;
}

//游戏结束
 void Over(Game *pGame)
{
	 system("pause");
	 exit(0);
}

//下一个位置是否死掉,1代表死了，0代表没死
int NextPosIsDeath(Game *pGame, Position pos)
{

	//下一个位置是否是墙
	if (pos.x > BGWIDTH-2 || pos.y > BGHIGHT - 2 || pos.x < 1 || pos.y < 1)
	{
		return 1;
	}
	//下一个位置是否是自己身体的部分
	if (IsCoincide(pGame, pos.x, pos.y) == 1)
	{
		return 1;
	}
	return 0;
}

//给定位置是否是食物
int IsGetedFood(Game *pGame)
{
	if (pGame->snake.pFirst->pos.x == pGame->foodPos.x && pGame->snake.pFirst->pos.y == pGame->foodPos.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//判断所给的位置是否与蛇身重合
 static int IsCoincide(Game *pGame, int x, int y)
{
	SnakeNode *pCur = pGame->snake.pFirst;
	while (pCur != NULL)
	{
		if (pCur->pos.x == x && pCur->pos.y == y)
		{
			return 1;
		}
		pCur = pCur->pNext;
	}
	return 0;
}

//获取合理的食物的位置
void GetFoodPositioin(Game *pGame)
{
	int x = 0;
	int y = 0;
	do
	{
		x = rand() % 29 + 1;
		y = rand() % 29 + 1;
	} while (IsCoincide(pGame, x, y));
	pGame->foodPos.x = x;
	pGame->foodPos.y = y;
}


//加分以及变速,返回1,代表游戏结束
int AddScoreAndChangeSpeed(Game *pGame)
{
	pGame->foodNum++;
	pGame->score += pGame->scoreStep;
	//每多吃五个食物，每个食物的分数就会增加5
	pGame->scoreStep = 5 + (pGame->foodNum / 5) * 5;
	//没多吃五个食物，蛇的速度就会增加20毫秒
	pGame->speed = 500 - (pGame->foodNum / 5) * 30;
	if (pGame->foodNum / 5 + 1 >16)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
