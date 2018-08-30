#define _CRT_SECURE_NO_WARNINGS 1
#include"view.h"

//��겻��ʾ
void UnvisibleMouse()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curcorInfo;
	GetConsoleCursorInfo(hStdout, &curcorInfo);
	curcorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdout, &curcorInfo);
	system("mode con cols=100 lines=40");
}

//�����ʾ
void VisibleMouse()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curcorInfo;
	GetConsoleCursorInfo(hStdout, &curcorInfo);
	curcorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(hStdout, &curcorInfo);
}

//�ƶ����
static void MoveMouse(int x, int y)
{
	//hStdoutΪstdout����һ�����͵ı�ʾ
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout, coord);
}

//��ӡ�����ߵ�ͷ�ڵ�
void PrintAddSnake(Game *pGame)
{
	MoveMouse(pGame->snake.pFirst->pos.x * 2, pGame->snake.pFirst->pos.y);
	printf("��");
}

//��ӡɾ���ߵ�β�ڵ�
void PrintDelSnakeRear(Game *pGame)
{
	MoveMouse(pGame->snake.pLast->pos.x * 2, pGame->snake.pLast->pos.y);
	printf("  ");
}

//��ӡһ����
void PrintSnake(Game *pGame)
{
	SnakeNode *pCur = pGame->snake.pFirst;
	while (pCur != pGame->snake.pLast->pNext)
	{
		MoveMouse(pCur->pos.x *2, pCur->pos.y);
		printf("��");
		pCur = pCur->pNext;
	}
	fflush(stdout);
}

//��ӡǽ
void PrintWall()
{
	int i = 0;
	int j = 0;
	for (i=0; i<BGWIDTH; i++)
	{
		MoveMouse(i*2, 0);
		printf("��");
		MoveMouse(0, i);
		printf("��");
		MoveMouse(BGWIDTH*2-2, i);
		printf("��");
		MoveMouse(i*2, BGWIDTH-1);
		printf("��");
	}
}

//��ӡ������
void PrintScore(Game *pGame)
{
	int i = 0;
	//����Χ��
	MoveMouse(BGWIDTH * 2 + 23, 15);
	printf("*");
	MoveMouse(BGWIDTH*2+2, 16);
	printf("    �ȼ�");
	MoveMouse(BGWIDTH*2+23, 16);
	printf("*  %d", pGame->scoreStep/5);
	MoveMouse(BGWIDTH * 2 + 23, 17);
	printf("*");
	MoveMouse(BGWIDTH * 2, 18);
	printf("*********************************");
	MoveMouse(BGWIDTH * 2 + 23, 19);
	printf("*");
	MoveMouse(BGWIDTH*2+2, 20);
	printf("    ����");
	MoveMouse(BGWIDTH * 2 + 23, 21);
	printf("*");
	MoveMouse(BGWIDTH*2 +23, 20);
	printf("*  %d", pGame->foodNum+3);
	MoveMouse(BGWIDTH * 2, 22);
	printf("*********************************");

	MoveMouse(BGWIDTH * 2, 10);
	printf("*********************************");
	MoveMouse(BGWIDTH*2+2, 12);
	printf("�����������Ϸ�������д��Ϸ��");
	MoveMouse(BGWIDTH * 2, 14);
	printf("*********************************");

	MoveMouse(BGWIDTH * 2 + 23, 23);
	printf("*");
	MoveMouse(BGWIDTH * 2 + 2, 24);
	printf("    ����");
	MoveMouse(BGWIDTH * 2 + 23, 25);
	printf("*");
	MoveMouse(BGWIDTH * 2 + 23, 24);
	printf("*  %d", pGame->score);
	MoveMouse(BGWIDTH * 2, 26);
	printf("*********************************");
		
	for (i=11; i<26; i++)
	{
		MoveMouse(BGWIDTH * 2, i);
		printf("**");
		MoveMouse(BGWIDTH * 2+31, i);
		printf("**");
	}
}

//�޸ķ���������
void ChangeScore(Game *pGame)
{
	//�ȼ�
	MoveMouse(BGWIDTH * 2 + 23, 16);
	printf("    ");
	MoveMouse(BGWIDTH * 2 + 23, 16);
	printf("*  %d", pGame->foodNum/5+1);
	//����
	MoveMouse(BGWIDTH * 2 + 23, 20);
	printf("    ");
	MoveMouse(BGWIDTH * 2 + 23, 20);
	printf("*  %d", pGame->foodNum+3);
	//����
	MoveMouse(BGWIDTH * 2 + 23, 24);
	printf("    ");
	MoveMouse(BGWIDTH * 2 + 23, 24);
	printf("*  %d", pGame->score);

}

//��ʾʳ��
void PrintFood(Position pos)
{
	MoveMouse(pos.x * 2, pos.y);
	printf("��");
	fflush(stdout);
}

//��ӡ������Ϣ
void PrintDeath(Game *pGame)
{
	MoveMouse(20, 15);
	printf("�����������ˣ���Ϸ������");
}

//ɾ���ɵ�ʳ��λ��
void PrintDelFood(Game *pGame)
{
	MoveMouse(pGame->foodPos.x*2, pGame->foodPos.y);
	printf("  ");
}

//��ӡ��Ϸ����
void PrintEnd(Game *pGame)
{
	MoveMouse(20, 15);
	printf("�����ˣ����ţ�ƣ�");
}
