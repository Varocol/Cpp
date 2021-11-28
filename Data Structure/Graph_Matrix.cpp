//图的邻接矩阵实现
#include <iostream>
#define MaxSize 10
typedef string DataType;
using namespace std;

class Graph_Matrix
{
private:
    DataType vertex[MaxSize];
    int edge[MaxSize][MaxSize];
    int vertexNum, edgeNum;

public:
    ~Graph_Matrix();
    Graph_Matrix();
    void CreateGraph();
    void DestoryGraph();
    void DFTraverse();
    void BFTraverse();
};
//图的空构造方法，不用管
Graph_Matrix::Graph_Matrix()
{
}
//图的析构方法，不用管
Graph_Matrix::~Graph_Matrix()
{
    DestoryGraph();
}
//图的构造方法
Graph_Matrix::Graph_Matrix()
{
    CreateGraph();
}
//创建一个图
void Graph_Matrix::CreateGraph()
{
    
}

void Graph_Matrix::DestoryGraph()
{
    cout << "图已被删除" << endl;
}

void Graph_Matrix::DFTraverse()
{
}
void Graph_Matrix::BFTraverse()
{
}

int main()
{
}
