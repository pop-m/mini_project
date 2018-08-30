#define _CRT_SECURE_NO_WARNINGS 1
#include"snake.h"


//�����ߵĽڵ�
 static SnakeNode* BuySnakeNode(Position pos)
{
	SnakeNode *pNewNode = (SnakeNode*)malloc(sizeof(SnakeNode));
	pNewNode->pNext = NULL;
	pNewNode->pos.x = pos.x;
	pNewNode->pos.y = pos.y;
	return pNewNode;
}

//�߼�ͷ
void AddSnakeNode(Game *pGame, Position pos)
{
	SnakeNode *pNewNode = BuySnakeNode(pos);
	pNewNode->pNext = pGame->snake.pFirst;
	pGame->snake.pFirst = pNewNode;
}

//��ɾβ
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

//��ʼ����Ϸ����(�����ڵ�)
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
	//��ʼ����Ϊ����
	pGame->snake.direct = RIGHT;
	//�������һ��ʳ��
	GetFoodPositioin(pGame);
	//��Ϸ״̬��Ϊ����̬
	pGame->stat = 1;
	//��ʼ��û500������ǰ��һ��
	pGame->speed = 500;
	//��ʼ���ٵ���ʳ����Ϊ0
	pGame->foodNum = 0;
}

//������һ��λ��
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

//��Ϸ����
 void Over(Game *pGame)
{
	 system("pause");
	 exit(0);
}

//��һ��λ���Ƿ�����,1�������ˣ�0����û��
int NextPosIsDeath(Game *pGame, Position pos)
{

	//��һ��λ���Ƿ���ǽ
	if (pos.x > BGWIDTH-2 || pos.y > BGHIGHT - 2 || pos.x < 1 || pos.y < 1)
	{
		return 1;
	}
	//��һ��λ���Ƿ����Լ�����Ĳ���
	if (IsCoincide(pGame, pos.x, pos.y) == 1)
	{
		return 1;
	}
	return 0;
}

//����λ���Ƿ���ʳ��
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

//�ж�������λ���Ƿ��������غ�
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

//��ȡ�����ʳ���λ��
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


//�ӷ��Լ�����,����1,������Ϸ����
int AddScoreAndChangeSpeed(Game *pGame)
{
	pGame->foodNum++;
	pGame->score += pGame->scoreStep;
	//ÿ������ʳ�ÿ��ʳ��ķ����ͻ�����5
	pGame->scoreStep = 5 + (pGame->foodNum / 5) * 5;
	//û������ʳ��ߵ��ٶȾͻ�����20����
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
