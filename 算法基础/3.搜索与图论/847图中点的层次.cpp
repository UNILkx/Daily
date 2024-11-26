#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;

int n, m;
int e[N], ne[N], h[N], idx;
int dis[N]; // 存放距离
int st[N];  // 标记是否遍历

// 使用头插法，b插入a链表头部
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    // 距离初始化为无穷大
    memset(dis, 0x3f, sizeof(dis));

    queue<int> q;
    q.push(1);
    // 从1号节点出发，距离为0
    dis[1] = 0;
    st[1] = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        // 遍历链表，对应操作是bfs图
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            // 点没去过
            if (!st[j])
            {
                dis[j] = dis[t] + 1;
                q.push(j);
                st[j] = 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    // 初始化每个节点为空，没有后继
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    bfs();
    cout << (dis[n] == 0x3f3f3f3f ? -1 : dis[n]) << endl;
    return 0;
}