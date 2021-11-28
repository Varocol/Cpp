//循环顺序队列
#include <iostream>
#include <cstdlib>
#define QueueSize 3
typedef int DataType;
using namespace std;

typedef struct
{
    DataType data[QueueSize];
    int front, rear;
} QueueType;

class CirQueue
{
private:
    QueueType queue;

public:
    CirQueue();
    ~CirQueue();
    void InitQueue();
    void DestoryQueue();
    int EnQueue(DataType element);
    DataType DeQueue();
    DataType GetHead();
    bool Empty();
};
//类的构造方法
CirQueue::CirQueue()
{
    InitQueue();
}
//类的析构方法
CirQueue::~CirQueue()
{
    DestoryQueue();
}
//初始化队列
void CirQueue::InitQueue()
{
    queue.front = queue.rear = QueueSize - 1;
}
//销毁队列
void CirQueue::DestoryQueue()
{
    cout<<"队列已被销毁"<<endl;
}
//元素入队
int CirQueue::EnQueue(DataType element)
{
    if ((queue.rear + 1) % QueueSize == queue.front)
    {
        cout << "队列已到达最大存储限度！" << endl;
        return 0;
    }
    queue.rear = (queue.rear + 1) % QueueSize;
    queue.data[queue.rear] = element;
    return 1;
}
//元素出队
DataType CirQueue::DeQueue()
{
    DataType temp;
    if (Empty())
    {
        cout << "队列为空，请插入元素" << endl;
        return 0;
    }
    temp = queue.data[(queue.front + 1) % QueueSize];
    queue.front = (queue.front + 1) % QueueSize;
    return temp;
}
//获取队头元素
DataType CirQueue::GetHead()
{
    if (Empty())
    {
        cout << "队列为空，请插入元素" << endl;
        return 0;
    }
    return queue.data[(queue.front + 1) % QueueSize];
}
//判断队列是否为空
bool CirQueue::Empty()
{
    return queue.front == queue.rear;
}

int main()
{
    CirQueue test;
    //初始化队列
    test = CirQueue();
    cout << "已初始化队列" << endl;
    cout << endl;

    //元素入队列
    test.EnQueue(1);
    cout << "入队元素：1" << endl;
    test.EnQueue(2);
    cout << "入队元素：2" << endl;
    //入队溢出
    test.EnQueue(3);
    cout << endl;

    //元素出队
    cout << "出队一个元素：" << test.DeQueue() << endl;
    cout << "出队一个元素：" << test.DeQueue() << endl;
    //出队溢出
    test.DeQueue();
    cout<<endl;

    //获取队头元素
    test.EnQueue(10);
    cout << "获取队头元素：" << test.GetHead() << endl;
    test.DeQueue();
    test.GetHead();
    cout<<endl;

    //判断队列是否为空
    cout << "队列是否为空：" << boolalpha << test.Empty() << endl;
    cout<<endl;

    system("pause");
}