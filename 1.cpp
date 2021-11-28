#include <stdio.h>
void Print_Num_Float(int num)
{
    int temp = num < 0 ? -num : num;
    //如果num为0则count直接给1
    int count = num ? 0 : 1;
    while (temp)
    {
        count++;
        temp /= 10;
    }
    char *str = new char[count + 2];
    str[count + 1] = '\0';
    temp = num < 0 ? -num : num;
    while (temp)
    {
        str[count--] = temp % 10 + '0';
        temp /= 10;
    }
    if (num == 0)
        str[1] = '0';
    str[0] = num < 0 ? '-' : ' ';
    printf(str);
    delete[] str;
}

int main()
{
    int test;
    while (~scanf("%d", &test))
    {
        Print_Num_Float(test);
    }
}