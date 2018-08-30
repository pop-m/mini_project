#pragma once
#include"snake.h"

//��ӡ�ߣ���ʼ����
void PrintSnake(Game *pGame);

//��ӡǽ����ʼ����
void PrintWall();

//��ӡ������Ϣ
void PrintScore(Game *pGame);

//�޸ķ�����Ϣ
void ChangeScore(Game *pGame);

//��ӡ�����ߵ�ͷ�ڵ�
void PrintAddSnake(Game *pGame);

//��ӡɾ���ߵ�β�ڵ�
void PrintDelSnakeRear(Game *pGame);

//��ʾʳ��
void PrintFood(Position pos);

//������Ϣ
void PrintDeath(Game *pGame);

//ɾ���ɵ�ʳ��λ��
void PrintDelFood(Game *pGame);

//��ӡ��Ϸ����
void PrintEnd(Game *pGame);

//��겻��ʾ
void UnvisibleMouse();

//�����ʾ
void VisibleMouse();

