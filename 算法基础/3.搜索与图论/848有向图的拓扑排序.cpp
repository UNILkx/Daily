// 参考这个https://raelum.blog.csdn.net/article/details/129650604

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N]; // d入度
vector<int> ans;
void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

void topsort()
{
    queue<int> q;
    // 入度为0的点入队
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q.push(i);

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        // 入度为0的点加入答案队列
        ans.push_back(t);
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            //
            if (!--d[j])
                q.push(j);
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        // 入度增加
        d[y]++;
    }
    topsort();

    if (ans.size() == n)
        for (auto it : ans)
            cout << it << ' ';
    else
        cout << -1 << endl;
    return 0;
}