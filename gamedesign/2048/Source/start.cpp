#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include"windowtitle.cpp"
string str;
void startui()
{   
   mciSendString(_T("open C:\\Users\\Varocol\\Desktop\\c\\gamedesign\\2048\\music\\1.mp3 alias bkmusic"),NULL,0,NULL);
   mciSendString(_T("play bkmusic repeat"),NULL,0,NULL);
   //��ʼ������
   initgraph(640,480);
   setbkcolor(GREEN);
   setbkmode(TRANSPARENT);
   cleardevice();
   windowtitle(L"��ʼ����");
   //��ʼ���ṹ��
   LOGFONT f;//�洢��������
   RECT r{0,0,640,480};
   settextstyle(0,0,_T("Consolas"));
   gettextstyle(&f);
   f.lfWeight=0;
   f.lfWidth=0;
   f.lfQuality=ANTIALIASED_QUALITY;
   
   //�������2
   settextcolor(BLACK);
   f.lfHeight=200;
   _tcscpy(f.lfFaceName,_T("����"));
   settextstyle(&f);
   drawtext(_T("2"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);
   cleardevice();
   //�������20
   settextcolor(WHITE);
   f.lfHeight=200;
   _tcscpy(f.lfFaceName,_T("����"));
   settextstyle(&f);
   drawtext(_T("20"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);
   cleardevice();
   //�������204
   settextcolor(BLUE);
   f.lfHeight=200;
   _tcscpy(f.lfFaceName,_T("����"));
   settextstyle(&f);
   drawtext(_T("204"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);
   cleardevice();
   //�����Ӱ����
   settextcolor(BLACK);
   f.lfHeight=250;
   _tcscpy(f.lfFaceName,_T("Consolas"));
   settextstyle(&f);
   outtextxy(95,120,_T("2048"));
   //�������2048
   settextcolor(RED);
   drawtext(_T("2048"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);

   //���Power by Group 7510
   wchar_t s[23]=L"�yPowered by Group 7510"; 
   wchar_t current[24];
   current[22]='\0';
   current[23]='\0';
   settextcolor(BLACK);
   f.lfHeight=50;
   settextstyle(&f);
   for(int i=0;i<22;i++)
   {
      bool flag=true;
      for(int j=0;j<22;j++)
      {
          if(flag)
          {
              current[j]=s[j];
              if(s[j]==L'�y')
              {wchar_t temp;temp=s[j+1];s[j+1]=s[j];s[j]=temp;flag=false;}
          }
          else current[j]=L' ';
      }
      Wchar_tToString(str,current);//��wchar_t����ת����string
      drawtext((LPCTSTR)str.c_str(),&r,DT_CENTER|DT_BOTTOM|DT_SINGLELINE);
      Sleep(200);
      settextcolor(GREEN);
      drawtext((LPCTSTR)str.c_str(),&r,DT_CENTER|DT_BOTTOM|DT_SINGLELINE);
      settextcolor(BLACK);
   }
   while(!kbhit())
   {
       BeginBatchDraw();
       static bool flag=true;
       if(flag)
       {
           current[21]=' ';
           current[22]=' ';
           Wchar_tToString(str,current);
           outtextxy(60,430,(LPCTSTR)str.c_str());
           FlushBatchDraw();
           Sleep(500);
           flag=!flag;
       }
       else
       {
           
           current[21]=L'�y';
           current[22]='\0';
           Wchar_tToString(str,current);
           outtextxy(60,430,(LPCTSTR)str.c_str());
           FlushBatchDraw();
           Sleep(500);
           settextcolor(GREEN);
           outtextxy(60,430,(LPCTSTR)str.c_str());
           settextcolor(BLACK);
           flag=!flag;
       }
   }
   EndBatchDraw();//�����Ժ�һ��Ҫ�ǵùر�
   closegraph();
   fflush(stdin);
}