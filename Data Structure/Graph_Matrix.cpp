//ͼ���ڽӾ���ʵ��
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
//ͼ�Ŀչ��췽�������ù�
Graph_Matrix::Graph_Matrix()
{
}
//ͼ���������������ù�
Graph_Matrix::~Graph_Matrix()
{
    DestoryGraph();
}
//ͼ�Ĺ��췽��
Graph_Matrix::Graph_Matrix()
{
    CreateGraph();
}
//����һ��ͼ
void Graph_Matrix::CreateGraph()
{
    
}

void Graph_Matrix::DestoryGraph()
{
    cout << "ͼ�ѱ�ɾ��" << endl;
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
