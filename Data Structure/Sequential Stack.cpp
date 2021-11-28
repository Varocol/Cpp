//˳��ջ��ʵ��
#include <iostream>
#include <cstdlib>
using namespace std;
#define StackSize 2
typedef int DataType;
string letter = "0123456789ABCDEF";
typedef struct
{
    DataType data[StackSize];
    int top;
} StackType;

class SeqStack
{
private:
    StackType stack;

public:
    SeqStack();
    ~SeqStack();
    int InitStack();
    void DestoryStack();
    int Push(DataType element);
    DataType Pop();
    DataType GetTop();
    bool Empty();
};

//�����������
SeqStack::~SeqStack()
{
    DestoryStack();
}
//��ʼ������
SeqStack::SeqStack()
{
    InitStack();
}
//��ʼ��ջ
int SeqStack::InitStack()
{
    stack.top = -1;
    return 1;
}
//����ջ
void SeqStack::DestoryStack()
{
    cout<<"ջ�ѱ�����!"<<endl;
}
//Ԫ����ջ
int SeqStack::Push(DataType element)
{
    if (stack.top + 1 == StackSize)
    {
        cout << "ջ�ѵ������洢�޶ȣ�" << endl;
        return 0;
    }
    stack.data[++stack.top] = element;
    return 1;
}
//Ԫ�س�ջ
DataType SeqStack::Pop()
{
    if (stack.top == -1)
    {
        cout << "ջ�ѵ���ײ���" << endl;
        return 0;
    }
    return stack.data[stack.top--];
}
//����ջ��Ԫ��
DataType SeqStack::GetTop()
{
    if (stack.top == -1)
    {
        cout << "ջΪ�գ������Ԫ�أ�" << endl;
        return 0;
    }
    return stack.data[stack.top];
}
//�ж�ջ�Ƿ�Ϊ��
bool SeqStack::Empty()
{
    return stack.top == -1;
}
//numΪ��Ҫת��������nΪ������
string Convert(int num, int n)
{
    SeqStack temp = SeqStack();
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
    SeqStack test;
    //��ʼ��ջ
    test = SeqStack();
    cout << "�ѳ�ʼ��ջ" << endl;
    cout << endl;

    //Ԫ����ջ
    test.Push(1);
    cout << "��ջԪ�أ�1" << endl;
    test.Push(2);
    cout << "��ջԪ�أ�2" << endl;
    //��ջ���
    test.Push(3);
    cout << endl;

    //Ԫ�س�ջ
    cout << "��ջһ��Ԫ�أ�" << test.Pop() << endl;
    cout << "��ջһ��Ԫ�أ�" << test.Pop() << endl;
    //��ջ���
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
    cout<<"15��16����ת�������\n";
    cout<<Convert(15,16)<<endl;

    system("pause");

}