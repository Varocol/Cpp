#include<iostream>
#include<graphics.h>

using namespace std;


void Wchar_tToString(std::string& szDst, wchar_t*wchar)
{
wchar_t * wText = wchar;
DWORD dwNum = WideCharToMultiByte(CP_OEMCP,NULL,wText,-1,NULL,0,NULL,FALSE);//WideCharToMultiByte������
char *psText;  // psTextΪchar*����ʱ���飬��Ϊ��ֵ��std::string���м����
psText = new char[dwNum];
WideCharToMultiByte (CP_OEMCP,NULL,wText,-1,psText,dwNum,NULL,FALSE);//WideCharToMultiByte���ٴ�����
szDst = psText;// std::string��ֵ
delete []psText;// psText�����
}

void IntToString(string& s,int num)
{
    s="";
    if(!num)s="0";
    while(num)
    {
        s=char(num%10+'0')+s;
        num/=10;
    }
}