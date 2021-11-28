//ѭ��˳�����
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
//��Ĺ��췽��
CirQueue::CirQueue()
{
    InitQueue();
}
//�����������
CirQueue::~CirQueue()
{
    DestoryQueue();
}
//��ʼ������
void CirQueue::InitQueue()
{
    queue.front = queue.rear = QueueSize - 1;
}
//���ٶ���
void CirQueue::DestoryQueue()
{
    cout<<"�����ѱ�����"<<endl;
}
//Ԫ�����
int CirQueue::EnQueue(DataType element)
{
    if ((queue.rear + 1) % QueueSize == queue.front)
    {
        cout << "�����ѵ������洢�޶ȣ�" << endl;
        return 0;
    }
    queue.rear = (queue.rear + 1) % QueueSize;
    queue.data[queue.rear] = element;
    return 1;
}
//Ԫ�س���
DataType CirQueue::DeQueue()
{
    DataType temp;
    if (Empty())
    {
        cout << "����Ϊ�գ������Ԫ��" << endl;
        return 0;
    }
    temp = queue.data[(queue.front + 1) % QueueSize];
    queue.front = (queue.front + 1) % QueueSize;
    return temp;
}
//��ȡ��ͷԪ��
DataType CirQueue::GetHead()
{
    if (Empty())
    {
        cout << "����Ϊ�գ������Ԫ��" << endl;
        return 0;
    }
    return queue.data[(queue.front + 1) % QueueSize];
}
//�ж϶����Ƿ�Ϊ��
bool CirQueue::Empty()
{
    return queue.front == queue.rear;
}

int main()
{
    CirQueue test;
    //��ʼ������
    test = CirQueue();
    cout << "�ѳ�ʼ������" << endl;
    cout << endl;

    //Ԫ�������
    test.EnQueue(1);
    cout << "���Ԫ�أ�1" << endl;
    test.EnQueue(2);
    cout << "���Ԫ�أ�2" << endl;
    //������
    test.EnQueue(3);
    cout << endl;

    //Ԫ�س���
    cout << "����һ��Ԫ�أ�" << test.DeQueue() << endl;
    cout << "����һ��Ԫ�أ�" << test.DeQueue() << endl;
    //�������
    test.DeQueue();
    cout<<endl;

    //��ȡ��ͷԪ��
    test.EnQueue(10);
    cout << "��ȡ��ͷԪ�أ�" << test.GetHead() << endl;
    test.DeQueue();
    test.GetHead();
    cout<<endl;

    //�ж϶����Ƿ�Ϊ��
    cout << "�����Ƿ�Ϊ�գ�" << boolalpha << test.Empty() << endl;
    cout<<endl;

    system("pause");
}