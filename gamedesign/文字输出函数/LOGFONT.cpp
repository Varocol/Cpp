/*
struct LOGFONT {
	LONG lfHeight;
	LONG lfWidth 
	LONG lfEscapement;
	LONG lfOrientation;
	LONG lfWeight;
	BYTE lfItalic;
	BYTE lfUnderline;
	BYTE lfStrikeOut;
	BYTE lfCharSet;
	BYTE lfOutPrecision;
	BYTE lfClipPrecision;
	BYTE lfQuality;
	BYTE lfPitchAndFamily;
	TCHAR lfFaceName[LF_FACESIZE];
};
lfHeight 
ָ���߶ȣ��߼���λ����
lfWidth
ָ���ַ���ƽ����ȣ��߼���λ�������Ϊ 0�����������Ӧ��
lfEscapement
�ַ�������д�Ƕȣ���λ 0.1 �ȣ�Ĭ��Ϊ 0��
lfOrientation
ÿ���ַ�����д�Ƕȣ���λ 0.1 �ȣ�Ĭ��Ϊ 0��
lfWeight
�ַ��ıʻ���ϸ����Χ 0~1000��0 ��ʾĬ�ϴ�ϸ��ʹ�����ֻ��±��ж���ĺ���ɡ�
lfItalic
ָ�������Ƿ���б�塣
lfUnderline
ָ�������Ƿ����»��ߡ�
lfStrikeOut
ָ�������Ƿ���ɾ����
lfCharSet
ָ���ַ���������ʹ������Ԥ�����ֵ��
lfOutPrecision
ָ�����ֵ�������ȡ�������ȶ�������������������߶ȡ���ȡ��ַ������оࡢ��������������ƥ�����ﵽ��ƥ��̶ȡ�����������ֵ��
lfClipPrecision
ָ�����ֵļ������ȡ��������ȶ�����μ����ַ���һ����λ�ڼ�������֮����ַ�������������ֵ��
lfClipPrecision
ָ�����ֵļ������ȡ��������ȶ�����μ����ַ���һ����λ�ڼ�������֮����ַ�������������ֵ��
lfQuality
ָ�����ֵ���������������������ͼ���豸���� (GDI) ���볢�Խ��߼�����������ʵ������������������Խ���ƥ�����ϸ�̶ȡ�����������ֵ��
lfPitchAndFamily
ָ���Գ��淽ʽ�������������ϵ�С�����ϵ���������µ�������ۡ�����ϵ�����������辫ȷ���岻����ʱָ�����塣1~2 λָ�������࣬����������ֵ��
lfFaceName
�������ƣ����Ʋ��ó��� 31 ���ַ�������ǿ��ַ�����ϵͳ��ʹ�õ�һ�������������Ե����塣

#include<graphics.h>
#include<conio.h>
int main()
{
   initgraph(640,480);
   LOGFONT f;   
   setbkcolor(GREEN);
   cleardevice();
   settextstyle(16,0,_T("Consolas"));
   settextcolor(RED);
   gettextstyle(&f);
   
   f.lfHeight=200;
   f.lfWeight=1000;
   f.lfQuality=ANTIALIASED_QUALITY;
   settextstyle(&f);

   RECT r={0,0,640,480};
   drawtext(_T("2048"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   _getch();
   
   
}
*/
#include<conio.h>
#include<graphics.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   //��ʼ������
   initgraph(640,480);
   setbkcolor(GREEN);
   cleardevice();
   //��ʼ���ṹ��
   LOGFONT f;
   RECT r{0,0,640,480};
   settextstyle(0,0,_T("Consolas"));
   gettextstyle(&f);
   f.lfWeight=1000;
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
   //�������2048RED
   settextcolor(RED);
   f.lfHeight=200;
   _tcscpy(f.lfFaceName,_T("Consolas"));
   settextstyle(&f);
   drawtext(_T("2048"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
   Sleep(1000);
   _getch();
   closegraph();
}