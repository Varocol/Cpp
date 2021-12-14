#include "Modules.h"
//程序指令
int Code;
//二叉排序树
SortTree tree = SortTree();
//返回值
ret_val Status;

//程序运行函数
void Pro_Run()
{
    while (Code != CMD_Quit)
    {
        Menu();
        Code_Read();
        Fun_Run();
    }
}

//程序调度函数
void Fun_Run()
{
    switch (Code)
    {
    case CMD_CreateTree:
        CreateTree();
        break;
    case CMD_DestoryTree:
        DestoryTree();
        break;
    case CMD_DeleteNode:
        DeleteNode();
        break;
    case CMD_InsertNode:
        InsertNode();
        break;
    case CMD_SearchNode:
        SearchNode();
        break;
    case CMD_PreorderOutput:
        PreorderOutput();
        break;
    case CMD_InorderOutput:
        InorderOutput();
        break;
    case CMD_PostorderOutput:
        PostorderOutput();
        break;
    case CMD_LevelorderOutput:
        LevelorderOutput();
        break;
    case CMD_TreeSizeOutput:
        TreeSizeOutput();
        break;
    case CMD_CalASL:
        CalASL();
        break;
    case CMD_About:
        About();
        break;
    case CMD_Quit:
        Quit();
        break;
    }
}

//正确输入指令
void Code_Read()
{
    cout << "请输入以上编号执行对应操作:" << endl;
    while (1)
    {
        Num_Read(Code);
        if (Code > CMD_Quit || Code < CMD_CreateTree || cin.eof())
        {
            if (cin.eof())
                cin.clear();
            cout << "请输入正确的指令!" << endl;
            continue;
        }
        break;
    }
}

//读取输入
void Num_Read(int &num)
{
    while (!(cin >> num) && !cin.eof())
    {
        cout << "数字输入错误,请重新输入:" << endl;
        //重新开启cin
        cin.clear();
        //清空cin缓冲流
        cin.sync();
    }
}

//菜单
void Menu()
{
    //输出菜单
    cout << "******************二叉排序树测试程序******************" << endl
         << "0 : 创建二叉排序树" << endl
         << "1 : 销毁二叉排序树" << endl
         << "2 : 删除二叉排序树结点" << endl
         << "3 : 插入二叉排序树结点" << endl
         << "4 : 查找二叉排序树结点" << endl
         << "5 : 前序输出二叉排序树" << endl
         << "6 : 中序输出二叉排序树" << endl
         << "7 : 后序输出二叉排序树" << endl
         << "8 : 层序输出二叉排序树" << endl
         << "9 : 输出二叉排序树大小" << endl
         << "10: 计算二叉排序树的ASL" << endl
         << "11: 关于程序" << endl
         << "12: 退出程序" << endl
         << "******************************************************" << endl;
}

//创建二叉排序树
void CreateTree()
{
    vector<Datatype> Data;
    Datatype x;
    cout << "********************创建二叉排序树********************" << endl;
    if (!tree.Empty())
    {
        cout << "二叉排序树已存在,请先销毁二叉排序树!" << endl;
        return;
    }
    cout << "请输入数字序列(输入Ctrl+Z结束):" << endl;
    while (1)
    {
        Num_Read(x);
        if (cin.eof())
        {
            cin.clear();
            if (Data.size() == 0)
            {
                cout << "请至少输入一个数!" << endl;
                cout << "请输入数字序列(输入Ctrl+Z结束):" << endl;
                continue;
            }
            break;
        }
        else
        {
            Data.push_back(x);
        }
    }
    tree.CreateTree(Data);
    cout << "创建成功!" << endl;
}

//销毁二叉排序树
void DestoryTree()
{
    cout << "********************销毁二叉排序树********************" << endl;
    if (tree.Empty())
    {
        cout << "二叉排序树不存在,请先建立二叉排序树!" << endl;
        return;
    }
    tree.DestoryTree();
    cout << "销毁成功!" << endl;
}

//删除二叉排序树结点
void DeleteNode()
{
    if (tree.Empty())
    {
        cout << "二叉排序树为空,请先插入结点!" << endl;
        return;
    }
    cout << "******************删除二叉排序树结点******************" << endl;
    cout << "请输入需要删除的结点:" << endl;
    Datatype x;
    while (1)
    {
        Num_Read(x);
        if (cin.eof())
        {
            cin.clear();
            cout << "数字输入错误,请重新输入:" << endl;
            continue;
        }
        break;
    }
    Status = tree.DeleteNode(x);
    if (Status == Success)
    {
        cout << "结点 " << x << " 删除成功!" << endl;
    }
    else if (Status == Node_Not_Found)
    {
        cout << "结点 " << x << " 找不到!" << endl;
    }
}

