#ifndef __TREE_H
//二叉排序树
#include <iostream>
#include <vector>
typedef int Datatype;
using namespace std;

struct Node
{
    Datatype data;
    Node *rchild, *lchild, *parent;
};
class SortTree
{
private:
    Node *root = NULL;

public:
    SortTree();
    SortTree(vector<Datatype> r);
    ~SortTree();
    void CreateTree(vector<Datatype> r);
    void Insert(Datatype data);
    void Delete(Datatype data);
    void Destory();
    Node *Search(Datatype data);
    int Level(Datatype data);
};
#endif /*__TREE_H*/
