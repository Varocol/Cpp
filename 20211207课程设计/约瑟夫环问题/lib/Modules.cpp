#include "Modules.h"

/*
   注意！！！
   所有的有关内存的声明都应该在 '.cpp' 或 '.c' 完成, '.h' 只提供接口
*/

//密码顺序表
int *PassList;
//出队队列
int *Queue;
//约瑟夫环长度
int length;
//已出队人数
int num;

//初始化密码顺序表
void CreatePassList()
{
    srand((unsigned int)time(0));
    PassList = new int[length];
    for (int i = 0; i < length; i++)
    {
        PassList[i] = rand();
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
    num = 0;
    ReadData();
    CreatePassList();
    CreateQueue();
}

//解决问题
void Solve()
{
    //记录当前人编号
    int pos = 0;
    //记录上一次入队的队列下标
    int current = 0;
    //折半查找需要用到的变量
    int begin, end, mid, distance;
    //当前人的密码
    int m;
    //循环解决问题
    while (num < length)
    {
        //初始化密码
        m = PassList[pos] % (length - num);
        //折半查找找出最佳移动距离
        begin = current, end = num + current, mid, distance;
        while (begin <= end)
        {
            mid = (begin + end) / 2;
            distance = (Queue[mid % num] + length - Queue[pos]) % length - (mid - pos);
            if (distance > m)
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }
        //取end为最近的出列人的编号
        end %= num;
        //算出还需多少距离,并更新pos的值
        pos = (m - distance + Queue[end]) % length;
        int i;
        for (i = num - 1; i && pos < Queue[i]; i--)
        {
            Queue[i + 1] = Queue[i];
        }
        Queue[i + 1] = pos;
        num++;
        cout << "出队编号: " << pos << endl;
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
        cout << "编号: " << i << "\t密码: " << PassList[i] << endl;
    }
}

//释放内存
void Releasememory()
{
    delete[] PassList;
    delete[] Queue;
}