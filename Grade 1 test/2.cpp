#include <stdio.h>
int main()
{
    float num[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%f", &num[i]);
        // //插入排序
        // int j;
        // float x = num[i];
        // for (j = i - 1; j >= 0 && x < num[j]; j--)
        // {
        //     num[j + 1] = num[j];
        // }
        // num[j + 1] = x;
    }
    // //冒泡
    // for(int i=0;i<9;i++)
    // {
    //     for(int j=0;j<9-i;j++)
    //     {
    //         if(num[j]>num[j+1])
    //         {
    //             num[j] += num[j+1];
    //             num[j+1] = num[j] - num[j+1];
    //             num[j] -= num[j+1];
    //         }
    //     }
    // }
    //选择
    for(int i=0;i<9;i++)
    {
        int minj = i;
        for(int j=i+1;j<10;j++)
        {
            if(num[minj]>num[j])
            {
                minj = j;
            }
        }
        if(minj != i)
        {
            num[minj]+= num[i];
            num[i] = num[minj] - num[i];
            num[minj] = num[minj] - num[i];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if(i)printf(" ");
        printf("%f",num[i]);
    }
}