//顺序栈的实现
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

//类的析构函数
SeqStack::~SeqStack()
{
    DestoryStack();
}
//初始化对象
SeqStack::SeqStack()
{
    InitStack();
}
//初始化栈
int SeqStack::InitStack()
{
    stack.top = -1;
    return 1;
}
//销毁栈
void SeqStack::DestoryStack()
{
    cout<<"栈已被销毁!"<<endl;
}
//元素入栈
int SeqStack::Push(DataType element)
{
    if (stack.top + 1 == StackSize)
    {
        cout << "栈已到达最大存储限度！" << endl;
        return 0;
    }
    stack.data[++stack.top] = element;
    return 1;
}
//元素出栈
DataType SeqStack::Pop()
{
    if (stack.top == -1)
    {
        cout << "栈已到达底部！" << endl;
        return 0;
    }
    return stack.data[stack.top--];
}
//返回栈顶元素
DataType SeqStack::GetTop()
{
    if (stack.top == -1)
    {
        cout << "栈为空，请插入元素！" << endl;
        return 0;
    }
    return stack.data[stack.top];
}
//判断栈是否为空
bool SeqStack::Empty()
{
    return stack.top == -1;
}
//num为需要转换的数，n为进制数
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
    //初始化栈
    test = SeqStack();
    cout << "已初始化栈" << endl;
    cout << endl;

    //元素入栈
    test.Push(1);
    cout << "入栈元素：1" << endl;
    test.Push(2);
    cout << "入栈元素：2" << endl;
    //入栈溢出
    test.Push(3);
    cout << endl;

    //元素出栈
    cout << "出栈一个元素：" << test.Pop() << endl;
    cout << "出栈一个元素：" << test.Pop() << endl;
    //出栈溢出
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
    cout<<"15的16进制转换结果：\n";
    cout<<Convert(15,16)<<endl;

    system("pause");

}