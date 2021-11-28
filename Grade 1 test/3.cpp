#include<stdio.h>
int main()
{
    int n,count=0;
    char str[101];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",str);
        for(int i=0;str[i];i++)
        {
            if(str[i]=='A')
            {
                count++;
            }
        }
        printf("%d\n",count);
        count = 0;
    }
}