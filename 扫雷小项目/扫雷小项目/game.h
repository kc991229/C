#define _CRT_SECURE_NO_WARNINGS 1
#ifndef _GAME_H_
#define _GAME_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW   9   //������
#define COL   9   //������
#define ROWS  11  //�ڲ�������
#define COLS  11 //�ڲ�������
#define MINE_NUM 10  //���������ɺ�ֱ���޸�
void menu();  //�˵�����
void game();  //��Ϸ���к���
void Show(char board[][ROWS], int row, int col); //��ӡ���̺���
void InitBoard(char board[][COLS], char mine[][COLS], int row, int col);  //���̳�ʼ��
void SetMine(char mine[][COLS], int row, int col, int num);  //������
int FindMine(char mine[][ROWS], char board[][ROWS]);   //ɨ��
int GetMineCount(char mine[][ROWS], int row, int col);  //�õ���������������
int Set_Assist(int i, int arr[], int brr[], int x, int y);//�����׵ĸ�������
#endif