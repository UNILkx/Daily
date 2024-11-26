#include <iostream>

using namespace std;

const long long N = 1e6 + 10;
int n, m;
long long a[N]; // 原始数组
int tar;

int check(int tar)
{
    long long l = 1, r = n;
    while (l < r) // 向左边搜索
    {
        long long mid = l + r >> 1;
        if (a[mid] < tar)
            l = mid + 1;
        else
            r = mid;
    }
    if (a[l] != tar)
        return -1;
    return l;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> tar;
        cout << check(tar) << " ";
    }
    return 0;
}