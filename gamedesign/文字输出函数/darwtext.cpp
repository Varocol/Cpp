#include<graphics.h>
#include<conio.h>
/*darwtext�����������
����ԭ�ͣ�
int drawtext(
	LPCTSTR str,//�ַ����汾
	RECT* pRect,
	UINT uFormat
);
int drawtext(
	TCHAR c,//�ַ��汾
	RECT* pRect,
	UINT uFormat
);
uformat
DT_BOTTOM        ��������λ�õ����εײ��������� DT_SINGLELINE һ��ʹ��ʱ��Ч��

DT_CALCRECT	     �����εĿ�ߡ�����ж������֣�drawtext ʹ�� pRect ָ���Ŀ�ȣ�������չ���εĵײ�������ÿһ�����֡�
                 ���ֻ��һ�����֣�drawtext �޸� pRect ���ұ����������һ�����֡��������������drawtext �����ظ�ʽ��������ָ߶ȣ����Ҳ�������֡�

DT_CENTER        ����ˮƽ���С�

DT_EDITCONTROL   �Ե��б༭�ķ�ʽ���ƿɼ��ı��������˵���������ַ���ƽ�����Ϊ�������ݣ�ͬʱ�������ʽӦ���ڱ༭���ƣ��������ַ�ʽ����ʾ�ɼ����ֵ����һ�С�

DT_END_ELLIPSIS  �����ı���ʾ������ַ�����ĩ�ַ����ھ����ڣ����ᱻ�ضϲ���ʡ�Ժű�ʶ�� �����һ�����ʶ�����һ���ַ�����ĩβ�����˾��η�Χ�������ᱻ�ضϡ�
                 �ַ������ᱻ�޸ģ�����ָ���� DT_MODIFYSTRING ��־��
DT_EXPANDTABS    չ�� TAB ���š� Ĭ��ÿ�� TAB ռ8���ַ�λ�á�
                 ע�⣬DT_WORD_ELLIPSIS��DT_PATH_ELLIPSIS �� DT_END_ELLIPSIS ���ܺ� DT_EXPANDTABS һ���á�

DT_EXTERNALLEADING ���и������������м�ࡣͨ������£��м�಻�����������ĵ��и��

DT_HIDEPREFIX    ���������е�ǰ׺�ַ�(&)������ǰ׺�ַ�������ַ���������»��ߡ�����ǰ׺�ַ��Իᱻ�������磺
                 �����ַ���:		"A&bc&&d"
                 ͨ�����:		"Abc&d"
                 DTDT_HIDEPREFIX:	"Abc&d"

DT_INTERNAL      ʹ��ϵͳ����������ֵĿ�ߵ����ԡ�   
DT_LEFT	         ��������롣
DT_MODIFYSTRING  �޸�ָ���ַ���Ϊ��ʾ�������ġ������� DT_END_ELLIPSIS �� DT_PATH_ELLIPSIS ��־ͬʱʹ��ʱ��Ч��
DT_NOCLIP        ʹ������ֲ��� pRect �ü����ơ�ʹ�� DT_NOCLIP ��ʹ drawtext ִ���Կ�һЩ��
DT_NOFULLWIDTHCHARBREAK	��ֹ���з����뵽 DBCS (double-wide character string�������ַ���)�����й����൱�� SBCS �ַ����������� DT_WORDBREAK һ��ʹ��ʱ��Ч��
                        ���磬���־��ǿ��ַ������øñ�־�������ĺ��ֻ���Ӣ�ĵ���һ���������з��жϡ�
DT_NOPREFIX      �ر�ǰ׺�ַ��Ĵ���ͨ����DrawText ����ǰ׺ת��� & Ϊ�����ַ����»��ߣ����� && Ϊ��ʾ���� &��ָ�� DT_NOPREFIX�����ִ����رա����磺
                 �����ַ���:	"A&bc&&d"
                 ͨ�����:	"Abc&d"
                 DT_NOPREFIX:	"A&bc&&d"

DT_PATH_ELLIPSIS ������ʾ�����֣���ʡ�Ժ��滻�ַ����м���ַ��Ա������ھ����ڡ�����ַ���������б��(\)��DT_PATH_ELLIPSIS �����ܵı������һ����б�ܺ�������֡�
                 �ַ������ᱻ�޸ģ�����ָ����DT_MODIFYSTRING��־��

DT_PREFIXONLY    ������(&)ǰ׺�ַ���λ���»���һ���»��ߡ��������ַ����е��κ������ַ������磺
                 �����ַ���:	"A&bc&&d"
                 ͨ�����:	"Abc&d"
                 DT_PREFIXONLY:	" _   "
DT_RIGHT         �����Ҷ��롣

DT_RTLREADING    ���ô���������Ķ�˳�򣨵�������ϣ�����Ļ�������ʱ����Ĭ�ϵ��Ķ�˳���Ǵ������ҡ�

DT_SINGLELINE    ʹ������ʾ��һ�С��س��ͻ��з�����Ч��

DT_TABSTOP       ���� TAB �Ʊ�λ��uFormat �� 15�C8 λָ�� TAB ���ַ���ȡ�Ĭ�� TAB ��ʾ 8 ���ַ���ȡ�
                 ע�⣬DT_CALCRECT��DT_EXTERNALLEADING��DT_INTERNAL��DT_NOCLIP �� DT_NOPREFIX ���ܺ� DT_TABSTOP һ���á�
DT_TOP           ���ֶ������롣

DT_VCENTER       ���ִ�ֱ���С������� DT_SINGLELINE һ��ʹ��ʱ��Ч��

DT_WORDBREAK     �Զ����С������ֳ����ұ߽�ʱ���Զ�����(���𿪵���)���س���ͬ�����Ի��С�

DT_WORD_ELLIPSIS ��ȥ�޷����ɵ����֣�����ĩβ����ʡ�Ժš�
                

*/
int main()
{
    initgraph(640,480);
    RECT r={0,0,640,480};
    drawtext(_T("HELLO WORLD"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);//��ֱˮƽ������һ�����
    _getch();
    cleardevice();
    drawtext(_T("HELLO WORLD"),&r,DT_CENTER);//ˮƽ����Ĭ��������
    _getch();
    cleardevice();
    drawtext(_T("HELLO WORLD"),&r,DT_VCENTER|DT_SINGLELINE);//��ֱһ��Ҫ����DT_SINGLELINE
    _getch();
    cleardevice();
    drawtext(_T("HELLO WORLD"),&r,DT_TOP);
    _getch();
    cleardevice();
    drawtext(_T("HELLO WORLD"),&r,DT_BOTTOM|DT_SINGLELINE);//�ײ�ҲҪ����DT_SINGLELINE
    _getch();
    cleardevice();
    closegraph();
}