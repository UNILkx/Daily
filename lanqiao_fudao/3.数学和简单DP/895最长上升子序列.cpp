#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int a[N];
// 转移状态，f[i]表示以a[i]结尾的最大的上升子序列长度
// f[i]=max(f[i],f[j]+1)

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> f(n + 10, 1);
    // int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            // a[i]前有a[j]小,选择加入
            if (a[j] < a[i])
            {
                // 循环中，不断比较a[j]加入后最大的序列长度
                f[i] = max(f[i], f[j] + 1);
            }
        }
        // ans = max(ans, f[i]);
    }
    auto ans = max_element(f.begin(), f.end());
    cout << *ans << endl;

    return 0;
}
