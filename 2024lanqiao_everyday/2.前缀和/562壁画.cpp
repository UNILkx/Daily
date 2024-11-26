#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 10;

int n, t;
int a[N], pre[N];

int main()
{
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        memset(a, 0, sizeof(a));
        memset(pre, 0, sizeof(pre));
        cin >> n;
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++)
        {
            a[i] = s[i - 1] - '0';
            pre[i] = pre[i - 1] + a[i];
        }
        int res = 0;
        // 向上取整
        // 找区间的时候，区间长度为n+1>>1,从下标1开始，则从n+1>>1+1结束
        for (int i = (n + 1) / 2; i <= n; i++)
        {
            res = max(res, pre[i] - pre[i - (n + 1) / 2 - 1]);
        }
        // for (int i = 1; i <= (n + 1) / 2 + 1; i++)
        // {
        //     res = max(res, pre[i + ((n + 1) / 2) - 1] - pre[i - 1]);
        // }
        cout << "Case #" << j << ": " << res << endl;
    }
    return 0;
}