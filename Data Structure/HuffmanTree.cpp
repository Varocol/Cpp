//哈夫曼树的实现
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MaxSize 100
typedef struct
{
    int weight;
    int parent, lchild, rchild;
} Elemtype;
void Select(Elemtype huffTree[], int n, int *a, int *b)
{
    int min1, min2;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (huffTree[i].parent == -1)
        {
            if (flag)
            {
                min1 = i;
                min2 = i;
                flag = false;
                i = -1;
                continue;
            }
            if (huffTree[i].weight < huffTree[min1].weight)
            {
                min1 = i;
            }
            else if (min2 == min1 || huffTree[min2].weight <= huffTree[i].weight)
            {
                min2 = i;
            }
        }
    }
    *a = min1;
    *b = min2;
}
void HuffmanTree(Elemtype huffTree[], int w[], int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        huffTree[i].parent = -1;
        huffTree[i].lchild = -1;
        huffTree[i].rchild = -1;
        if (i < n)
        {
            huffTree[i].weight = w[i];
        }
    }
    for (int i = n; i < 2 * n - 1; i++)
    {
        int min1, min2;
        Select(huffTree, i, &min1, &min2);
        huffTree[i].weight = huffTree[min1].weight + huffTree[min2].weight;
        huffTree[i].lchild = min1;
        huffTree[i].rchild = min2;
        huffTree[min1].parent = i;
        huffTree[min2].parent = i;
    }
}

int main()
{
    //测试样例: 2,3,4,5
    // 35,25,15,15,10
    //2,3,5
    Elemtype huffTree[MaxSize];
    int weight[MaxSize] = {4,5,7,8,15,20,21,22};
    HuffmanTree(huffTree, weight, 8);
    cout << huffTree[2 * 8 - 2].weight;
    system("pause");
}