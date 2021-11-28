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
        cout << "����Ϊ�գ������Ԫ��" << endl;
        return 0;
    }
    //��ͷԪ�ز���ɾ��
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
        cout << "����Ϊ�գ������Ԫ��" << endl;
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
    //����һ��Ҫֱ��д���췽����������������
    ChainQueue test = ChainQueue();
    //��ʼ������
    cout << "�ѳ�ʼ������" << endl;
    cout << endl;

    //Ԫ�������
    test.EnQueue(1);
    cout << "���Ԫ�أ�1" << endl;
    test.EnQueue(2);
    cout << "���Ԫ�أ�2" << endl;
    test.EnQueue(3);
    cout << "���Ԫ�أ�3" << endl;
    cout << endl;

    //Ԫ�س���
    cout << "����һ��Ԫ�أ�" << test.DeQueue() << endl;
    cout << "����һ��Ԫ�أ�" << test.DeQueue() << endl;
    cout << "����һ��Ԫ�أ�" << test.DeQueue() << endl;
    //�������
    test.DeQueue();
    cout << endl;

    //��ȡ��ͷԪ��
    test.EnQueue(10);
    cout << "���Ԫ�أ�10" << endl;
    cout << "��ȡ��ͷԪ�أ�" << test.GetHead() << endl;
    test.DeQueue();
    cout << "����Ԫ�أ�10" << endl;
    test.GetHead();
    cout << endl;

    //�ж϶����Ƿ�Ϊ��
    cout << "�����Ƿ�Ϊ�գ�" << boolalpha << test.Empty() << endl;
}