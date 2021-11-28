//链栈的实现
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
//类的析构函数
ChainStack::~ChainStack()
{
    DestoryStack();
}
//类的构造方法
ChainStack::ChainStack()
{
    InitStack();
}
//初始化栈
void ChainStack::InitStack()
{
    top = NULL;
}
//销毁栈
void ChainStack::DestoryStack()
{
    Node *temp;
    while (top)
    {
        temp = top->next;
        delete top;
        top = temp;
    }
    cout<<"栈已被销毁"<<endl;
}
//元素入栈
void ChainStack::Push(DataType element)
{
    Node *temp = new Node;
    temp->data = element;
    temp->next = top;
    top = temp;
}
//元素出栈
DataType ChainStack::Pop()
{
    if(Empty())
    {
        cout<<"栈为空，请插入元素！"<<endl;
        return 0;
    }
    Node *temp = top->next;
    DataType x = top->data;
    delete top;
    top = temp;
    return x;
}
//获取栈顶元素
DataType ChainStack::GetTop()
{
    if(Empty())
    {
        cout<<"栈为空，请插入元素！"<<endl;
        return 0;
    }
    return top->data;
}
//                
bool ChainStack::Empty()
{
    return top == NULL;
}

//num为需要转换的数，n为进制数
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
    //初始化栈
    test = ChainStack();
    cout << "已初始化栈" << endl;
    cout << endl;

    //元素入栈
    test.Push(1);
    cout << "入栈元素：1" << endl;
    test.Push(2);
    cout << "入栈元素：2" << endl;
    cout << endl;

    //元素出栈
    cout << "出栈一个元素：" << test.Pop() << endl;
    cout << "出栈一个元素：" << test.Pop() << endl;
    test.Pop();
    cout<<endl;

    //获取栈顶元素
    test.Push(1);
    cout << "获取栈顶元素：" << test.GetTop() << endl;
    test.Pop();
    test.GetTop();
    cout<<endl;

    //判断栈是否为空
    cout << "栈是否为空：" << boolalpha << test.Empty() << endl;
    cout<<endl;

    //进制转换
    cout<<Convert(15,16)<<endl;
}