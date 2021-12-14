#ifndef __MODULES_H
#include <iostream>
#include <vector>
#include "Binary_Sort_Tree.h"
using namespace std;

//指令枚举
typedef enum
{
    CMD_CreateTree,
    CMD_DestoryTree,
    CMD_DeleteNode,
    CMD_InsertNode,
    CMD_SearchNode,
    CMD_PreorderOutput,
    CMD_InorderOutput,
    CMD_PostorderOutput,
    CMD_LevelorderOutput,
    CMD_TreeSizeOutput,
    CMD_CalASL,
    CMD_About,
    CMD_Quit
} CMD_CODE;

//程序运行函数
void Pro_Run();
//程序调度函数
void Fun_Run();
//正确输入指令
void Code_Read();
//正确输入数字
void Num_Read(int &);

//菜单
void Menu();
//创建二叉排序树
void CreateTree();
//销毁二叉排序树
void DestoryTree();
//打印二叉排序树
void DisplayTree();
//删除二叉排序树结点
void DeleteNode();
//插入二叉排序树结点
void InsertNode();
//查找二叉排序树结点
void SearchNode();
//前序输出二叉排序树
void PreorderOutput();
//中序输出二叉排序树
void InorderOutput();
//后序输出二叉排序树
void PostorderOutput();
//层序输出二叉排序树
void LevelorderOutput();
//输出二叉排序树大小
void TreeSizeOutput();
//计算二叉排序树的ASL
void CalASL();
//关于程序
void About();
//退出程序
void Quit();
#endif /*__MODULES_H*/