#define _CRT_SECURE_NO_WARNINGS 1
#include"view.h"

//光标不显示
void UnvisibleMouse()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curcorInfo;
	GetConsoleCursorInfo(hStdout, &curcorInfo);
	curcorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdout, &curcorInfo);
	system("mode con cols=100 lines=40");
}

//光标显示
void VisibleMouse()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO curcorInfo;
	GetConsoleCursorInfo(hStdout, &curcorInfo);
	curcorInfo.bVisible = TRUE;
	SetConsoleCursorInfo(hStdout, &curcorInfo);
}

//移动光标
static void MoveMouse(int x, int y)
{
	//hStdout为stdout的另一种类型的表示
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hStdout, coord);
}

//打印增加蛇的头节点
void PrintAddSnake(Game *pGame)
{
	MoveMouse(pGame->snake.pFirst->pos.x * 2, pGame->snake.pFirst->pos.y);
	printf("▓");
}

//打印删除蛇的尾节点
void PrintDelSnakeRear(Game *pGame)
{
	MoveMouse(pGame->snake.pLast->pos.x * 2, pGame->snake.pLast->pos.y);
	printf("  ");
}

//打印一条蛇
void PrintSnake(Game *pGame)
{
	SnakeNode *pCur = pGame->snake.pFirst;
	while (pCur != pGame->snake.pLast->pNext)
	{
		MoveMouse(pCur->pos.x *2, pCur->pos.y);
		printf("▓");
		pCur = pCur->pNext;
	}
	fflush(stdout);
}

//打印墙
void PrintWall()
{
	int i = 0;
	int j = 0;
	for (i=0; i<BGWIDTH; i++)
	{
		MoveMouse(i*2, 0);
		printf("■");
		MoveMouse(0, i);
		printf("■");
		MoveMouse(BGWIDTH*2-2, i);
		printf("■");
		MoveMouse(i*2, BGWIDTH-1);
		printf("■");
	}
}

//打印分数栏
void PrintScore(Game *pGame)
{
	int i = 0;
	//分数围栏
	MoveMouse(BGWIDTH * 2 + 23, 15);
	printf("*");
	MoveMouse(BGWIDTH*2+2, 16);
	printf("    等级");
	MoveMouse(BGWIDTH*2+23, 16);
	printf("*  %d", pGame->scoreStep/5);
	MoveMouse(BGWIDTH * 2 + 23, 17);
	printf("*");
	MoveMouse(BGWIDTH * 2, 18);
	printf("*********************************");
	MoveMouse(BGWIDTH * 2 + 23, 19);
	printf("*");
	MoveMouse(BGWIDTH*2+2, 20);
	printf("    长度");
	MoveMouse(BGWIDTH * 2 + 23, 21);
	printf("*");
	MoveMouse(BGWIDTH*2 +23, 20);
	printf("*  %d", pGame->foodNum+3);
	MoveMouse(BGWIDTH * 2, 22);
	printf("*********************************");

	MoveMouse(BGWIDTH * 2, 10);
	printf("*********************************");
	MoveMouse(BGWIDTH*2+2, 12);
	printf("请勿沉迷玩游戏，请沉迷写游戏！");
	MoveMouse(BGWIDTH * 2, 14);
	printf("*********************************");

	MoveMouse(BGWIDTH * 2 + 23, 23);
	printf("*");
	MoveMouse(BGWIDTH * 2 + 2, 24);
	printf("    分数");
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

//修改分数栏数据
void ChangeScore(Game *pGame)
{
	//等级
	MoveMouse(BGWIDTH * 2 + 23, 16);
	printf("    ");
	MoveMouse(BGWIDTH * 2 + 23, 16);
	printf("*  %d", pGame->foodNum/5+1);
	//长度
	MoveMouse(BGWIDTH * 2 + 23, 20);
	printf("    ");
	MoveMouse(BGWIDTH * 2 + 23, 20);
	printf("*  %d", pGame->foodNum+3);
	//分数
	MoveMouse(BGWIDTH * 2 + 23, 24);
	printf("    ");
	MoveMouse(BGWIDTH * 2 + 23, 24);
	printf("*  %d", pGame->score);

}

//显示食物
void PrintFood(Position pos)
{
	MoveMouse(pos.x * 2, pos.y);
	printf("¤");
	fflush(stdout);
}

//打印死亡信息
void PrintDeath(Game *pGame)
{
	MoveMouse(20, 15);
	printf("垃圾！你死了，游戏结束！");
}

//删除旧的食物位置
void PrintDelFood(Game *pGame)
{
	MoveMouse(pGame->foodPos.x*2, pGame->foodPos.y);
	printf("  ");
}

//打印游戏翻盘
void PrintEnd(Game *pGame)
{
	MoveMouse(20, 15);
	printf("翻盘了，你很牛逼！");
}
