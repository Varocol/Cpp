//二叉树
//存储结构:二叉链表(不用顺序存储)
//前序、中序、后序递归算法和非递归
#include <iostream>
#include <vector>
#include <cstdlib>
typedef char DataType;
using namespace std;
struct Tree_Node
{
    DataType data;
    Tree_Node *lchild, *rchild;
};

class Binary_Tree
{
private:
    Tree_Node *root;
    vector<vector<DataType>> result;
    Tree_Node *CreateTree(Tree_Node *root);
    void DestoryTree(Tree_Node *root);
    void PreOrder_Recursion(Tree_Node *root);
    void InOrder_Recursion(Tree_Node *root);
    void PostOrder_Recursion(Tree_Node *root);
    void LevelOrder_Recursion(Tree_Node *root, int num);

public:
    Binary_Tree();
    ~Binary_Tree();
    void CreateTree();
    void DestoryTree();
    void PreOrder_Recursion();
    void InOrder_Recursion();
    void PostOrder_Recursion();
    void LevelOrder_Recursion();
    void PreOrder();
    void InOrder();
    void PostOrder();
    void LevelOrder();
};
//二叉树析构造方法
Binary_Tree::~Binary_Tree()
{
    DestoryTree();
}
//二叉树构造方法
Binary_Tree::Binary_Tree()
{
    CreateTree();
}
//二叉树创建调用方法(递归)
Tree_Node *Binary_Tree::CreateTree(Tree_Node *root)
{
    char ch;
    cin >> ch;
    if (ch == '#')
    {
        root = NULL;
    }
    else
    {
        root = new Tree_Node;
        root->data = ch;
        root->lchild = CreateTree(root->lchild);
        root->rchild = CreateTree(root->rchild);
    }
    return root;
}
//二叉树创建方法(递归)
void Binary_Tree::CreateTree()
{
    cout << "请输入二叉树(空节点用'#'表示):\n";
    root = CreateTree(root);
}
//二叉树销毁调用方法
void Binary_Tree::DestoryTree()
{
    DestoryTree(root);
    cout << "已销毁二叉树" << endl;
}
//二叉树销毁方法
void Binary_Tree::DestoryTree(Tree_Node *root)
{
    if (root == NULL)
    {
        return;
    }
    DestoryTree(root->lchild);
    DestoryTree(root->rchild);
    delete root;
}
//二叉树的前序遍历(非递归)
void Binary_Tree::PreOrder()
{
    vector<Tree_Node *> S;
    Tree_Node *bt = root;
    while (bt != NULL || S.size())
    {
        while (bt != NULL)
        {
            cout << bt->data;
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
    cout << endl;
}
//二叉树的中序遍历(非递归)
void Binary_Tree::InOrder()
{
    vector<Tree_Node *> S;
    Tree_Node *bt = root;
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
            cout << bt->data;
            S.pop_back();
            bt = bt->rchild;
        }
    }
    cout << endl;
}
//二叉树的后序遍历(非递归)
void Binary_Tree::PostOrder()
{
    vector<pair<Tree_Node *, int>> S;
    Tree_Node *bt = root;
    while (bt != NULL || S.size())
    {
        //一直到最左边
        while (bt != NULL)
        {
            S.push_back(pair<Tree_Node *, int>(bt, 1));
            bt = bt->lchild;
        }
        while (S.size() && S.back().second == 2)
        {
            bt = S.back().first;
            S.pop_back();
            cout << bt->data;
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

    cout << endl;
}
//二叉树的层序遍历(非递归)
void Binary_Tree::LevelOrder()
{
    vector<Tree_Node *> S;
    S.push_back(root);
    for (int i = 0; i < S.size(); i++)
    {
        cout<<S[i]->data;
        if(S[i]->lchild != NULL)
        {
            S.push_back(S[i]->lchild);  
        }
        if(S[i]->rchild != NULL)
        {
            S.push_back(S[i]->rchild);
        }
    }
    cout<<endl;
}
//二叉树的前序遍历递归方法
void Binary_Tree::PreOrder_Recursion(Tree_Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    PreOrder_Recursion(root->lchild);
    PreOrder_Recursion(root->rchild);
}
//二叉树的前序遍历递归的调用方法
void Binary_Tree::PreOrder_Recursion()
{
    PreOrder_Recursion(root);
    cout << endl;
}
//二叉树的中序遍历递归方法
void Binary_Tree::InOrder_Recursion(Tree_Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder_Recursion(root->lchild);
    cout << root->data;
    InOrder_Recursion(root->rchild);
}
//二叉树的中序遍历递归的调用方法
void Binary_Tree::InOrder_Recursion()
{
    InOrder_Recursion(root);
    cout << endl;
}
//二叉树的后序遍历递归方法
void Binary_Tree::PostOrder_Recursion(Tree_Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder_Recursion(root->lchild);
    PostOrder_Recursion(root->rchild);
    cout << root->data;
}
//二叉树的后序遍历递归的调用方法
void Binary_Tree::PostOrder_Recursion()
{
    PostOrder_Recursion(root);
    cout << endl;
}
//二叉树的层序遍历递归方法
void Binary_Tree::LevelOrder_Recursion(Tree_Node *root, int num)
{
    if (root == NULL)
        return;
    if (num > result.size())
        result.push_back(vector<DataType>());
    result[num - 1].push_back(root->data);
    LevelOrder_Recursion(root->lchild, num + 1);
    LevelOrder_Recursion(root->rchild, num + 1);
}
//二叉树的层序遍历递归的调用方法
void Binary_Tree::LevelOrder_Recursion()
{
    //清空
    result.clear();
    //调用层序遍历递归
    LevelOrder_Recursion(root, 1);
    //输出
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
        }
    cout << endl;
}

int main()
{
    Binary_Tree tree = Binary_Tree();
    //递归测试样例:ab#d##c##
    cout<<"测试遍历算法："<<endl;
    //前序遍历 abdc
    tree.PreOrder_Recursion();
    //中序遍历 bdac
    tree.InOrder_Recursion();
    //后序遍历 dbca
    tree.PostOrder_Recursion();
    //层序遍历 abcd
    tree.LevelOrder_Recursion();
    cout<<endl;

    //非递归测试样例:ab#cd###ef#g###
    cout<<"测试非遍历算法："<<endl;
    //前序遍历 abcdefg
    tree.PreOrder();
    //中序遍历 bdcafge
    tree.InOrder();
    //后序遍历 dcbgfea
    tree.PostOrder();
    //层序遍历 abecfdg
    tree.LevelOrder();
    system("pause");
}