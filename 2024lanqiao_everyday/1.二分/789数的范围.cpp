#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[100010];

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        int k, st, ed;
        cin >> k;
        // 往左找
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[mid] >= k)
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] != k)
        {
            cout << "-1 -1" << endl;
            continue;
        }
        else
        {
            st = l - 1;
            l = 1, r = n;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (a[mid] <= k)
                    l = mid;
                else
                    r = mid - 1;
            }
            ed = l - 1;
            cout << st << ' ' << ed << endl;
        }
    }
    return 0;
}