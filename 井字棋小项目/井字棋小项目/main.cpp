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
			printf("��лʹ�ð���Ӵ\n");
			break;
		case 1:
			printf("�װ��ģ���Ϸ��ʼ�ˣ�׼��������\n");
			game();
			break;
		default:
			printf("���Ƥ���ú�����\n");
			break;
		}
	} while (input);
	return 0;
}