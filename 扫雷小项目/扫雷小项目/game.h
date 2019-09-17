#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _GAME_H_
#define _GAME_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW   9   //棋盘行
#define COL   9   //棋盘列
#define ROWS  11  //内部运行行
#define COLS  11 //内部运行列
#define MINE_NUM 10  //雷数量，可宏直接修改
void menu();  //菜单函数
void game();  //游戏运行函数
void Show(char board[][ROWS], int row, int col); //打印雷盘函数
void InitBoard(char board[][COLS], char mine[][COLS], int row, int col);  //雷盘初始化
void SetMine(char mine[][COLS], int row, int col, int num);  //设置雷
int FindMine(char mine[][ROWS], char board[][ROWS]);   //扫雷
int GetMineCount(char mine[][ROWS], int row, int col);  //得到附近雷数量函数
int Set_Assist(int i, int arr[], int brr[], int x, int y);//设置雷的辅助函数
#endif