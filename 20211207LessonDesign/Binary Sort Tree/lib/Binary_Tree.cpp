#include "Binary_Tree.h"

/**
  * @brief  二叉树默认构造方法
  * @param  None
  * @retval None
  */
BinaryTree::BinaryTree()
{
}

/**
  * @brief  二叉树析构方法
  * @param  None
  * @retval None
  */
BinaryTree::~BinaryTree()
{
  if (root != NULL)
  {
    DestoryTree();
  }
}

/**
  * @brief  销毁二叉树调用方法
  * @param  None
  * @retval 如果树为空则返回树已存在,否则返回成功
  */
ret_val BinaryTree::DestoryTree()
{
  DestoryTree(root);
  //重置根结点
  root = NULL;
  //重置树的结点数
  count = 0;
  return Success;
}

/**
  * @brief  销毁二叉树方法
  * @param  root        二叉树的根结点
  * @retval None
  */
void BinaryTree::DestoryTree(Node *root)
{
  if (root != NULL)
  {
    DestoryTree(root->left);
    DestoryTree(root->right);
    delete root;
  }
}

/**
  * @brief  二叉树的前序遍历调用方法
  * @param  None
  * @retval result      二叉树前序遍历结果集
  */
vector<Datatype> BinaryTree::Preorder()
{
  vector<Datatype> result;
  Preorder(root, result);
  return result;
}

/**
  * @brief  二叉树的前序遍历方法
  * @param  root        二叉树的根结点
  * @param  order       二叉树前序遍历结果集
  * @retval None
  */
void BinaryTree::Preorder(Node *root, vector<Datatype> &order)
{
  if (root != NULL)
  {
    order.push_back(root->data);
    Preorder(root->left, order);
    Preorder(root->right, order);
  }
}

/**
  * @brief  二叉树的中序遍历调用方法
  * @param  None
  * @retval result      二叉树中序遍历结果集
  */
vector<Datatype> BinaryTree::Inorder()
{
  vector<Datatype> result;
  Inorder(root, result);
  return result;
}

/**
  * @brief  二叉树的中序遍历方法
  * @param  root        二叉树的根结点
  * @param  order       二叉树中序遍历结果集
  * @retval None
  */
void BinaryTree::Inorder(Node *root, vector<Datatype> &order)
{
  if (root != NULL)
  {
    Inorder(root->left, order);
    order.push_back(root->data);
    Inorder(root->right, order);
  }
}

/**
  * @brief  二叉树的后序遍历调用方法
  * @param  None
  * @retval result      二叉树后序遍历结果集
  */
vector<Datatype> BinaryTree::Postorder()
{
  vector<Datatype> result;
  Postorder(root, result);
  return result;
}

/**
  * @brief  二叉树的后序遍历方法
  * @param  root        二叉树的根结点
  * @param  order       二叉树后序遍历结果集
  * @retval None
  */
void BinaryTree::Postorder(Node *root, vector<Datatype> &order)
{
  if (root != NULL)
  {
    Postorder(root->left, order);
    Postorder(root->right, order);
    order.push_back(root->data);
  }
}

/**
  * @brief  二叉树的层序遍历方法
  * @param  None
  * @retval result      二叉树层序遍历结果集
  */
vector<Datatype> BinaryTree::Levelorder()
{
  vector<Datatype> result;
  queue<Node *> order;
  order.push(root);
  while (order.size())
  {
    if (order.front()->left != NULL)
    {
      order.push(order.front()->left);
    }
    if (order.front()->right != NULL)
    {
      order.push(order.front()->right);
    }
    result.push_back(order.front()->data);
    order.pop();
  }
  return result;
}

/**
  * @brief  二叉树创建结点
  * @param  data        结点数据
  * @retval 二叉树结点
  */
Node *BinaryTree::CreateNode(Datatype &data)
{
  Node *temp = new Node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

/**
  * @brief  二叉树获取结点个数方法
  * @param  None
  * @retval True or False
  */
int BinaryTree::Size()
{
  return count;
}

/**
  * @brief  二叉树判空方法
  * @param  None
  * @retval True or False
  */
bool BinaryTree::Empty()
{
  return root == NULL && count == 0;
}