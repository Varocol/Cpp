#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<time.h>
//����������
int main()
{
    initgraph(640,640);
    bool flag;
    //�û��ߵ���ʽ
    /*
    for(int i=0;i<640;i+=80)
    {
        flag=i/80%2?BLACK:WHITE;
        unsigned long color;
        for(int j=1;j<=640;j++)
        {
           color=flag?WHITE:BLACK;
           flag=j%80?flag:!flag;
           setlinecolor(color);
           //line(j,i,j,i+80);//���Ż���
           line((j-1)/80*80,(j-1)%80+1+i,(j-1)/80*80+80,(j-1)%80+1+i);//���Ż���
        }
    }
    */
    //�û����ε���ʽ
    for(int i=0;i<64;i++)
    {
        unsigned long color=i%8?i/8%2?(i-i/8*8)%2?WHITE:BLACK:(i-i/8*8)%2?BLACK:WHITE:i/8%2?BLACK:WHITE;
        setfillcolor(color);
        solidrectangle(i%8*80,i/8*80,i%8*80+80,i/8*80+80);
    }
    getch();
    closegraph();
}