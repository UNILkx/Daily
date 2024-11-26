// 并查集查看此文章：https://blog.csdn.net/raelum/article/details/128766206
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    // iota(st + 1, st + n + 1, 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'M')
        {
            // 将a的根节点指向b的根节点
            p[find(a)] = find(b);
        }
        else if (c == 'Q')
        {
            if (find(a) == find(b))
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
    }
    return 0;
}