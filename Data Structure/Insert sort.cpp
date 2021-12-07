#include <iostream>
using namespace std;
typedef enum
{
    up = 1,
    down = -1
} direction;
void InsertSort(int[], int, direction);
int main()
{
    int num;
    cout << "请输入数组长度:" << endl;
    cin >> num;
    int arr[num + 1];
    for (int i = 1; i <= num; i++)
    {
        cin >> arr[i];
    }
    InsertSort(arr, num, up);
}
void InsertSort(int r[], int num, direction dir)
{
    for (int i = 2; i <= num; i++)
    {
        r[0] = r[i];
        int j;
        for (j = i - 1; dir * r[0] < dir * r[j]; j--)
        {
            r[j + 1] = r[j];
        }
        r[j + 1] = r[0];
        if (i - 1 < 7)
        {
            cout << "第" << i - 1 << "趟:";
            for (int k = 1; k <= num; k++)
            {
                cout << "\t";
                cout << r[k];
            }
            cout << endl;
        }
    }
}