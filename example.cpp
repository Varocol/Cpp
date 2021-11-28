#include<stdio.h>
int sum_1(int,int);
int sum_2(int,int);
//int (*p)(int,int);
int main()
{
   int (*p)(int,int);
   p = sum_1;
   printf("%d\n",p(1,2));
   p = sum_2;
   printf("%d\n",p(1,2));
}
int sum_1(int a,int b)
{
    return a+b;
}
int sum_2(int a,int b)
{
    return 2*a+b;
}