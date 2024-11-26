#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int n;

// h是邻接表的头结点构成的，e，ne是结点指向的下一个结点
int h[N], e[M], ne[M], idx;
bool st[N]; // 标记是否选到
int ans;

// 点b和点a有边，头插法，b插入a链表头部
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 返回以u为根的子树中点的数量
int dfs(int u)
{
    // 标记该点访问了
    st[u] = 1;
    // i遍历链表头
    int sum = 1, res = 0;
    // sum存放以u为根的树的点的个数包括u，res表示当前连通块点数最大值
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        // 该节点还未访问，深搜得到子树点的数目
        if (!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}
int main()
{
    memset(h, -1, sizeof(h));
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}