#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    struct xscj
    {
        int number;
        char name[10];
        int sco[6];
        int rank;
        float ave;
        int sum;
    };
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
    int choice;
    int i,j,l;
    struct xscj score[30];
    int scototal[6]={0};
    float scoave[6];
    int stuc,scoc;
    int x=1;
    int f=0;

    while (1)
    {
        scanf("%d",&choice);
        switch (choice)
        {
        case   1:
            {
                printf("Please input students count and scores count\n");

                scanf("%d %d",&stuc,&scoc);
                printf("Please input student name number and score\n");
                for(i=0;i<stuc;i++)
                {
                    scanf("%s",score[i].name);
                    scanf("%d",&score[i].number);
                    for(j=0;j<scoc;j++)
                    {
                        scanf("%d",&score[i].sco[j]);
                    }

                }
                f=1;
                break;

            }
        case 2:
            {
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
                else
                {
                    for(i=0;i<scoc;i++)
                {
                    for(j=0;j<stuc;j++)
                    {
                        scototal[i]=scototal[i]+score[j].sco[i];
                    }

                }
                for(i=0;i<scoc;i++)
                {
                    scoave[i]=scototal[i]/stuc;
                }
                for(i=0;i<scoc;i++)
                {
                    printf("课程%d的总分是%d\n",i+1,scototal[i]);
                    printf("课程%d的平均分是%.2f\n",i+1,scoave[i]);
                }
                printf("\n");
                break;

                }



            }
        case 3:
            {
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
                else
                {
                    for(i=0;i<stuc;i++)
                {
                    score[i].sum=0;

                    for(j=0;j<scoc;j++)
                    {
                        score[i].sum=score[i].sum+score[i].sco[j];
                    }
                }
                for(i=0;i<stuc;i++)
                {
                    score[i].ave=score[i].sum/scoc;
                }
                for(i=0;i<stuc;i++)
                {
                    printf("%s的总分是%d\n",score[i].name,score[i].sum);
                    printf("%s的平均分是%.2f\n",score[i].name,score[i].ave);
                }
                printf("\n");
                break;
                }

            }
        case 4:
            {
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
                else
                {
                    for(i=0;i<stuc;i++)
                {

                    score[i].rank=1;
                }
               for(i=0;i<stuc;i++)
               {
                   for(j=0;j<stuc;j++)
                   if(score[i].sum<score[j].sum)
                   {
                       score[i].rank++;
                   }

               }
               printf("每个学生从高到低名次表为\n");
               for(i=0;i<stuc;i++)
               {
                  for(j=0;j<stuc;j++)
                  {

                      if(score[j].rank==x)
                      {
                        printf("姓名 %s  ",score[j].name);
                        printf("学号 %d  ",score[j].number);
                        for(l=0;l<scoc;l++)
                        {
                            printf("课程%d   %d ",l+1,score[j].sco[l]);
                        }
                        printf("\n");
                         x++;
                      }
                  }

               }
               printf("\n");
               break;
                }
            }
        case 5:
            {
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
                else
                {
                    printf("每个学生从低到高名次表为\n");
                int y=stuc;
                for(i=0;i<stuc;i++)
               {
                  for(j=0;j<stuc;j++)
                  {
                      if(score[j].rank==y)
                      {
                        printf("姓名 %s  ",score[j].name);
                        printf("学号 %d  ",score[j].number);
                        for(l=0;l<scoc;l++)
                        {
                            printf("课程%d  %d  ",i+1,score[j].sco[l]);
                        }
                        printf("\n");
                        y--;
                      }
                  }

               }
               printf("\n");
               break;
                }

            }
        case 6:
            {
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
                else
                {
                    struct xscj a[30],c;
                for(i=0;i<stuc;i++)
                {
                    a[i]=score[i];
                }
                for(i=0;i<stuc;i++)
                {
                    for(j=i+1;j<stuc;j++)
                    {
                        if(a[i].number>a[j].number)
                        {
                            c=a[i];
                            a[i]=a[j];
                            a[j]=c;
                        }
                    }
                }
                printf("按学号由小到大成绩表\n");
                for(i=0;i<stuc;i++)
                {
                    printf("学号 %d  ",a[i].number);
                    printf("姓名 %s  ",a[i].name);
                    for(j=0;j<scoc;j++)
                    {
                        printf("课程%d  %d  ",i+1,a[i].sco[j]);
                    }
                    printf("\n");
                }
                printf("\n");
                break;
                }
            }
        case 7:
        {
            if(f==0)
                {
                    printf("请先输入学生成绩");
                    break;
                }
            else
            {
                struct xscj b[30],d;
                for(i=0;i<stuc;i++)
                {
                    b[i]=score[i];
                }
                 for(i=0;i<stuc;i++)
                {
                    for(j=i+1;j<stuc;j++)
                    {
                        if(strcmp(b[i].name,b[j].name)>0)
                        {
                            d=b[i];
                            b[i]=b[j];
                            b[j]=d;
                        }
                    }
                }
                printf("按姓名字典顺序成绩表\n");
                for(i=0;i<stuc;i++)
                {
                    printf("学号 %d  ",b[i].number);
                    printf("姓名 %s  ",b[i].name);
                    for(j=0;j<scoc;j++)
                    {
                        printf("课程%d  %d  ",i+1,b[i].sco[j]);
                    }
                    printf("\n");
                }
                break;
            }
        }
        case 8:
            {
                int y;
             //   2=0;
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
                else
                {
                    printf("请输入学生学号\n");
                    int num;
                scanf("%d",&num);
                for(i=0;i<stuc;i++)
               {
                  if(score[i].number==num)
                  {

                    printf("学号  %d  ",score[i].number);
                    printf("姓名  %s  ",score[i].name);
                    for(j=0;j<scoc;j++)
                    {
                        printf("%d  ",score[i].sco[j]);
                    }
                    y=1;


                  }

               }
               if(y==0)
               {
                   printf("查无此人\n");
               }
               printf("\n");
               break;
                }

            }
        case 9:
            {
                int p=0;
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
               else
               {
                   printf("请输入学生姓名\n");
                    char nam[10];
                scanf("%s",nam);
                for(i=0;i<stuc;i++)
                {
                    if(strcmp(score[i].name,nam)==0)
                    {
                        printf("学号  %d  ",score[i].number);
                        printf("姓名  %s  ",score[i].name);
                        for(j=0;j<scoc;j++)
                      {
                        printf("课程%d %d  ",i+1,score[i].sco[j]);
                      }
                      p=1;
                    }

                }
                if(p==0)
                {
                    printf("查无此人\n");
                }
                printf("\n");
                break;
               }
            }
        case 10:
            {
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
                else
                {
                    int a1[6]={0},a2[6]={0},a3[6]={0},a4[6]={0},a5[6]={0};
                    printf("成绩分析\n");

                for(i=0;i<scoc;i++)
                {
                    for(j=0;j<stuc;j++)
                    {
                        if(score[j].sco[i]>=90)
                        {
                            a1[i]++;
                        }
                        else if(score[j].sco[i]>=80)
                        {
                            a2[i]++;
                        }
                        else if(score[j].sco[i]>=70)
                        {
                            a3[i]++;
                        }
                        else if(score[j].sco[i]>=60)
                        {
                            a4[i]++;
                        }
                        else
                        {
                            a5[i]++;
                        }
                    }

                }
                 for(i=0;i<scoc;i++)
                {
                    printf("课程%d\n",i+1);
                    printf("优秀人数:%d 优秀人数百分比%.1f%%\n",a1[i],
                           a1[i]*1.0/stuc*100);
                    printf("良好人数:%d 良好人数百分比%.1f%%\n",a2[i],
                           a2[i]*1.0/stuc*100);
                    printf("中等人数:%d 中等人数百分比%.1f%%\n",a3[i],
                           a3[i]*1.0/stuc*100);
                    printf("及格人数:%d 及格人数百分比%.1f%%\n",a4[i],
                           a4[i]*1.0/stuc*100);
                    printf("不及格人数:%d 不及格人数百分比%.1f%%\n",a5[i],
                           a5[i]*1.0/stuc*100);

                }
                break;

                }

            }
        case 11:
            {
                if(f==0)
                {
                    printf("请先输入学生成绩\n");
                    break;
                }
                else
                {
                    for(i=0;i<stuc;i++)
                {
                    printf("学号  %d  ",score[i].number);
                        printf("姓名  %s  ",score[i].name);
                        for(j=0;j<scoc;j++)
                      {
                        printf("课程%d %d  ",j+1,score[i].sco[j]);
                      }
                      printf("总分%d  ",score[i].sum);
                      printf("均分%.2f  ",score[i].ave);
                      printf("\n");
                }
                break;
                }

            }
        case 12:
            {
                struct xscj c[30],g;
                for(i=0;i<stuc;i++)
                    c[i]=score[i];
                for(i=0;i<stuc;i++)
                {
                    for(j=i+1;j<stuc;j++)
                    {
                        if(c[i].number>c[j].number)
                        {
                            g=c[i];
                            c[i]=c[j];
                            c[j]=g;
                        }
                    }
                }

                FILE *fp;
                if((fp=fopen("E://score.txt","w"))==NULL)
                {
                    printf("Failure to open score.txt!\n");

                }
                for(i=0;i<stuc;i++)
                {
                    fprintf(fp,"姓名:%s\t学号:%d\t总分:%d\t\n各科成绩\n",c[i].name,c[i].number,c[i].sum);

                    for(j=0;j<scoc;j++)
                    {
                        fprintf(fp,"%d\t",c[i].sco[j]);
                    }
                    fprintf(fp,"\n");
                }
                fclose(fp);
                printf("已将数据写入文件");
                break;
            }
        case 13:
            {
                FILE *fp;
                if((fp=fopen("E://score.txt","r"))==NULL)
                {
                    printf("Failure to open score.txt!\n");
                }
                char name1[30];
                long num1;
                double  sum1;
                double  s1[20];
                int ttt=stuc;
                while(ttt--)
                {
                    fscanf(fp,"姓名:%s\t学号:%ld\t总分:%lf\t\n各科成绩:\n",name1,&num1,&sum1);
                    for(j=0;j<scoc;j++)
                    {
                          fscanf(fp,"%lf\t",&s1[j]);
                    }
                    printf("姓名:%s\t学号:%ld\t总分:%.1f\t\n各科成绩\n",name1,num1,sum1);
                    for(j=0;j<scoc;j++)
                    {
                        printf("%.1f\t",s1[j]);
                    }
                        printf("\n");
                }
                fclose(fp);
                break;
            }
            case 0:
            {
                exit(0);
            }
          }

   }
    return 0;
}
