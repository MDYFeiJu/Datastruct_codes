#include <bits/stdc++.h>
using namespace std;

// 结构体定义
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 初始化链表头
LinkList InitLinkList()
{
    LinkList p = (LinkList)malloc(sizeof(LNode));
    p->next = NULL;
    return p;
}

// 头插法插入数据
bool InsertFromHead(LinkList ls, int x)
{
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = ls->next;
    ls->next = s;
    return true;
}
// 尾插法插入数据
bool InsertFromTail(LinkList ls, int x)
{
    LNode *p = ls;
    while (p->next != NULL)
    {
        p = p->next;
    }
    LNode *q = (LNode *)malloc(sizeof(LNode));
    q->data = x;
    q->next = p->next;
    p->next = q;
    return true;
}

// 输出链表的长度
int length(LinkList ls)
{
    LNode *p = ls;
    int count = 0;
    while (p->next != NULL)
    {
        count += 1;
        p = p->next;
    }
    return count;
}
// 寻找链表中第一个对应数字的位序
int FindNumFirstIndex(LinkList ls, int num)
{
    int count = 0;
    LNode *p = ls;
    while (p != NULL)
    {
        if (p->data == num)
        {
            return count;
        }
        count += 1;
        p = p->next;
    }
    return -1;
}

bool DeleteNumByIndex(LinkList ls, int index)
{
    if (index == -1 || index > length(ls))
    {
        return false;
    }
    int count = 0;
    LNode *p = ls;
    while (count < index - 1)
    {
        p = p->next;
        count += 1;
    }
    LNode *q = p->next;
    p->next = p->next->next;
    free(q);
    return true;
}

// 输出链表的数据
void PrintLinkList(LinkList ls)
{
    LNode *s = ls;
    while (s->next != NULL)
    {
        s = s->next;
        cout << s->data << endl;
    }
}

int main()
{
    LinkList Ls1 = InitLinkList();
    int x;
    for (int i = 0; i < 3; i++)
    {
        // cin >> x;
        InsertFromTail(Ls1, i + 1);
    }

    int i = FindNumFirstIndex(Ls1, 1);
    cout << i << endl;
    bool flag = DeleteNumByIndex(Ls1, i);
    cout << flag << endl;
    PrintLinkList(Ls1);
    return 0;
}