#include"mine.h"

//��ӡ�˵�
int menu()
{
	int choose = 0;
	printf("*********ɨ����Ϸ**********\n");
	printf("********1����ʼ��Ϸ********\n");
	printf("********0���˳���Ϸ********\n");
	printf("***************************\n");
	printf("��������ţ�");
	scanf("%d", &choose);
	return choose;
}

//��ʼ���ױ�����
void init(char f_mine[ROW][COL], char f_show[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i=0; i<ROW; i++)
	{
		for (j=0; j<COL; j++)
		{
			f_mine[i][j] = '0';
			f_show[i][j] = '*';
		}
	}
}

//��ӡshow���
void print_show(char f_show[ROW][COL])
{
	int i = 0;
	int j = 0;
	printf("      1  2  3  4  5  6  7  8  9  10\n");
	printf("-----------------------------------\n");

	for (i=1; i<ROW-1; i++)
	{
		printf("%2d  |", i);
		for (j=1; j<COL-1; j++)
		{
			if (f_show[i][j] == '0')
			{
				printf("%2c|", ' ');
			}
			else
			{
				printf("%2c|", f_show[i][j]);
			}
		}
		printf("\n-----------------------------------\n");
	}
}

//������
void set_mine(char f_mine[ROW][COL], int f_x, int f_y)
{
	int count = MINE_NUM;
	srand((unsigned) time(NULL));
	int i = 0;
	int j = 0;
	while (count > 0)
	{
		i = rand() % 10 +1;
		j = rand() % 10 + 1;
		if (f_mine[i][j] == '0' && i != f_x && j != f_y)
		{
			f_mine[i][j] = '1';
			count--;
		}
	}
}

//ͳ����Χ�׵�����
int mine_count(char f_mine[ROW][COL], int f_x, int f_y)
{
	int count = 0;
	int i;
	int j;
	if (f_mine[f_x - 1][f_y - 1] == '1') count++;
	if (f_mine[f_x  - 1][f_y] == '1') count++;
	if (f_mine[f_x - 1][f_y + 1] == '1') count++;
	if (f_mine[f_x ][f_y - 1] == '1') count++;
	if (f_mine[f_x][f_y ] == '1') count++;
	if (f_mine[f_x][f_y + 1] == '1') count++;
	if (f_mine[f_x + 1][f_y - 1] == '1') count++;
	if (f_mine[f_x + 1][f_y] == '1') count++;
	if (f_mine[f_x + 1][f_y+1] == '1') count++;
	return count;
}

//չ����Χ
void open(char f_show[ROW][COL], char f_mine[ROW][COL], int i, int j)
{
	int ret = mine_count(f_mine, i, j);
	f_show[i][j] = '0' + ret;
		if (ret == 0)
		{
			//����Χ���죬һ���Կ���չ���뱾�����������׵����
			if ((i - 1) >= 1 && (i - 1) <= (ROW - 1) && (j - 1)>=1 && (j - 1)<=(COL - 1) && f_show[i - 1][j - 1] == '*') 
				open(f_show, f_mine, i - 1, j - 1);
			if ((i - 1) >= 1 && (i - 1) <= (ROW - 1) && j>=1 && j<=(COL - 1) && f_show[i - 1][j] == '*')
				open(f_show, f_mine, i - 1, j);
			if ((i - 1) >= 1 && (i - 1) <= (ROW - 1) && (j + 1)>=1 && (j + 1)<=(COL - 1) && f_show[i - 1][j+1] == '*')
				open(f_show, f_mine, i - 1, j + 1);
			if (i >= 1 && i <= (ROW - 1) && (j - 1)>=1 && (j - 1)<=(COL - 1) && f_show[i][j - 1] == '*')
				open(f_show, f_mine, i, j - 1);
			if (i >= 1 && i <= (ROW - 1) && (j + 1)>=1 && (j + 1)<=(COL - 1) && f_show[i][j + 1] == '*')
				open(f_show, f_mine, i, j + 1);
			if ((i + 1) >= 1 && (i + 1) <= (ROW - 1) && (j - 1)>=1 && (j - 1)<=(COL - 1) && f_show[i + 1][j - 1] == '*')
				open(f_show, f_mine, i + 1, j - 1);
			if ((i + 1) >= 1 && (i + 1) <= (ROW - 1) && j>=1 && j<=(COL - 1) && f_show[i + 1][j] == '*')
				open(f_show, f_mine, i + 1, j);
			if ((i + 1) >= 1 && (i + 1) <= (ROW - 1) && (j + 1)>=1 && (j + 1)<=(COL - 1) && f_show[i + 1][j + 1] == '*')
				open(f_show, f_mine, i + 1, j + 1);
		}
}

//�ж��Ƿ�������
int is_end(char f_show[ROW][COL])
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i=1; i<ROW-1; i++)
	{
		for (j=1; j<COL-1; j++)
		{
			if (f_show[i][j] == '*')
				count++;
		}
	}
	if (count == MINE_NUM)
		return 1;
	else
		return 0;
}

//��Ϸ����
void game(char f_mine[12][12], char f_show[12][12])
{
	int x = 0;
	int y = 0;
	init(f_mine, f_show);
	print_show(f_show);

	while(1)
	{
		printf("������Ҫ�򿪵����꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= ROW - 2 && y >= 1 && y <= COL - 2)
			break;
		else
			printf("�������");
	}
	set_mine(f_mine, x, y);
	print_show(f_mine);
	while (is_end(f_show) == 0)
	{
		if (x >= 1 && x <= ROW - 2 && y >= 1 && y <= COL - 2)
		{
			if (f_mine[x][y] == '1')
			{
				printf("BOOM���㱻ը���ˣ�\n");
				print_show(f_mine);
				return;
			}
			else
			{
				open(f_show, f_mine, x, y);
			}
		}
		else
		{
			printf("����Ƿ���\n");
		}
		print_show(f_show);
		printf("������Ҫ�򿪵����꣺");
		scanf("%d%d", &x, &y);
	}
	printf("��ϲ����ϲ����ϲ����ϲѽ��\n");
}
