#ifndef __MODULES_H
#define __MODULES_H
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//初始化密码顺序表
void CreatePassList();
//初始化出队队列
void CreateQueue();
//读取数据
void ReadData();
//初始化数据
void Init();
//解决问题
void Solve();
//输出队列
void Displayresult();
//输出每个人的密码
void Displaypass();
//释放内存
void Releasememory();

#endif /*__MODULES_H*/
