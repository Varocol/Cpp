#include <stdio.h>
//第一种方法
// int main()
// {
//     int l, r;
//     int count = 0;
//     scanf("%d %d", &l, &r);
//     for (int i = l; i <= r; i++)
//     {
//         //转换
//         int temp = i,shuixian = 0;
//         while(temp)
//         {
//             int num = temp%10,convert = 0;
//             temp/=10;
//             while(num)
//             {
//                convert = convert *2 + num%2;
//                num/=2;
//             }
//             shuixian += convert*convert*convert;                                             
//         }
//         if(i == shuixian)
//         {
//             count ++;
//         }
//     }
//     printf("%d",count);
// }
//第二种方法
int main()
{
    int num[10]={0,1,1,3,1,5,4,7,1,9};
    int l, r;
    int count = 0;
    scanf("%d %d", &l, &r);
    for (int i = l; i <= r; i++)
    {
        //转换
        int temp = i,shuixian = 0;
        while(temp)
        {
            shuixian += num[temp%10]*num[temp%10]*num[temp%10];
            temp/=10;
        }
        if(i == shuixian)
        {
            count ++;
        }
    }
    printf("%d",count);
}