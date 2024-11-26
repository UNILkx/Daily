#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int e[N], ne[N], pe[N], idx;
int m;
string a;
int k, x;

// 下标为k的点的右边，插入x
void insert(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    pe[idx] = k;
    pe[ne[k]] = idx;
    ne[k] = idx;
    idx++;
}
// 删除第k节点
void remove(int k)
{
    ne[pe[k]] = ne[k];
    pe[ne[k]] = pe[k];
}

int main()
{
    cin >> m;
    // 初始化

    ne[0] = 1; // 头head
    pe[1] = 0; // 尾tail
    idx = 2;

    while (m--)
    {
        cin >> a;
        if (a == "L")
        {
            cin >> x;
            insert(0, x);
        }
        else if (a == "R")
        {
            cin >> x;
            insert(pe[1], x);
        }
        else if (a == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if (a == "IL")
        {
            cin >> k >> x;
            insert(pe[k + 1], x);
        }
        else if (a == "IR")
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }
    for (int i = ne[0]; i != 1; i = ne[i])
    {
        cout << e[i] << " ";
    }
    return 0;
}