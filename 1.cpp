#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    string bm;
    int num;
} DataType;
typedef struct
{
    vector<DataType> goods;
    int length;
} SeqList;

int Partition(vector<DataType> &, int, int);

int main()
{
    SeqList L;
    //一趟降序快速排序
    cout << "请输入表长：" << endl;
    cin >> L.length;
    for (int i = 0; i < L.length; i++)
    {
        cin.get();
        cout << "请输入字符串：" << endl;
        L.goods.push_back({});
        getline(cin, L.goods[i].bm);
        cout << "请输入数字:" << endl;
        cin >> L.goods[i].num;
    }
    Partition(L.goods, 0, L.length - 1);
    //第一趟排序结果为：
    for (int i = 0; i < L.goods.size(); i++)
    {
        cout << L.goods[i].bm << " " << L.goods[i].num << endl;
    }
}

int Partition(vector<DataType> &r, int first, int end)
{
    int i = first, j = end;
    bool flag = true;
    while (i < j)
    {
        if (r[i].num <= r[j].num)
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
