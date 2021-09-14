#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void List_Expand(Node *);
Node *List_Init(int[], int);
void List_Print(Node *first);
int main()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node *first = List_Init(a,8);
    cout<<"扩展之前：\n";
    List_Print(first);
    List_Expand(first);
    cout<<"扩展之后：\n";
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
    while(temp)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}