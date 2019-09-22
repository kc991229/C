#include "list.h"
int i, j, l;
struct xscj score[30];
float scototal[6] = { 0 };
float scoave[6];
int stuc, scoc;
int x = 1;
int f = 0;
void Menu()
{
	printf("Please enter number from 1-13:");
	printf("\n");
	printf("1.Input record\n");
	printf("2.Calculate total and average scores of every course\n");
	printf("3.Calculate total and average scores of every student\n");
	printf("4.Sort in descending order by total score of every student\n");
	printf("5.Sort in ascending order by total score of every student\n");
	printf("6.Sort in ascending order by number\n");
	printf("7.Sort in dictionary order by name\n");
	printf("8.Search by number\n");
	printf("9.Search by name\n");
	printf("10.Analysis for every course\n");
	printf("11.List record\n");
	printf("12.Write to a file\n");
	printf("13.Read from a file\n");
	printf("0.Exit\n");
	printf("Please input record first then enter your choice\n");
}
void Input_record()
{
	printf("Please input students count and scores count\n");
	scanf("%d %d", &stuc, &scoc);
	printf("Please input student name number and score\n");
	for (i = 0; i<stuc; i++)
	{
		scanf("%s", score[i].name);
		scanf("%d", &score[i].number);
		for (j = 0; j<scoc; j++)
		{
			scanf("%d", &score[i].sco[j]);
		}

	}
	f = 1;
}
void To_Ave_Course()
{
		for (i = 0; i < scoc; i++)
		{
			for (j = 0; j < stuc; j++)
			{
				scototal[i] = scototal[i] + score[j].sco[i];
			}

		}
		for (i = 0; i < scoc; i++)
		{
			(float)scoave[i] = scototal[i] / stuc;
		}
		for (i = 0; i < scoc; i++)
		{
			printf("�γ�%d���ܷ���%d\n", i + 1, scototal[i]);
			printf("�γ�%d��ƽ������%.2f\n", i + 1, scoave[i]);
		}
		printf("\n");
}
void To_Ave_student()
{
	for (i = 0; i<stuc; i++)
	{
		score[i].sum = 0;

		for (j = 0; j<scoc; j++)
		{
			score[i].sum = score[i].sum + score[i].sco[j];
		}
	}
	for (i = 0; i<stuc; i++)
	{
		score[i].ave = score[i].sum / scoc;
	}
	for (i = 0; i<stuc; i++)
	{
		printf("%s���ܷ���%d\n", score[i].name, score[i].sum);
		printf("%s��ƽ������%.2f\n", score[i].name, score[i].ave);
	}
	printf("\n");
}
void Order_by_total_score()
{
	for (i = 0; i<stuc; i++)
	{

		score[i].rank = 1;
	}
	for (i = 0; i<stuc; i++)
	{
		for (j = 0; j<stuc; j++)
		if (score[i].sum<score[j].sum)
		{
			score[i].rank++;
		}

	}
	printf("ÿ��ѧ���Ӹߵ������α�Ϊ\n");
	for (i = 0; i<stuc; i++)
	{
		for (j = 0; j<stuc; j++)
		{

			if (score[j].rank == x)
			{
				printf("���� %s  ", score[j].name);
				printf("ѧ�� %d  ", score[j].number);
				for (l = 0; l<scoc; l++)
				{
					printf("�γ�%d   %d ", l + 1, score[j].sco[l]);
				}
				printf("\n");
				x++;
			}
		}

	}
	printf("\n");
}
void Ascending_Order_by_total_score()
{
	printf("ÿ��ѧ���ӵ͵������α�Ϊ\n");
	int y = stuc;
	for (i = 0; i<stuc; i++)
	{
		for (j = 0; j<stuc; j++)
		{
			if (score[j].rank == y)
			{
				printf("���� %s  ", score[j].name);
				printf("ѧ�� %d  ", score[j].number);
				for (l = 0; l<scoc; l++)
				{
					printf("�γ�%d  %d  ", i + 1, score[j].sco[l]);
				}
				printf("\n");
				y--;
			}
		}

	}
	printf("\n");
}
void  Ascending_Order_by_number()
{
	struct xscj a[30], c;
	for (i = 0; i<stuc; i++)
	{
		a[i] = score[i];
	}
	for (i = 0; i<stuc; i++)
	{
		for (j = i + 1; j<stuc; j++)
		{
			if (a[i].number>a[j].number)
			{
				c = a[i];
				a[i] = a[j];
				a[j] = c;
			}
		}
	}
	printf("��ѧ����С����ɼ���\n");
	for (i = 0; i<stuc; i++)
	{
		printf("ѧ�� %d  ", a[i].number);
		printf("���� %s  ", a[i].name);
		for (j = 0; j<scoc; j++)
		{
			printf("�γ�%d  %d  ", i + 1, a[i].sco[j]);
		}
		printf("\n");
	}
	printf("\n");
}
void Sort_in_dictionary()
{
	struct xscj b[30], d;
	for (i = 0; i<stuc; i++)
	{
		b[i] = score[i];
	}
	for (i = 0; i<stuc; i++)
	{
		for (j = i + 1; j<stuc; j++)
		{
			if (strcmp(b[i].name, b[j].name)>0)
			{
				d = b[i];
				b[i] = b[j];
				b[j] = d;
			}
		}
	}
	printf("�������ֵ�˳��ɼ���\n");
	for (i = 0; i<stuc; i++)
	{
		printf("ѧ�� %d  ", b[i].number);
		printf("���� %s  ", b[i].name);
		for (j = 0; j<scoc; j++)
		{
			printf("�γ�%d  %d  ", i + 1, b[i].sco[j]);
		}
		printf("\n");
	}
}
void Search_by_number()
{
	int y = 0;
	printf("������ѧ��ѧ��\n");
	int num;
	scanf("%d", &num);
	for (i = 0; i<stuc; i++)
	{
		if (score[i].number == num)
		{

			printf("ѧ��  %d  ", score[i].number);
			printf("����  %s  ", score[i].name);
			for (j = 0; j<scoc; j++)
			{
				printf("%d  ", score[i].sco[j]);
			}
			y = 1;


		}

	}
	if (y == 0)
	{
		printf("���޴���\n");
	}
	printf("\n");
}
void Search_by_name()
{
	int p = 0;
	printf("������ѧ������\n");
	char nam[10];
	scanf("%s", nam);
	for (i = 0; i<stuc; i++)
	{
		if (strcmp(score[i].name, nam) == 0)
		{
			printf("ѧ��  %d  ", score[i].number);
			printf("����  %s  ", score[i].name);
			for (j = 0; j<scoc; j++)
			{
				printf("�γ�%d %d  ", i + 1, score[i].sco[j]);
			}
			p = 1;
		}

	}
	if (p == 0)
	{
		printf("���޴���\n");
	}
	printf("\n");
}
void Analysis_for_every_course()
{
	int a1[6] = { 0 }, a2[6] = { 0 }, a3[6] = { 0 }, a4[6] = { 0 }, a5[6] = { 0 };
	printf("�ɼ�����\n");

	for (i = 0; i<scoc; i++)
	{
		for (j = 0; j<stuc; j++)
		{
			if (score[j].sco[i] >= 90)
			{
				a1[i]++;
			}
			else if (score[j].sco[i] >= 80)
			{
				a2[i]++;
			}
			else if (score[j].sco[i] >= 70)
			{
				a3[i]++;
			}
			else if (score[j].sco[i] >= 60)
			{
				a4[i]++;
			}
			else
			{
				a5[i]++;
			}
		}

	}
	for (i = 0; i<scoc; i++)
	{
		printf("�γ�%d\n", i + 1);
		printf("��������:%d ���������ٷֱ�%.1f%%\n", a1[i],
			a1[i] * 1.0 / stuc * 100);
		printf("��������:%d ���������ٷֱ�%.1f%%\n", a2[i],
			a2[i] * 1.0 / stuc * 100);
		printf("�е�����:%d �е������ٷֱ�%.1f%%\n", a3[i],
			a3[i] * 1.0 / stuc * 100);
		printf("��������:%d ���������ٷֱ�%.1f%%\n", a4[i],
			a4[i] * 1.0 / stuc * 100);
		printf("����������:%d �����������ٷֱ�%.1f%%\n", a5[i],
			a5[i] * 1.0 / stuc * 100);

	}
}
void List_record()
{
	for (i = 0; i<stuc; i++)
	{
		printf("ѧ��  %d  ", score[i].number);
		printf("����  %s  ", score[i].name);
		for (j = 0; j<scoc; j++)
		{
			printf("�γ�%d %d  ", j + 1, score[i].sco[j]);
		}
		printf("�ܷ�%d  ", score[i].sum);
		printf("����%.2f  ", score[i].ave);
		printf("\n");
	}
}
void Write_To_A_file()
{
	struct xscj c[30], g;
	FILE *fp;
	for (i = 0; i<stuc; i++)
		c[i] = score[i];
	for (i = 0; i<stuc; i++)
	{
		for (j = i + 1; j<stuc; j++)
		{
			if (c[i].number>c[j].number)
			{
				g = c[i];
				c[i] = c[j];
				c[j] = g;
			}
		}
	}
	if ((fp = fopen("E://score.txt", "w")) == NULL)
	{
		printf("Failure to open score.txt!\n");
	}
	for (i = 0; i<stuc; i++)
	{
		fprintf(fp, "����:%s\tѧ��:%d\t�ܷ�:%d\t\n���Ƴɼ�\n", c[i].name, c[i].number, c[i].sum);

		for (j = 0; j<scoc; j++)
		{
			fprintf(fp, "%d\t", c[i].sco[j]);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	printf("�ѽ�����д���ļ�");
}
void Read_From_a_file()
{
	FILE *fp;
	if ((fp = fopen("E://score.txt", "r")) == NULL)
	{
		printf("Failure to open score.txt!\n");
	}
	char name1[30];
	long num1;
	double  sum1;
	double  s1[20];
	int ttt = stuc;
	while (ttt--)
	{
		fscanf(fp, "����:%s\tѧ��:%ld\t�ܷ�:%lf\t\n���Ƴɼ�:\n", name1, &num1, &sum1);
		for (j = 0; j<scoc; j++)
		{
			fscanf(fp, "%lf\t", &s1[j]);
		}
		printf("����:%s\tѧ��:%ld\t�ܷ�:%.1f\t\n���Ƴɼ�\n", name1, num1, sum1);
		for (j = 0; j<scoc; j++)
		{
			printf("%.1f\t", s1[j]);
		}
		printf("\n");
	}
	fclose(fp);
}
int Judge()
{
	if (f == 0)
	{
		printf("��������ѧ���ɼ�\n");
		return 0;
	}
	return 1;
}