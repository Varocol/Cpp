#include "Tree.h"
//树的空构造方法
SortTree::SortTree()
{
}
//树的构造方法
SortTree::SortTree(vector<Datatype> r)
{
    CreateTree(r);
}
//树的析构方法
SortTree::~SortTree()
{
    Destory();
    cout << "已销毁树" << endl;
}
//创建树
void SortTree::CreateTree(vector<Datatype> r)
{
    if (r.size())
    {
        root = new Node;
        root->data = 0;
        root->rchild = NULL;
        root->lchild = NULL;
        root->parent = NULL;
        Node *temp = new Node;
        temp->data = r[0];
        temp->lchild = NULL;
        temp->rchild = NULL;
        temp->parent = NULL;
        root->rchild = temp;
        for (int i = 1; i < r.size(); i++)
        {
            Insert(r[i]);
        }
    }
}
//插入元素
void SortTree::Insert(Datatype data)
{
    Node *temp = root->rchild, *pre = temp;
    while (temp != NULL)
    {
        if (temp->data < data)
        {
            pre = temp;
            temp = temp->rchild;
        }
        else
        {
            pre = temp;
            temp = temp->lchild;
        }
    }
    temp = new Node;
    temp->data = data;
    temp->rchild = NULL;
    temp->lchild = NULL;
    temp->parent = pre;
    if (pre->data < data)
    {
        pre->rchild = temp;
    }
    else if (pre->data > data)
    {
        pre->lchild = temp;
    }
}
//删除元素
void SortTree::Delete(Datatype data)
{
    Node *p = Search(data), *f = p->parent;

    Node *&temp = p == f->rchild ? f->rchild : f->lchild;

    if ((p->lchild == NULL) && (p->rchild == NULL))
    {
        temp = NULL;
        delete p;
        return;
    }
    if (p->rchild == NULL)
    {
        temp = p->lchild;
        delete p;
        return;
    }
    if (p->lchild == NULL)
    {
        temp = p->rchild;
        delete p;
        return;
    }
    Node *par = p, *s = p->rchild;
    while (s->lchild != NULL)
    {
        par = s;
        s = s->lchild;
    }
    p->data = s->data;
    if (par == p)
        par->rchild = s->rchild;
    else
        par->lchild = s->rchild;
    delete s;
}
//销毁树
void SortTree::Destory()
{
    //利用栈非递归
    vector<Node *> stack;
    stack.push_back(root);
    for (int i = 0; i < stack.size(); i++)
    {
        if (stack[i]->lchild != NULL)
        {
            stack.push_back(stack[i]->lchild);
        }
        if (stack[i]->rchild != NULL)
        {
            stack.push_back(stack[i]->rchild);
        }
        delete stack[i];
    }
}
//返回查找到的元素
Node *SortTree::Search(Datatype data)
{
    Node *temp = root->rchild;
    while (temp != NULL && temp->data != data)
    {
        if (temp->data < data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }
    return temp;
}
//查找层数
int SortTree::Level(Datatype data)
{
    Node *temp = root->rchild;
    int level = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
            break;
        if (temp->data < data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
        level++;
    }
    if (temp == NULL)
        return 0;
    return level;
}
