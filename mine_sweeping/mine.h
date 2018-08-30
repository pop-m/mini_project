#ifndef __MINE_H__    //��ֹ���ظ�ʹ��
#define __MINE_H__

#define _CRT_SECURE_NO_WARNINGS 1    
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 12        //ʵ�����Ĵ�С
#define COL 12
#define MINE_NUM 10      //�׵�����

 //���ĳ�ʼ��
void init(char f_mine[ROW][COL], char f_show[12][12]); 

//������
void set_mine(char f_mine[ROW][COL], int f_x, int f_y);

//չ������
void open(char f_show[ROW][COL], char f_mine[ROW][COL], int i, int j);

//������Χ�׵�����
int mine_count(char f_mine[ROW][COL], int f_x, int f_y);

//��ӡ�������
void print_show(char f_show[ROW][COL]);

//��Ϸ������
void game(char f_mine[ROW][COL], char f_show[12][12]);

//�˵�����
int menu();

//�ж��Ƿ�������
int is_end(char f_show[ROW][COL]);

#endif // !__MINE_H__

