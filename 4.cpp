#include<stdio.h>
int sum_arr_1(int arr[][3],int n); //等价于int (*arr)[3]
int sum_arr_2(int **arr,int n,int m); 
int main()
{
    int num[2][3] = {{1,2,3},{4,5,6}};
    //下面这种方法只是用读取，不适用传参
    //int *a = &(num[0][0]);
    //int **p = &a;
    int *a[2];
    a[0] = num[0];
    a[1] = num[1];
    printf("%d\n",sum_arr_1(num,2));
    printf("%d\n",sum_arr_2(a,2,3));
}
int sum_arr_1(int arr[][3],int n)
{
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum +=arr[i][j];
        }
    }
    return sum;
}
int sum_arr_2(int **arr,int n,int m)
{
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sum +=arr[i][j];
        }
    }
    return sum;
}