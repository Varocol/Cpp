#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef enum
{
    up = 1,
    down = -1
} direction;
int num;
vector<vector<vector<int>>> result;
int Partition(int[], int, int, direction);
void QuickSort(int[], int, int, int, direction);
int main()
{
    cout << "请输入数组长度:" << endl;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    QuickSort(arr, 0, num - 1, 1, up);
    for (int i = 0; i < 2; i++)
    {
        cout << "第" << i + 1 << "趟:";
        for (int j : result[i].back())
        {
            cout << "\t" << j;
        }
        cout << endl;
    }
}
int Partition(int r[], int begin, int end, direction dir)
{
    int i = begin, j = end;
    bool flag = true;
    while (i < j)
    {
        if (dir * r[i] <= dir * r[j])
        {
            if (flag)
                j--;
            else
                i++;
        }
        else
        {
            swap(r[i], r[j]);
            flag = !flag;
        }
    }
    return i;
}
void QuickSort(int r[], int begin, int end, int level, direction dir)
{
    if (begin >= end)
        return;
    int pos = Partition(r, begin, end, dir);
    if (result.size() < level)
    {
        result.push_back({});
    }
    vector<int> a;
    for (int i = 0; i < num; i++)
    {
        a.push_back(r[i]);
    }
    result[level - 1].push_back(a);
    QuickSort(r, begin, pos - 1, level + 1, dir);
    QuickSort(r, pos + 1, end, level + 1, dir);
}