#include <iostream>
#include <cstdlib>
#define Binary_Max 16 //����������
#define Binary_Min 2  //��С��������
using namespace std;
const char *str = "0123456789ABCDEF";
string Binary_Convert(int, int);
int main()
{
    int num, Binary;
    while (1)
    {
        cout << "��������ֵ:\n";
        cin >> num;
        cout << "������ת���Ľ���:\n";
        cin >> Binary;
        cout << Binary_Convert(num, Binary) << endl
             << endl;
    }
    system("pause");
}
string Binary_Convert(int num, int Binary)
{
    if (Binary < Binary_Min || Binary > Binary_Max)
    {
        return "ת�����Ʋ��ڷ�Χ��";
    }
    if (num == 0)
    {
        return "0";
    }
    string result;
    while (num)
    {
        result = str[num % Binary] + result;
        num /= Binary;
    }
    return result;
}