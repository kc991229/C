#include "game.h"
int main()
{
	int input = 2;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始了\n");
			game();
			break;
		case 0:
			printf("感谢使用\n");
			break;
		default:
			printf("请输入正确的指令\n");
		}
	} while (input);
}