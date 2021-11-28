#include <iostream>
#include <cstdlib>
#define Binary_Max 16 //最大进制限制
#define Binary_Min 2  //最小进制限制
using namespace std;
const char *str = "0123456789ABCDEF";
string Binary_Convert(int, int);
int main()
{
    int num, Binary;
    while (1)
    {
        cout << "请输入数值:\n";
        cin >> num;
        cout << "请输入转换的进制:\n";
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
        return "转换进制不在范围内";
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