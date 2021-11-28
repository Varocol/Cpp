//������
//�洢�ṹ:��������(����˳��洢)
//ǰ�����򡢺���ݹ��㷨�ͷǵݹ�
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
//�����������췽��
Binary_Tree::~Binary_Tree()
{
    DestoryTree();
}
//���������췽��
Binary_Tree::Binary_Tree()
{
    CreateTree();
}
//�������������÷���(�ݹ�)
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
//��������������(�ݹ�)
void Binary_Tree::CreateTree()
{
    cout << "�����������(�սڵ���'#'��ʾ):\n";
    root = CreateTree(root);
}
//���������ٵ��÷���
void Binary_Tree::DestoryTree()
{
    DestoryTree(root);
    cout << "�����ٶ�����" << endl;
}
//���������ٷ���
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
//��������ǰ�����(�ǵݹ�)
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
//���������������(�ǵݹ�)
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
//�������ĺ������(�ǵݹ�)
void Binary_Tree::PostOrder()
{
    vector<pair<Tree_Node *, int>> S;
    Tree_Node *bt = root;
    while (bt != NULL || S.size())
    {
        //һֱ�������
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
//�������Ĳ������(�ǵݹ�)
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
//��������ǰ������ݹ鷽��
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
//��������ǰ������ݹ�ĵ��÷���
void Binary_Tree::PreOrder_Recursion()
{
    PreOrder_Recursion(root);
    cout << endl;
}
//����������������ݹ鷽��
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
//����������������ݹ�ĵ��÷���
void Binary_Tree::InOrder_Recursion()
{
    InOrder_Recursion(root);
    cout << endl;
}
//�������ĺ�������ݹ鷽��
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
//�������ĺ�������ݹ�ĵ��÷���
void Binary_Tree::PostOrder_Recursion()
{
    PostOrder_Recursion(root);
    cout << endl;
}
//�������Ĳ�������ݹ鷽��
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
//�������Ĳ�������ݹ�ĵ��÷���
void Binary_Tree::LevelOrder_Recursion()
{
    //���
    result.clear();
    //���ò�������ݹ�
    LevelOrder_Recursion(root, 1);
    //���
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
    //�ݹ��������:ab#d##c##
    cout<<"���Ա����㷨��"<<endl;
    //ǰ����� abdc
    tree.PreOrder_Recursion();
    //������� bdac
    tree.InOrder_Recursion();
    //������� dbca
    tree.PostOrder_Recursion();
    //������� abcd
    tree.LevelOrder_Recursion();
    cout<<endl;

    //�ǵݹ��������:ab#cd###ef#g###
    cout<<"���ԷǱ����㷨��"<<endl;
    //ǰ����� abcdefg
    tree.PreOrder();
    //������� bdcafge
    tree.InOrder();
    //������� dcbgfea
    tree.PostOrder();
    //������� abecfdg
    tree.LevelOrder();
    system("pause");
}