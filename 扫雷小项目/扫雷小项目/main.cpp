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
			printf("��Ϸ��ʼ��\n");
			game();
			break;
		case 0:
			printf("��лʹ��\n");
			break;
		default:
			printf("��������ȷ��ָ��\n");
		}
	} while (input);
}