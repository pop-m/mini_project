#ifndef __MINE_H__    //防止被重复使用
#define __MINE_H__

#define _CRT_SECURE_NO_WARNINGS 1    
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 12        //实际面板的大小
#define COL 12
#define MINE_NUM 10      //雷的数量

 //面板的初始化
void init(char f_mine[ROW][COL], char f_show[12][12]); 

//设置雷
void set_mine(char f_mine[ROW][COL], int f_x, int f_y);

//展开机制
void open(char f_show[ROW][COL], char f_mine[ROW][COL], int i, int j);

//计算周围雷的数量
int mine_count(char f_mine[ROW][COL], int f_x, int f_y);

//打印交互面板
void print_show(char f_show[ROW][COL]);

//游戏主函数
void game(char f_mine[ROW][COL], char f_show[12][12]);

//菜单函数
int menu();

//判断是否排完雷
int is_end(char f_show[ROW][COL]);

#endif // !__MINE_H__

