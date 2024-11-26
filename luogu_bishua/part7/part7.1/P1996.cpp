#include <iostream>

using namespace std;

typedef struct Josep
{
    int key;
    Josep *prior;
    Josep *next;
} Josep;

int main()
{
    int n, m;
    cin >> n >> m;
    Josep *head = new Josep;
    head->key = 1;
    head->prior = head;
    head->next = head;
    Josep *p = head;
    for (int i = 2; i <= n; i++)
    {
        Josep *q = new Josep;
        // 新加入的节点的值是i
        q->key = i;
        // 新加入的节点的前驱是p，后继是p的后继
        q->prior = p;
        // 新加入的节点的后继是p的后继
        q->next = p->next;
        // 修改p的后继的前驱为q，必须在修改p的后继之前
        p->next->prior = q;
        // 修改p的后继为q
        p->next = q;
        p = q;
    }
    p = head;
    while (p->next != p)
    {
        for (int i = 1; i < m; i++)
        {
            p = p->next;
        }
        // 删除p的后继
        p->prior->next = p->next;
        //  修改p的后继的前驱为p的前驱
        p->next->prior = p->prior;
        // 输出p的后继的值
        cout << p->key << " ";

        p = p->next;
    }
    cout << p->key << endl;
    return 0;
}