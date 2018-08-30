#include"snake.h"
#include"view.h"


int main(void)
{
	//������Ϸ����
	Game game;
	Game *pGame = &game;
	InitGame(pGame);
	//��ʼ����ӡ
	//�������Լ��趨���ڴ�С
	UnvisibleMouse();
	PrintWall();	//��ӡǽ
	PrintSnake(pGame);	//��ӡ��
	PrintScore(pGame);	//��ӡ�������
	PrintFood(pGame->foodPos); 	//��ӡʳ��
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

		//��ȡ��һ��λ��
		Position nextPos = GetNextPos(pGame);
		//�ж���һ��λ���Ƿ�����
		if (NextPosIsDeath(pGame, nextPos) == 0)
		{
			//�ߵ��ƶ����ƶ�һ��
			//һ��ͷ��һ��βɾ
			//��ͷ�岢��ӡ�²���Ľڵ㣬����Ե�ʳ��Ǿͽ�β���Ľڵ���Ϊ�ո�Ȼ���ٽ�β�����ߵ�������ɾ��
			AddSnakeNode(pGame, nextPos);
			
			//û��ʳ���������
			if (IsGetedFood(pGame) == 0)
			{
				//�Ե�ʳ��ʹ�ӡͷȻ���ٴ�ӡɾβ��Ȼ��������ɾβ
				PrintAddSnake(pGame);
				PrintDelSnakeRear(pGame);
				DelSnakeRear(pGame);
			}
			else  //�Ե�ʳ��з��̵Ŀ���
			{
				//�������1˵����Ϸ����
				int stat = AddScoreAndChangeSpeed(pGame);
				if (stat == 1)
				{
					PrintEnd(pGame);
					VisibleMouse();
					Over(pGame);
				}
				//��ӡ��ͷ����
				PrintAddSnake(pGame);
				//��ȡ��һ��ʳ��
				GetFoodPositioin(pGame);
				PrintFood(pGame->foodPos);
				//�޸ķ�����Ϣ
				ChangeScore(pGame);
			}
		}
		else
		{
			//����
			PrintDeath(pGame);
			VisibleMouse();
			Over(pGame);
		}
		Sleep(pGame->speed);
	}
	return 0;
}