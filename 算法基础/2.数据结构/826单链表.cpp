#include <iostream>
#include <string>
using namespace std;
const int N = 1e5 + 10;
// 头结点，节点i，下一个节点，当前用到哪个点
int head, e[N], ne[N], idx;

int m;

void head_insert(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void del_k(int k)
{
    ne[k] = ne[ne[k]];
}

void insert_k(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

int main()
{
    cin >> m;
    char a;
    int k, x;
    int len_a = 0;

    // 单链表初始化
    head = -1;
    idx = 0;

    while (m--)
    {
        cin >> a;

        if (a == 'H') // 表头插入,H x
        {
            cin >> x;
            head_insert(x);
        }
        else if (a == 'D') // 删除操作,D k
        {
            cin >> k;
            if (!k)
                head = ne[head];
            del_k(k - 1);
        }
        else if (a == 'I') // 插入操作,I k x
        {
            cin >> k >> x;
            insert_k(k - 1, x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    return 0;
}