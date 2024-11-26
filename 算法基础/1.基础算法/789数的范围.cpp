#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e5 + 5;
int n, q;
int a[N];

int main()
{
    scanf("%d%d", &n, &q);
    // 输入已经是升序
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int l, r;
    while (q--)
    {
        int tar;
        scanf("%d", &tar);
        l = 0, r = n - 1;
        // 先左搜，找到起始位置（第一个出现的位置），
        // 如果没找到(后面也不会有)直接输出-1-1
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= tar) // 还在左边
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] != tar)
        {
            printf("-1 -1\n");
            continue;
        }
        else
            printf("%d ", l);
        // 再右搜，找到终止位置（最后一个出现的位置）
        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= tar) // 还在右边
                l = mid;
            else
                r = mid - 1;
        }
        printf("%d\n", l);
    }

    return 0;
}