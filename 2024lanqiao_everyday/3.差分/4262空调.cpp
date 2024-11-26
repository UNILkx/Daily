#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int p[N], t[N], a[N], psb[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i]; // 期望温度
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i]; // 当前温度
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        a[i] = p[i] - t[i];       // 还需a[i]温度到期望温度
        psb[i] = a[i] - a[i - 1]; // 存放差分,最后需要差分数组为0
        // 区间的操作体现到差分数组，则是操作1：一个+1另一个-1:；操作2：一个数+1/-1
        // 使最后结果为0，必然是正数和负数和相同，所以下使用操作2，再操作1.
        if (psb[i] < 0)
            x += abs(psb[i]);
        else
            y += abs(psb[i]);
    }
    // 结果，当前[i,j]可连续区间需要次数

    int res = max(x, y);
    cout << res << endl;
    return 0;
}