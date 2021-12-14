#include <iostream>
#include <algorithm>
using namespace std;
typedef enum
{
    up = 1,
    down = -1
} direciton;
//折半查找的递归和非递归
int BinSearch1(int r[], int n, int k, direciton dir)
{
    int mid, low = 0, high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (dir * k < dir * r[mid])
            high = mid - 1;
        else if (dir * k > dir * r[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
int BinSearch2(int r[], int low, int high, int k, direciton dir)
{
    int mid;
    if (low > high)
        return -1;
    else
    {
        mid = (low + high) / 2;
        if (dir * k < dir * r[mid])
            return BinSearch2(r, low, mid - 1, k, dir);
        else if (dir * k > dir * r[mid])
            return BinSearch2(r, mid + 1, high, k, dir);
        else
            return mid;
    }
}

int main()
{
    int num, k, result;
    cout << "请输入数组大小：" << endl;
    cin >> num;
    cout << "请输入查找值：" << endl;
    cin >> k;
    cout << "请输入数组：" << endl;
    int *arr = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    //先排序
    sort(arr, arr + num);
    cout << "非递归方法：" << endl;
    //非递归方法
    result = BinSearch1(arr, num, k, up);
    if (result != -1)
    {
        cout << "已找到,下标为：" << result << endl;
    }
    else
    {
        cout << "抱歉,未找到" << endl;
    }
    cout << endl;
    cout << "递归方法：" << endl;
    //递归方法
    result = BinSearch2(arr, 0, num - 1, k, up);
    if (result != -1)
    {
        cout << "已找到,下标为：" << result << endl;
    }
    else
    {
        cout << "抱歉,未找到" << endl;
    }
}