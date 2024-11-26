#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], c[N];
int n;

//  t中二分查找最后一个小于x的
int checkl(int x, int t[])
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (t[mid] < x)
            l = mid;
        else
            r = mid - 1;
    }
    if (t[l] >= x)
        return 0;
    return l;
}

//  t中二分查找第一个大于x的
int checkh(int x, int t[])
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (t[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }
    if (t[l] > x)
        return l;
    else
        return 0;
}
// 试试从b开始考虑
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    sort(c + 1, c + n + 1);
    long long ans = 0;
    for (int j = 1; j <= n; j++)
    {
        // a中最后一个比b[j]小的
        int i = checkl(b[j], a);
        // a中没有比b[j]小，j增加
        if (i == 0)
            continue;
        // c中第一个比b[j]大的
        int k = checkh(b[j], c);
        // c中没有比b[j]大，退出
        if (k == 0)
            break;
        // cout << "i:" << i << " j:" << j << " k:" << k << endl;
        ans += (long long)i * (n - k + 1);
    }
    cout << ans << endl;
    return 0;
}
// 超时做法，时间为n*logn*logn
// 从a开始的逐一循环+双指针，会超时
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(a, a + n + 1);
    sort(b, b + n + 1);
    sort(c, c + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 这里ab换成双指针应该就可以过了
        int fir = checkh(a[i], b);
        if (fir == 0)
            break;
        // 试试双指针
        for (int j = fir, k = 1; j <= n; j++)
        {
            // c小，增大
            while (k <= n && c[k] <= b[j])
                k++;

            // 循环出来后，仍然是c不大于b,此时后续所有j都不需要循环了
            if (k == n + 1)
            {
                break;
            }

            ans += n - k + 1;
        }

        // for (int j = fir; j <= n; j++)
        // {
        //     int k = check(b[j], c);
        //     if (k == 0)
        //         break;
        //     // cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
        //     ans += n - k + 1;
        // }
    }
    cout << ans << endl;
    return 0;
}