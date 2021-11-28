#include <stdio.h>
int main()
{
    char str[4];
    printf("明天出去玩吗？\n");
    while (scanf("%s", str) != 1)
        ;
    //也可直接写scanf("%s",str);
    //如果yes
    if (str[0] == 'Y')
    {
        //小A继续询问
        printf("下午2点？\n");
        while (scanf("%s", str) != 1)
            ;
        //答应了
        if (str[0] == 'Y')
        {
            printf("OK!\n");
        }
        else if (str[0] == 'N')
        {
            printf("那就下午3点！\n");
        }
    }
    else if (str[0] == 'N')
    {
        printf("那么改天再约。\n");
    }
}