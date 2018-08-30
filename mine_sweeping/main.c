#include"mine.h"


int main()
{
	char mine[ROW][COL] = { '0' };
	char show[ROW][COL] = { '0' };
	int choose = 0;
	do
	{
		choose = menu();
		switch (choose)
		{
		case 1:
			game(mine, show);
			break;
		case 0:
			printf("ÓÎÏ·ÒÑÍË³ö£¡\n");
			break;
		default:
			printf("ÊäÈë´íÎó£º\n");
			break;
		}

	} while (choose != 0);

	return 0;
}
