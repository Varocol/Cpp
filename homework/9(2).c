#include<stdio.h>
#include<stdlib.h>
#define NUM 4
struct  datas
{
   char num[20],name[20];
   int grade[4];
}a[NUM];

int main()
{
   for(int i=0;i<NUM;i++)
       {
           printf("������%d��ѧ����ѧ��,����,���ųɼ�:",i+1);
           scanf("%s%s%d%d%d",a[i].num,a[i].name,&a[i].grade[0],&a[i].grade[1],&a[i].grade[2]);
           a[i].grade[3]=a[i].grade[0]+a[i].grade[1]+a[i].grade[2];
       }
   for(int i=0;i<NUM;i++)
   {
       printf("��%d��ѧ����ѧ��,����,���ųɼ����ܷ�:%s %s %d %d %d %d\n",i+1,a[i].num,a[i].name,a[i].grade[0],a[i].grade[1],a[i].grade[2],a[i].grade[3]);
   }
   freopen("hw2.txt","w",stdout);
   for(int i=0;i<NUM;i++)
   {
       printf("%s %s %d %d %d %d ",a[i].num,a[i].name,a[i].grade[0],a[i].grade[1],a[i].grade[2],a[i].grade[3]);
   }
   fclose(stdout);
   freopen("CON","r",stdin);
   system("pause");
}