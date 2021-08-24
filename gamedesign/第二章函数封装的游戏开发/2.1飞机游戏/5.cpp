#include<stdio.h>
#include<stdlib.h>
#include<conio.h>//����kbhit()��getch()����

int bullet_x,bullet_y;//�ӵ�����
int position_x,position_y;//�ɻ�����
int enemy_x,enemy_y;//�л�����
int high,width;//����ߴ�
int score;//�÷�

void startup()
{
    high=20;
    width=30;
    position_x=high/2;
    position_y=width/2;
    bullet_x=position_x;
    bullet_y=-2;
    enemy_x=position_x;
    enemy_y=-1;//��ֹ����Ļ�����
    score=0;
}

void show()
{
    system("cls");
    for(int i=0;i<high;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(i==position_y&&j==position_x)
            printf("*");
            else if(i==bullet_y&&j==bullet_x)
            printf("|");
            else if(i==enemy_y&&j==enemy_x)
            printf("@");
            else 
            printf(" ");
        }
        printf("\n");
    }
    printf("�÷֣�%d\n",score);
}

void updateWithoutInput()
{
    if(bullet_y>=0)
    bullet_y--;
    static int speed=0;
    if(enemy_y==bullet_y&&enemy_x==bullet_x)
    {
        score++;
        enemy_y=-1;
        enemy_x=rand()%width;
        bullet_y=-2;
    }
    if(enemy_x>high)
    {
        enemy_y=-1;
        enemy_x=rand()%width;
    }
    if(speed<10)
       speed++;
    else 
    {
       enemy_y++;
       speed=0; 
    }
}
void updateWithInput()
{
        char input;
        if(kbhit())
        {
        input=getch();//�ȴ�����
        switch(input)
        {
            case 'a':
            case 'A':position_x--;
            break;
            case 's':
            case 'S':position_y++;
            break;
            case 'd':
            case 'D':position_x++;
            break;
            case 'w':
            case 'W':position_y--;
            break;
            case ' ':{bullet_y=position_y-1;bullet_x=position_x;}
            break;
        }
        }
}

int main()
{
    startup();
    while(1)
    {        
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}