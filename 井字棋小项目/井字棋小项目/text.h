#define _CRT_SECURE_NO_WARNINGS 1
#ifndef  __TEXT__H_
#define  __TEXT__H_

#define ROW 3     //�궨�����������
#define COL 3     //�궨�����������
#include<stdio.h>

void menu();  //��ӡ�˵�����
void InitBoard(char board[][ROW], int row, int col, int set);  //��ʼ�����̺���
void ShowBoard(char board[][ROW], int row, int col);//��ӡ���̺���
char IsWin(char board[][ROW], int row, int col); //�ж���Ӯ����
void ComputerMove(char board[][ROW], int row, int col);//�����ƶ�����
void PlayerMove(char board[][ROW], int row, int col); //����ƶ�����
static int IsFull(char board[][ROW], int row, int col); //�ж������Ƿ���������
void game();//��Ϸ������Ҫ����
void game();
#endif
