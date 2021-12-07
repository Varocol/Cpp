#include <iostream>
#include <vector>
using namespace std;
typedef int Datatype;
//树结点
struct Node
{
    Datatype data;
    Node *rchild, *lchild;
};

//第一个输出数标志
bool flag;

//创建树
Node *CreatTree(int);
//先序遍历(递归)
void PreOrder_Recursion(Node *);
//中序遍历(递归)
void InOrder_Recursion(Node *);
//后序遍历(递归)
void PostOrder_Recursion(Node *);
//先序遍历(非递归)
void PreOrder(Node *);
//中序遍历(非递归)
void InOrder(Node *);
//后序遍历(非递归)
void PostOrder(Node *);

int main()
{
    int N;
    scanf("%d", &N);
    //输入树
    Node *Tree = CreatTree(N);
    //先序遍历(递归)
    flag = true;
    PreOrder_Recursion(Tree);
    printf("\n");
    //中序遍历(递归)
    flag = true;
    InOrder_Recursion(Tree);
    printf("\n");
    //后序遍历(递归)
    flag = true;
    PostOrder_Recursion(Tree);
}

//创建树
Node *CreatTree(int num)
{
    int i, l, r;
    //使用1-100下标,并给所有的赋值为NULL;
    Node *Stack[101] = {};
    while (num--)
    {
        scanf("%d %d %d", &i, &l, &r);
        //如果之前没有申请过空间
        if (Stack[i] == NULL)
        {
            Stack[i] = (Node *)malloc(sizeof(Node));
        }
        //赋值数据域
        Stack[i]->data = i;
        Stack[i]->lchild = NULL;
        Stack[i]->rchild = NULL;
        //赋值孩子指针域
        if (l != -1)
        {
            if (Stack[l] == NULL)
            {
                Stack[l] = (Node *)malloc(sizeof(Node));
                Stack[l]->data = l;
                Stack[l]->lchild = NULL;
                Stack[l]->rchild = NULL;
            }
            Stack[i]->lchild = Stack[l];
        }
        if (r != -1)
        {
            if (Stack[r] == NULL)
            {
                Stack[r] = (Node *)malloc(sizeof(Node));
                Stack[r]->data = r;
                Stack[r]->lchild = NULL;
                Stack[r]->rchild = NULL;
            }
            Stack[i]->rchild = Stack[r];
        }
    }
    //返回1根节点
    return Stack[1];
}
//先序遍历(递归)
void PreOrder_Recursion(Node *root)
{
    if (root == NULL)
        return;
    //第一个数不用空格
    if (flag)
    {
        printf("%d", root->data);
        flag = false;
    }
    else
    {
        printf(" %d", root->data);
    }
    PreOrder_Recursion(root->lchild);
    PreOrder_Recursion(root->rchild);
}
//中序遍历(递归)
void InOrder_Recursion(Node *root)
{
    if (root == NULL)
        return;
    InOrder_Recursion(root->lchild);
    //第一个数不用空格
    if (flag)
    {
        printf("%d", root->data);
        flag = false;
    }
    else
    {
        printf(" %d", root->data);
    }
    InOrder_Recursion(root->rchild);
}
//后序遍历(递归)
void PostOrder_Recursion(Node *root)
{
    if (root == NULL)
        return;
    PostOrder_Recursion(root->lchild);
    PostOrder_Recursion(root->rchild);
    //第一个数不用空格
    if (flag)
    {
        printf("%d", root->data);
        flag = false;
    }
    else
    {
        printf(" %d", root->data);
    }
}
//先序遍历(非递归)
void PreOrder(Node *root)
{
    vector<Node *> S;
    Node *bt = root;
    while (bt != NULL || S.size())
    {
        while (bt != NULL)
        {
            if (flag)
            {
                cout << bt->data;
                flag = false;
            }
            else
            {
                cout << " " << bt->data;
            }
            S.push_back(bt);
            bt = bt->lchild;
        }
        if (S.size())
        {
            bt = S.back();
            S.pop_back();
            bt = bt->rchild;
        }
    }
}
//中序遍历(非递归)
void InOrder(Node *root)
{
    vector<Node *> S;
    Node *bt = root;
    while (bt != NULL || S.size())
    {
        while (bt != NULL)
        {
            S.push_back(bt);
            bt = bt->lchild;
        }
        if (S.size())
        {
            bt = S.back();
            if (flag)
            {
                cout << bt->data;
                flag = false;
            }
            else
            {
                cout << " " << bt->data;
            }
            S.pop_back();
            bt = bt->rchild;
        }
    }
}
//后序遍历(非递归)
void PostOrder(Node *root)
{
    vector<pair<Node *, int>> S;
    Node *bt = root;
    while (bt != NULL || S.size())
    {
        //一直到最左边
        while (bt != NULL)
        {
            S.push_back(pair<Node *, int>(bt, 1));
            bt = bt->lchild;
        }
        while (S.size() && S.back().second == 2)
        {
            bt = S.back().first;
            S.pop_back();
            if (flag)
            {
                cout << bt->data;
                flag = false;
            }
            else
            {
                cout << " " << bt->data;
            }
        }
        if (S.size())
        {
            bt = S.back().first->rchild;
            S.back().second = 2;
        }
        else
        {
            break;
        }
    }
}
