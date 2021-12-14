#include "Modules.h"
/*
   注意！！！
   所有的有关内存的声明都应该在 '.cpp' 或 '.c' 完成, '.h' 只提供接口
*/
//密码顺序表(循环链表)
Node *PassList;
//出队队列
int *Queue;
//约瑟夫环长度
int length;

//初始化密码循环链表
void CreatePassList()
{
    srand((unsigned int)time(0));
    PassList = new Node[length];
    for (int i = 0; i < length; i++)
    {
        PassList[i].num = i + 1;
        PassList[i].data = rand();
        PassList[i].front = &PassList[(i + 1) % length];
        PassList[i].back = &PassList[(i - 1 + length) % length];
    }
}

//初始化出队队列
void CreateQueue()
{
    Queue = new int[length];
}

//读取数据
void ReadData()
{
    cout << "请输入约瑟夫环的人数:";
    cin >> length;
}

//初始化数据
void Init()
{
    ReadData();
    CreatePassList();
    CreateQueue();
}

//删除某个结点
void Delete(Node *node)
{
    node->front->back = node->back;
    node->back->front = node->front;
}

//查找结点
Node *Find(Node *node, int count, int length)
{
    Node *result = node;
    bool flag;
    if (count <= length / 2)
    {
        flag = true;
    }
    else
    {
        flag = false;
        count = length - count;
    }
    while (count--)
    {
        result = flag ? result->front : result->back;
    }
    return result;
}

//解决问题
void Solve()
{
    //暂存长度
    int tmp_len = length;
    //密码变量
    int m = PassList->data;
    //工作结点
    Node *temp = PassList->back;
    //循环解决问题
    while (tmp_len)
    {
        //简化密码
        m %= tmp_len;
        //查找结点
        temp = Find(temp, m, tmp_len);
        //得出密码
        m = temp->data;
        //出队
        cout << "出队编号: " << temp->num << endl;
        //放置Queue数组
        Queue[length - tmp_len] = temp->num;
        //删除节点
        temp = temp->back;
        Delete(temp->front);
        //更新长度
        tmp_len--;
    }
}

//输出队列
void Displayresult()
{
    cout << "出列序列为: ";
    for (int i = 0; i < length; i++)
    {
        if (i)
            cout << " ";
        cout << Queue[i];
    }
    cout << endl;
}

//输出每个人的密码
void Displaypass()
{
    for (int i = 0; i < length; i++)
    {
        cout << "编号: " << PassList[i].num << "  \t"
             << "密码: " << PassList[i].data << endl;
    }
}

//释放内存
void Releasememory()
{
    delete[] PassList;
    delete[] Queue;
}