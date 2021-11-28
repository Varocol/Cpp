//��ջ��ʵ��
#include <iostream>
using namespace std;
typedef int DataType;
string letter = "0123456789ABCDEF";
struct Node
{
    DataType data;
    Node *next;
} ;

class ChainStack
{
private:
    Node *top;

public:
    ChainStack();
    ~ChainStack();
    void InitStack();
    void DestoryStack();
    void Push(DataType element);
    DataType Pop();
    DataType GetTop();
    bool Empty();
};
//�����������
ChainStack::~ChainStack()
{
    DestoryStack();
}
//��Ĺ��췽��
ChainStack::ChainStack()
{
    InitStack();
}
//��ʼ��ջ
void ChainStack::InitStack()
{
    top = NULL;
}
//����ջ
void ChainStack::DestoryStack()
{
    Node *temp;
    while (top)
    {
        temp = top->next;
        delete top;
        top = temp;
    }
    cout<<"ջ�ѱ�����"<<endl;
}
//Ԫ����ջ
void ChainStack::Push(DataType element)
{
    Node *temp = new Node;
    temp->data = element;
    temp->next = top;
    top = temp;
}
//Ԫ�س�ջ
DataType ChainStack::Pop()
{
    if(Empty())
    {
        cout<<"ջΪ�գ������Ԫ�أ�"<<endl;
        return 0;
    }
    Node *temp = top->next;
    DataType x = top->data;
    delete top;
    top = temp;
    return x;
}
//��ȡջ��Ԫ��
DataType ChainStack::GetTop()
{
    if(Empty())
    {
        cout<<"ջΪ�գ������Ԫ�أ�"<<endl;
        return 0;
    }
    return top->data;
}
//                
bool ChainStack::Empty()
{
    return top == NULL;
}

//numΪ��Ҫת��������nΪ������
string Convert(int num, int n)
{
    ChainStack temp = ChainStack();
    string result;
    while(num)
    {
        temp.Push(num%n);
        num/=n;
    }
    while(!temp.Empty())
    {
       result += letter[temp.Pop()];   
    }
    return result;
}

int main()
{
    ChainStack test;
    //��ʼ��ջ
    test = ChainStack();
    cout << "�ѳ�ʼ��ջ" << endl;
    cout << endl;

    //Ԫ����ջ
    test.Push(1);
    cout << "��ջԪ�أ�1" << endl;
    test.Push(2);
    cout << "��ջԪ�أ�2" << endl;
    cout << endl;

    //Ԫ�س�ջ
    cout << "��ջһ��Ԫ�أ�" << test.Pop() << endl;
    cout << "��ջһ��Ԫ�أ�" << test.Pop() << endl;
    test.Pop();
    cout<<endl;

    //��ȡջ��Ԫ��
    test.Push(1);
    cout << "��ȡջ��Ԫ�أ�" << test.GetTop() << endl;
    test.Pop();
    test.GetTop();
    cout<<endl;

    //�ж�ջ�Ƿ�Ϊ��
    cout << "ջ�Ƿ�Ϊ�գ�" << boolalpha << test.Empty() << endl;
    cout<<endl;

    //����ת��
    cout<<Convert(15,16)<<endl;
}