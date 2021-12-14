#ifndef __MODULES_H
#define __MODULES_H
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
typedef int Datatype;
//链表结点
struct Node
{
    int num;
    Datatype data;
    Node *front, *back;
};

//初始化密码顺序表
void CreatePassList();
//初始化出队队列
void CreateQueue();
//读取数据
void ReadData();
//初始化数据
void Init();
//删除某个结点
void Delete(Node *);
//查找结点
Node *Find(Node *, int, int);
//解决问题
void Solve();
//输出队列
void Displayresult();
//输出每个人的密码
void Displaypass();
//释放内存
void Releasememory();

#endif /*__MODULES_H*/