//插入二叉排序树结点
void InsertNode()
{
    cout << "******************插入二叉排序树结点******************" << endl;
    cout << "请输入需要插入的结点:" << endl;
    Datatype x;
    while (1)
    {
        Num_Read(x);
        if (cin.eof())
        {
            cin.clear();
            cout << "数字输入错误,请重新输入:" << endl;
            continue;
        }
        break;
    }
    Status = tree.InsertNode(x);
    if (Status == Success)
    {
        cout << "结点 " << x << " 插入成功!" << endl;
    }
    else if (Status == Node_Exsit)
    {
        //检测到重复数据
        cout << "结点 " << x << " 重复输入!" << endl;
    }
}

//查找二叉排序树结点
void SearchNode()
{
    if (tree.Empty())
    {
        cout << "二叉排序树为空,请先插入结点!" << endl;
        return;
    }
    cout << "******************查找二叉排序树结点******************" << endl;
    cout << "请输入需要查找的结点:" << endl;
    Datatype x;
    while (1)
    {
        Num_Read(x);
        if (cin.eof())
        {
            cin.clear();
            cout << "数字输入错误,请重新输入:" << endl;
            continue;
        }
        break;
    }
    Node *result = tree.SearchNode(x);
    if (result != NULL)
    {
        cout << "结点 " << x << " 查找成功!" << endl;
        cout << "该结点的左孩子为: ";
        if (result->left)
        {
            cout << result->left->data << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
        cout << "该结点的右孩子为: ";
        if (result->right)
        {
            cout << result->right->data << endl;
        }
        else
        {
            cout << "NULL" << endl;
        }
    }
    else
    {
        cout << "结点 " << x << " 不存在!" << endl;
    }
}

//前序输出二叉排序树
void PreorderOutput()
{
    if (tree.Empty())
    {
        cout << "二叉排序树为空,请先插入结点!" << endl;
        return;
    }
    vector<Datatype> order = tree.Preorder();
    cout << "当前二叉排序树的前序遍历是:" << endl;
    for (int i = 0; i < order.size(); i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << order[i];
    }
    cout << endl;
}

//中序输出二叉排序树
void InorderOutput()
{
    if (tree.Empty())
    {
        cout << "二叉排序树为空,请先插入结点!" << endl;
        return;
    }
    vector<Datatype> order = tree.Inorder();
    cout << "当前二叉排序树的中序遍历是:" << endl;
    for (int i = 0; i < order.size(); i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << order[i];
    }
    cout << endl;
}

//后序输出二叉排序树
void PostorderOutput()
{
    if (tree.Empty())
    {
        cout << "二叉排序树为空,请先插入结点!" << endl;
        return;
    }
    vector<Datatype> order = tree.Postorder();
    cout << "当前二叉排序树的后序遍历是:" << endl;
    for (int i = 0; i < order.size(); i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << order[i];
    }
    cout << endl;
}

//层序输出二叉排序树
void LevelorderOutput()
{
    if (tree.Empty())
    {
        cout << "二叉排序树为空,请先插入结点!" << endl;
        return;
    }
    vector<Datatype> order = tree.Levelorder();
    cout << "当前二叉排序树的层序遍历是:" << endl;
    for (int i = 0; i < order.size(); i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << order[i];
    }
    cout << endl;
}
//输出二叉排序树大小
void TreeSizeOutput()
{
    cout << "当前二叉排序树大小为:" << tree.Size() << endl;
}

//计算二叉排序树的ASL
void CalASL()
{
    if (tree.Empty())
    {
        cout << "二叉排序树为空,请先插入结点!" << endl;
        return;
    }
    pair<double, double> ASL = tree.CalASL();
    cout << "搜索成功的ASL为:" << ASL.first << endl;
    cout << "搜索失败的ASL为:" << ASL.second << endl;
}

//关于程序
void About()
{
    cout << endl;
    cout << "***********************************************" << endl;
    cout << "程序名   : 二叉排序树测试程序" << endl;
    cout << "制作团队 : 北华大学计算机科学技术学院20级1班" << endl;
    cout << "发行时间 : 2021年 12月 12日 星期日 15:40:25 CST" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
}

//退出程序
void Quit()
{
    cout << "已退出程序!" << endl;
}