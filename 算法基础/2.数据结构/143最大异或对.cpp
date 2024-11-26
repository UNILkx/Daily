#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 3100010;
int n;
int a[N];
int trie[M][2], idx;

void insert(int n)
{
    int p = 0;
    // 后面寻找从最高位开始，求最大时首先要做的就是看首位是否相同
    for (int i = 30; i >= 0; i--)
    {
        int u = n >> i & 1;
        if (!trie[p][u])
            trie[p][u] = ++idx;
        p = trie[p][u];
    }
}

int query(int n)
{
    // 输入当前要想异或的值，
    // 显然，从最高位置，应当选择与当前位相反的数，存在就顺着往下找，反之只能走另外一条

    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = n >> i & 1;
        if (trie[p][!u])
        {
            res = res + (1 << i);
            p = trie[p][!u];
        }
        else
            p = trie[p][u];
    }

    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, query(a[i]));
    cout << res << endl;
    return 0;
}