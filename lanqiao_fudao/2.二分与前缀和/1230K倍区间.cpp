#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int a[N], pad[N], res[N];

int main()
{
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pad[i] = (pad[i - 1] + a[i]) % k;

        // 首先明确 res[sum[i]] 表示的是sum[i]出现过的次数。
        // 举个例子，假设 sum[i] = 3，在后边的循环中，又出现了一个 sum[i] =3
        // 那么此时，这个“3”可以和前边出现过的所有的“3”分别构成一个K倍区间，
        // 前边的“3”一共出现过res[sum[i]] 次，
        // 所以 此时又新增了res[sum[i]]个K倍区间。

        // 再就是，这样一个模k相同的pad[i],数量求和是个1+2+...+n的等差数列,所以res[0]要单独加上0
        ans += res[pad[i]];
        res[pad[i]]++;
    }
    // 暴力,枚举区间长度1~n,感觉会超时

    cout << ans + res[0] << endl;
    return 0;
}