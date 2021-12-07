#include <iostream>
using namespace std;
typedef enum
{
    up = 1,
    down = -1
} direction;
void Shellsort(int[], int, direction);
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
    Shellsort(arr, num, up);
}
void Shellsort(int r[], int num, direction dir)
{
    for (int d = num / 2; d; d /= 2)
    {
        for (int i = d + 1; i <= num; i++)
        {
            r[0] = r[i];
            int j;
            for (j = i - d; r[0] * dir < r[j] * dir && j > 0; j -= d)
            {
                r[j + d] = r[j];
            }
            r[j + d] = r[0];
        }
        if (d >= num / 8)
        {
            cout << "D = " << d << ":";
            for (int j = 1; j <= num; j++)
            {
                cout << "\t" << r[j];
            }
            cout << endl;
        }
    }
}