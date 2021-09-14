#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *List_Init(int[], int);
void List_Expand(Node *);
void List_Print(Node *first);
int List_Delete(Node *first, int min, int max);
int main()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *first = List_Init(a, 8);
    cout << "扩展之前：\n";
    List_Print(first);
    List_Expand(first);
    cout << "扩展之后：\n";
    List_Print(first);
    List_Delete(first, 0, 7);
    cout << "删除之后：\n";
    List_Print(first);
    system("pause");
}
void List_Expand(Node *first)
{
    Node *temp, *p = first->next;
    while (p)
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = p->data;
        temp->next = p->next;
        p->next = temp;
        p = temp->next;
    }
}
Node *List_Init(int num[], int length)
{
    Node *first, *temp;
    first = (Node *)malloc(sizeof(Node));
    temp = first;
    for (int i = 0; i < length; i++)
    {
        temp->next = (Node *)malloc(sizeof(Node));
        temp = temp->next;
        temp->data = num[i];
    }
    temp->next = NULL;
    return first;
}
void List_Print(Node *first)
{
    Node *temp = first->next;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int List_Delete(Node *first, int min, int max)
{
    Node *p, *temp = first;
    if (min >= max)
    {
        cout << "最小值大于等于最大值\n";
        return 0;
    }
    while (temp->next)
    {
        p = temp->next;
        if (p->data < max && p->data > min)
        {
            temp->next = p->next;
            free(p);
        }
        else
        {
            temp = temp->next;
        }
    }
    return 1;
}