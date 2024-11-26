/*
此题差分的思路非常明显，不多说，简单说一下二分思路
如果出现订单不满足需求，那么在这个订单之前的订单都是满足需求的，在这个订单之后一定都是不满足的
所以我们可以二分查找第一个不满足需求的订单
*/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e6 + 10;
int n, m; // 天数，订单数
long long d[N];
int s[N], t[N];

long long room[N]; // 每天教室数
long long dir[N];

bool check(int mid)
{
    memset(dir, 0, sizeof(dir));
    for (int i = 1; i <= mid; i++)
    {
        dir[s[i]] += d[i];
        dir[t[i] + 1] -= d[i];
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += dir[i];
        if (sum > room[i]) // 向左边寻找
            return true;
    }
    return false; // 向右边寻找
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> room[i];
        // dir[i] = room[i] - room[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> d[i] >> s[i] >> t[i];
    }
    // 正常来说是{1,m}，但是如果一直没有找到，最后l=r，r==m，此情况和正好是最后一天不满足条件相同
    // 此时会和
    int l = 1, r = m + 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (r == m + 1)
        cout << 0 << endl;
    else
        cout << -1 << endl
             << r << endl;
    return 0;
}