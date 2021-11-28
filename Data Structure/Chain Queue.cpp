#include <iostream>
typedef int DataType;
using namespace std;
struct Node
{
    DataType data;
    Node *next;
};
class ChainQueue
{
private:
    Node *Front;
    Node *Rear;

public:
    ChainQueue();
    ~ChainQueue();
    void InitQueue();
    void DestoryQueue();
    void EnQueue(DataType element);
    DataType DeQueue();
    DataType GetHead();
    bool Empty();
};

ChainQueue::ChainQueue()
{
    InitQueue();
}
ChainQueue::~ChainQueue()
{
    DestoryQueue();
}
void ChainQueue::InitQueue()
{
    Front = new Node;
    Front->data = 0;
    Front->next = NULL;
    Rear = Front;
}
void ChainQueue::DestoryQueue()
{
    Node *temp;
    while (Front)
    {
        temp = Front->next;
        delete Front;
        Front = temp;
    }
}
void ChainQueue::EnQueue(DataType element)
{
    Node *temp = new Node;
    temp->data = element;
    temp->next = NULL;
    Rear->next = temp;
    Rear = temp;
}
DataType ChainQueue::DeQueue()
{
    if (Empty())
    {
        cout << "队列为空，请插入元素" << endl;
        return 0;
    }
    //队头元素不能删除
    Node *temp = Front->next->next;
    DataType x = Front->next->data;
    if (temp == NULL)
        Rear = Front;
    delete Front->next;
    Front->next = temp;
    return x;
}
DataType ChainQueue::GetHead()
{
    if (Empty())
    {
        cout << "队列为空，请插入元素" << endl;
        return 0;
    }
    return Front->next->data;
}
bool ChainQueue::Empty()
{
    return Front == Rear;
}

int main()
{
    //这里一定要直接写构造方法，否则会分配两次
    ChainQueue test = ChainQueue();
    //初始化队列
    cout << "已初始化队列" << endl;
    cout << endl;

    //元素入队列
    test.EnQueue(1);
    cout << "入队元素：1" << endl;
    test.EnQueue(2);
    cout << "入队元素：2" << endl;
    test.EnQueue(3);
    cout << "入队元素：3" << endl;
    cout << endl;

    //元素出队
    cout << "出队一个元素：" << test.DeQueue() << endl;
    cout << "出队一个元素：" << test.DeQueue() << endl;
    cout << "出队一个元素：" << test.DeQueue() << endl;
    //出队溢出
    test.DeQueue();
    cout << endl;

    //获取队头元素
    test.EnQueue(10);
    cout << "入队元素：10" << endl;
    cout << "获取队头元素：" << test.GetHead() << endl;
    test.DeQueue();
    cout << "出队元素：10" << endl;
    test.GetHead();
    cout << endl;

    //判断队列是否为空
    cout << "队列是否为空：" << boolalpha << test.Empty() << endl;
}