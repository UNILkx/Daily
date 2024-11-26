#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, L;
int c[N];

// 如果后面文章数大于等于当前的，往右找
bool check(int mid)
{
    int sum = 0, mark = L;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] >= mid)
            sum++;
        // 查找时，直接处理c[i]=mid-1的情况
        else if (mark && c[i] + 1 >= mid)
            sum++, mark--;
    }
    // sum>=mid，说明选小了，往右边找
    return sum >= mid;
}

int main()
{
    cin >> n >> L;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    // 引用次数降序排序
    sort(c, c + n + 1);
    // 找到当前h
    // mid越大，c[mid]越大，往右边找
    // 我显然想找到相等的最左边的
    int l = 0, r = 1e5;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        // 往右边找
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    // 1~h是大于等于h的
    cout << l;

    return 0;
}