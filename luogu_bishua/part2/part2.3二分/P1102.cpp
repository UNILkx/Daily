#include <iostream>
#include <algorithm>
using namespace std;

long long N, C;
int a[200005];
long long st, ans;
int main()
{
    cin >> N >> C;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    // 排序后，可能一个数出现多次，需要向左向右两次二分找到区间范围

    // 升序
    sort(a + 1, a + N + 1);

    for (int i = 1; i <= N; i++)
    {
        // 当前为A，需要找到B满足A-B=C;
        int l = i + 1, r = N;

        // 应该先找到第一个，所以向左
        while (l < r)
        {
            int mid = r + l >> 1;
            if (a[mid] - a[i] >= C) // 还在左边
                r = mid;
            else
                l = mid + 1;
        }
        // 出来后，l==r，但不知道是否找到了

        if (a[l] - a[i] == C) // 找到了，继续找
            st = l;
        else
            continue;
        // 下面找最右边出现的
        l = i + 1, r = N;
        while (l < r) // 向右
        {
            int mid = l + r + 1 >> 1;
            if (a[mid] - a[i] <= C) // 还在右边
                l = mid;
            else
                r = mid - 1;
        }
        if (a[l] - a[i] == C) // 找到了
            ans += l - st + 1;
    }
    cout << ans << endl;
    return 0;
}