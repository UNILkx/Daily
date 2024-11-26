#include <iostream>
#include <cstdio>
using namespace std;

#define h first
#define w second

const int N = 1e5 + 10;

int n, k;
pair<int, int> K[N];

// 1向右找,
bool check(int mid)
{
    int num = 0; // 一共有多少块
    // 计算每一块可以切出多少个
    for (int i = 0; i < n; i++)
    {
        if ((K[i].h / mid) > 0 && (K[i].w / mid) > 0)
        {
            num += (K[i].h / mid) * (K[i].w / mid);
        }
    }
    // cout<<num<<endl;

    if (num >= k) // 说明划分的小了，往右找
        return 1;
    return 0;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &K[i].h, &K[i].w);
    }
    int l = 1, r = 1e5;
    while (l < r)
    {
        // 向右找最大边长
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}