#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int h[N], w[N];

bool check(int mid)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (h[i] / mid && w[i] / mid)
        {
            sum += (h[i] / mid) * (w[i] / mid);
        }
    }
    // 总数大了，说明mid小了，向右边找
    if (sum >= k) // 等号都是排除相等情况
        return false;
    else
        return true;
}

int main()
{
    cin >> n >> k; // n块巧克力，k个人
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i] >> w[i];
    }
    int l = 1, r = 1e5;
    while (l < r)
    {
        // 边长大，向右边找
        int mid = l + r + 1 >> 1;
        // 向左找
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l;
    return 0;
}