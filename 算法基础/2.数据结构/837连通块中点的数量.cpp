#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N], res[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i, res[i] = 1;
    while (m--)
    {
        string c;
        int a, b;
        cin >> c;
        if (c == "C")
        {
            cin >> a >> b;
            if (a == b || find(a) == find(b))
                continue;
            // 相比并查集多一步，加上根节点数组存放集合的数量
            res[find(b)] = res[find(a)] + res[find(b)];
            p[find(a)] = find(b);
        }
        else if (c == "Q1")
        {
            cin >> a >> b;
            if (a == b)
            {
                cout << "Yes" << endl;
                continue;
            }
            if (find(a) == find(b))
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
        else if (c == "Q2")
        {
            cin >> a;
            cout << res[find(a)] << endl;
        }
    }
    return 0;
}