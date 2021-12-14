#ifndef __BINARY_SORT_TREE_H
#include "Binary_Tree.h"
class SortTree : public BinaryTree
{
private:
    void CalASL(Node *, int &, int &, int);

public:
    SortTree();
    ~SortTree();
    ret_val CreateTree(vector<Datatype> &);
    ret_val DeleteNode(Datatype &);
    ret_val InsertNode(Datatype &);
    pair<double, double> CalASL();
    Node *SearchParentNode(Datatype &);
    Node *SearchNode(Datatype &);
};

#endif /*__BINARY_SORT_TREE_H*/