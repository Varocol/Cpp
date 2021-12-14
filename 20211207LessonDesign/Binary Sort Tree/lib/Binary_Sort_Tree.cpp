#include "Binary_Sort_Tree.h"

/**
  * @brief  二叉排序树默认构造方法
  * @param  None
  * @retval None
  */
SortTree::SortTree()
{
}

/**
  * @brief  二叉排序树析构方法
  * @param  None
  * @retval None
  */
SortTree::~SortTree()
{
}

/**
  * @brief  二叉排序树创建方法
  * @param  Data        数据集
  * @retval None
  */
ret_val SortTree::CreateTree(vector<Datatype> &Data)
{
  for (Datatype data : Data)
  {
    ret_val Status = InsertNode(data);
    if (Status == Success)
    {
      cout << "结点 " << data << " 插入成功!" << endl;
    }
    else if (Status == Node_Exsit)
    {
      //检测到重复数据
      cout << "结点 " << data << " 重复输入!" << endl;
    }
  }
  return Success;
}

/**
  * @brief  二叉排序树删除结点方法
  * @param  data        结点数据
  * @retval None
  */
ret_val SortTree::DeleteNode(Datatype &data)
{
  // 寻找data结点
  Node *parent = SearchParentNode(data);
  Node *temp = SearchNode(data);
  Node *work = temp;
  Node *front = temp;
  if (temp == NULL)
  {
    // 找不到该结点
    return Node_Not_Found;
  }

  //减少结点数
  count--;
  //删除结点,并用直接前驱代替
  //如果左子树不为空,选择左子树,否则选右子树
  work = temp->left;
  while (work != NULL)
  {
    if (work->right == NULL)
    {
      break;
    }
    front = work;
    work = work->right;
  }

  //左子树找不到,找右子树
  if (work == NULL)
  {
    work = temp->right;
    while (work != NULL)
    {
      if (work->left == NULL)
      {
        break;
      }
      front = work;
      work = work->left;
    }
  }

  //替换结点
  if (work != NULL)
  {
    temp->data = work->data;
    temp = work->left == NULL ? work->right : work->left;
    if (work == front->left)
    {
      front->left = temp;
    }
    else
    {
      front->right = temp;
    }
    delete work;
  }
  //如果是末尾结点
  else
  {
    if (parent->left == temp)
    {
      parent->left = NULL;
    }
    else
    {
      parent->right = NULL;
    }
    if (root == temp)
    {
      root = NULL;
    }
    delete temp;
  }
  return Success;
}

/**
  * @brief  二叉排序树插入结点方法
  * @param  data        结点数据
  * @retval None
  */
ret_val SortTree::InsertNode(Datatype &data)
{
  //增加结点
  count++;
  //若根为空
  if (root == NULL)
  {
    root = CreateNode(data);
    return Success;
  }
  //根不为空,则直接插入
  Node *temp = root;
  while (temp != NULL)
  {
    if (data < temp->data)
    {
      if (temp->left == NULL)
      {
        temp->left = CreateNode(data);
        return Success;
      }
      temp = temp->left;
    }
    else if (data > temp->data)
    {
      if (temp->right == NULL)
      {
        temp->right = CreateNode(data);
        return Success;
      }
      temp = temp->right;
    }
    else
    {
      count--;
      return Node_Exsit;
    }
  }
  return Success;
}

/**
  * @brief  二叉排序计算ASL方法
  * @param  data        结点数据
  * @retval 一对double,前者是查找成功的ASL,后者是失败的ASL
  */
pair<double, double> SortTree::CalASL()
{
  int SUCC_SUM = 0, FAIL_SUM = 0;
  CalASL(root, SUCC_SUM, FAIL_SUM, 1);
  return pair<double, double>(SUCC_SUM * 1.0 / Size(), FAIL_SUM * 1.0 / (Size() + 1));
}

/**
  * @brief  二叉排序计算ASL方法
  * @param  root        结点数据
  * @param  SUCC_SUM    成功的总和
  * @param  FAIL_SUM    失败的总和
  * @param  level       结点所在层数
  * @retval None
  */
void SortTree::CalASL(Node *root, int &SUCC_SUM, int &FAIL_SUM, int level)
{
  if (root == NULL)
  {
    FAIL_SUM += level;
    return;
  }
  SUCC_SUM += level;
  CalASL(root->left, SUCC_SUM, FAIL_SUM, level + 1);
  CalASL(root->right, SUCC_SUM, FAIL_SUM, level + 1);
}

/**
  * @brief  二叉排序树寻找双亲结点方法
  * @param  data        结点数据
  * @retval result      找到则返回结点地址,否则返回NULL
  */
Node *SortTree::SearchParentNode(Datatype &data)
{
  Node *result = root, *parent = result;
  while (result != NULL)
  {
    if (result->data < data)
    {
      parent = result;
      result = result->right;
    }
    else if (result->data > data)
    {
      parent = result;
      result = result->left;
    }
    else
    {
      break;
    }
  }
  return parent;
}

/**
  * @brief  二叉排序树寻找结点方法
  * @param  data        结点数据
  * @retval result      找到则返回结点地址,否则返回NULL
  */
Node *SortTree::SearchNode(Datatype &data)
{
  Node *result = root;
  while (result != NULL)
  {
    if (result->data < data)
    {
      result = result->right;
    }
    else if (result->data > data)
    {
      result = result->left;
    }
    else
    {
      break;
    }
  }
  return result;
}
