/*
这个是洛谷链表的一个典型题目，涉及到查找、插入和删除操作，显然双链表是比较好的
需要注意：
1.首元节点prior指针和尾元结点的next指针为null
2.插入时，头指针需要更新指向新的尾元结点
3.删除时，不同节点处理方式不同，删除首元节点需要更新头指针，删除尾元结点需要更新新节点的next
4.对于2和3，使用的函数需要传递地址过去，这样才能修改
5.执行节点的插入和删除时，注意操作顺序，先修改新节点的指针，再修改原节点的指针

由于题目中设计的操作较多，纯粹的双链表构造，其时间复杂度为O(n^2)，所以可以使用链表数组查找的方式优化，该部分内容放到P1160优化.cpp中
*/

#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int mask[100005]; // 记录是否删除

typedef struct List
{
    int num;
    List *prior;
    List *next;
} list; // 双向链表

void list_insert(List *&L, int tar, int dir, int n)
{
    List *p = L;
    while (p != NULL && p->num != tar)
    {
        p = p->next;
    }
    // cout << "find p->num:" << p->num << " and tar: " << tar << endl;
    list *q = new list;
    q->num = n;
    if (dir == 0) // insert left
    {
        q->next = p;
        if (p != NULL && p->prior != NULL) // 不是首元节点
        {
            p->prior->next = q;
            q->prior = p->prior;
            p->prior = q;
        }
        else if (p != NULL && p->prior == NULL) // 是首元节点
        {
            q->prior = NULL;
            p->prior = q; // 别忘了这一步
            L = q;
        }
    }
    else if (dir == 1) // insert right
    {
        q->prior = p;
        if (p != NULL && p->next != NULL)
        {
            q->next = p->next;
            p->next->prior = q;
        }
        else
        {
            q->next = NULL;
        }
        p->next = q;
    }
    return;
}

void list_delete(List *&L, int n)
{
    List *p = L;
    while (p->num != n)
    {
        p = p->next;
    }
    // cout << "find p->num:" << p->num << " and tar: " << n << endl;
    if (p->prior != NULL && p->next != NULL) // 不是唯一节点
    {
        p->prior->next = p->next;
        p->next->prior = p->prior;
        delete p;
    }
    else if (p->prior == NULL && p->next != NULL) // 删除首元节点
    {
        p->next->prior = NULL;
        L = p->next; // 头结点指向新的首元节点
        delete p;
    }
    else if (p->prior != NULL && p->next == NULL) // 删除尾元节点
    {
        p->prior->next = NULL;
        delete p;
    }
    else if (p->prior == NULL && p->next == NULL) // 删除唯一节点
    {
        L = NULL;
        delete p;
    }

    return;
}

int main()
{
    List *head = new list;
    head->num = 1;
    head->prior = NULL;
    head->next = NULL;

    List *p = head;

    cin >> N;
    int tar, dir;
    for (int i = 2; i <= N; i++)
    {
        cin >> tar >> dir;
        // 这里需要传入head节点地址，因为首插时head节点可能会改变
        list_insert(head, tar, dir, i);
    }
    // for (p = head; p != NULL; p = p->next)
    // {
    //     cout << p->num << endl;
    // }
    // cout << "----------------" << endl;
    cin >> M;
    memset(mask, 1, (N + 1) * sizeof(int));
    int n;
    while (M--)
    {
        cin >> n;
        if (mask[n])
        {
            mask[n] = 0;
            list_delete(head, n);
        }
        else
            continue;
    }
    for (p = head; p != NULL; p = p->next)
    {
        cout << p->num << " ";
    }
    return 0;
}