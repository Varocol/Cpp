#include<stdio.h>
#include<stdlib.h>
#include<conio.h>//����kbhit()��getch()����

int bullet_x,bullet_y;//�ӵ�����
int position_x,position_y;//�ɻ�����
int enemy_x,enemy_y;//�л�����
int high,width;

void startup()
{
    high=20;
    width=30;
    position_x=high/2;
    position_y=width/2;
    bullet_x=position_x;
    bullet_y=0;
    enemy_x=position_x;
    enemy_y=0;
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
}

void updateWithoutInput()
{

}

void updateWithInput()
{
        char input;
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

int main()
{
    startup();
    show();
    while(1)
    {        
        updateWithoutInput();
        if(kbhit)updateWithInput();
        while(bullet_y>=0)
        {bullet_y--;show();}
        bullet_y=0;
    }
    return 0;
}