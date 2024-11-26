#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e4 + 10;

int n;
int a[N], b[N];

// 1往左，0往右
bool checkl(ll mid)
{
    for (int i = 1; i <= n; i++)
    {
        // mid小了
        if (a[i] / mid > b[i])
            return false;
        if (a[i] / mid < b[i])
            return true;
    }
    // 如果全部相同，说明在区间内，此时往左边找，找到最小的
    return true;
}

// 1往右，0往左
bool checkr(ll mid)
{
    for (int i = 1; i <= n; i++)
    {
        // mid小了
        if (a[i] / mid > b[i])
            return true;
        if (a[i] / mid < b[i])
            return false;
    }
    // 如果全部相同，说明在区间内，此时往右边找，找到最大的
    return true;
}

int main()
{
    cin >> n;
    ll mx = 1e9;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        mx = min(mx, (ll)a[i] / b[i]);
    }
    int st, ed;
    // 向左找
    int l = 1, r = mx;
    while (l < r)
    {
        ll mid = l + r >> 1;
        if (checkl(mid))
            r = mid;
        else
            l = mid + 1;
    }
    st = l;
    l = 1, r = mx;
    while (l < r)
    {
        ll mid = l + r + 1 >> 1;
        if (checkr(mid))
            l = mid;
        else
            r = mid - 1;
    }
    ed = l;
    cout << st << ' ' << ed << endl;
    return 0;
}
