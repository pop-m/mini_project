#include"snake.h"
#include"view.h"


int main(void)
{
	//创建游戏数据
	Game game;
	Game *pGame = &game;
	InitGame(pGame);
	//初始化打印
	//清楚光标以及设定窗口大小
	UnvisibleMouse();
	PrintWall();	//打印墙
	PrintSnake(pGame);	//打印蛇
	PrintScore(pGame);	//打印分数相关
	PrintFood(pGame->foodPos); 	//打印食物
	srand((unsigned int)time(NULL));
	while (1)
	{
		if (GetAsyncKeyState(VK_UP) && pGame->snake.direct != DOWN)
			pGame->snake.direct = UP;
		else if (GetAsyncKeyState(VK_DOWN) && pGame->snake.direct != UP)
			pGame->snake.direct = DOWN;
		else if (GetAsyncKeyState(VK_RIGHT) && pGame->snake.direct != LEFT)
			pGame->snake.direct = RIGHT;
		else if (GetAsyncKeyState(VK_LEFT) && pGame->snake.direct != RIGHT)
			pGame->snake.direct = LEFT;

		//获取下一个位置
		Position nextPos = GetNextPos(pGame);
		//判断下一个位置是否死了
		if (NextPosIsDeath(pGame, nextPos) == 0)
		{
			//蛇的移动（移动一格）
			//一次头插一次尾删
			//先头插并打印新插入的节点，如果吃到食物，那就将尾部的节点置为空格，然后再将尾部从蛇的链表中删掉
			AddSnakeNode(pGame, nextPos);
			
			//没到食物，不可能死
			if (IsGetedFood(pGame) == 0)
			{
				//吃到食物就打印头然后再打印删尾，然后再真正删尾
				PrintAddSnake(pGame);
				PrintDelSnakeRear(pGame);
				DelSnakeRear(pGame);
			}
			else  //吃到食物，有翻盘的可能
			{
				//如果返回1说明游戏翻盘
				int stat = AddScoreAndChangeSpeed(pGame);
				if (stat == 1)
				{
					PrintEnd(pGame);
					VisibleMouse();
					Over(pGame);
				}
				//打印蛇头增加
				PrintAddSnake(pGame);
				//获取下一个食物
				GetFoodPositioin(pGame);
				PrintFood(pGame->foodPos);
				//修改分数信息
				ChangeScore(pGame);
			}
		}
		else
		{
			//死了
			PrintDeath(pGame);
			VisibleMouse();
			Over(pGame);
		}
		Sleep(pGame->speed);
	}
	return 0;
}