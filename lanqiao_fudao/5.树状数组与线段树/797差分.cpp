#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], psb[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psb[i] = a[i] - a[i - 1];
    }
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        psb[l] += c;
        psb[r + 1] -= c;
    }
    int res = a[0];

    for (int i = 1; i <= n; i++)
    {
        res += psb[i];
        cout << res << ' ';
    }
    return 0;
}