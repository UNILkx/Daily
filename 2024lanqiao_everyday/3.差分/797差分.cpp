#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N]; // 从后面开始可以不省略空间

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
        a[i] = a[i] - a[i - 1];
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        a[l] += c;
        a[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i];
        cout << a[i] << ' ';
    }
    return 0;
}
