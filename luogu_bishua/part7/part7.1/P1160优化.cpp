/*此部分为P1160题的解答
 由于链表的查询是O(N)级别，在循环输入的情况下，时间复杂度为O(N^2)，所以需要优化
 采用数组模拟的方式查找时间就为O(1)，整体时间复杂度为O(N)，有效简化了时间复杂度。
  */

#include <iostream>

using namespace std;

// 注意N,M是[0,1e5].
struct List
{
    int prior;
    int next;
} list[100005]; // 数组类双向链表
// 节点被删除则prior和next都为-1
int N, M;

int main()
{
    cin >> N;
    int head = 1;
    list[1].prior = 0;
    list[1].next = 0;
    // insert操作
    int tar, dir;
    for (int i = 2; i <= N; i++)
    {
        cin >> tar >> dir;
        if (dir == 0) // 插入左边
        {
            list[i].next = tar;       // 插入节点指向目标节点
            if (list[tar].prior == 0) // 目标节点的前驱节点为0
            {
                list[i].prior = 0; // 成为新的首元节点
                head = i;          // 更新头结点
            }
            else
            {
                list[i].prior = list[tar].prior; // 插入节点的前驱节点指向目标节点的前驱节点
                list[list[tar].prior].next = i;  // 目标节点的前驱节点的后继节点指向i
            }
            list[tar].prior = i; // 目标节点的前驱节点指向插入节点
        }
        else // 插入右边
        {
            list[i].prior = tar;     // 插入节点指向目标节点
            if (list[tar].next == 0) // 目标节点的后继节点为0
            {
                list[i].next = 0; // 成为新的尾元节点
            }
            else
            {
                list[i].next = list[tar].next;  // 插入节点的后继节点指向目标节点的后继节点
                list[list[tar].next].prior = i; // 目标节点的后继节点的前驱节点指向i
            }
            list[tar].next = i; // 目标节点的后继节点指向插入节点
        }
    }

    // delete操作
    cin >> M;
    while (M--)
    {
        cin >> tar;
        if (list[tar].prior == -1 && list[tar].next == -1) // 该节点已删除
            continue;
        else if (list[tar].prior == 0 && list[tar].next != 0) // 删除首节点
        {
            list[list[tar].next].prior = 0;
            head = list[tar].next;
            list[tar].prior = -1;
            list[tar].next = -1;
            continue;
        }
        else if (list[tar].prior != 0 && list[tar].next == 0) // 删除尾结点
        {
            list[list[tar].prior].next = 0;
            list[tar].prior = -1;
            list[tar].next = -1;
            continue;
        }
        else // 删除中间节点
        {
            list[list[tar].prior].next = list[tar].next;
            list[list[tar].next].prior = list[tar].prior;
            list[tar].prior = -1;
            list[tar].next = -1;
            continue;
        }
    }
    for (int i = head; i != 0; i = list[i].next)
    {
        cout << i << " ";
    }
    return 0;
}