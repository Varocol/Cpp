#ifndef __BINARY_TREE_H
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef int Datatype;

typedef enum
{
    Success,
    Node_Not_Found,
    Node_Exsit
} ret_val;

//链表结点
struct Node
{
    //数据域
    Datatype data;
    //左右孩子指针域
    Node *left, *right;
};

//二叉树的基类
class BinaryTree
{
    friend class SortTree;

private:
    void DestoryTree(Node *);
    void Preorder(Node *, vector<Datatype> &);
    void Inorder(Node *, vector<Datatype> &);
    void Postorder(Node *, vector<Datatype> &);
    int count = 0;
    int fail_count;
    Node *root = NULL;

public:
    BinaryTree();
    ~BinaryTree();
    virtual ret_val CreateTree(vector<Datatype> &) = 0;
    ret_val DestoryTree();
    vector<Datatype> Preorder();
    vector<Datatype> Inorder();
    vector<Datatype> Postorder();
    vector<Datatype> Levelorder();
    Node *CreateNode(Datatype &);
    virtual ret_val DeleteNode(Datatype &) = 0;
    virtual ret_val InsertNode(Datatype &) = 0;
    virtual Node *SearchParentNode(Datatype &) = 0;
    virtual Node *SearchNode(Datatype &) = 0;
    int Size();
    bool Empty();
};

#endif /*__BINARY_TREE_H*/
