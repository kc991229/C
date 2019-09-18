#include "text.h"
int main()
{
	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("感谢使用爱您哟\n");
			break;
		case 1:
			printf("亲爱的，游戏开始了，准备好了吗\n");
			game();
			break;
		default:
			printf("别调皮，好好输入\n");
			break;
		}
	} while (input);
	return 0;
}