#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n, k;
int a[N];

int countone(int x)
{
    int cnt = 0;
    while (x)
    {
        if (x & 1)
            cnt++;
        x >>= 1;
    }
    return cnt;
}
// 判断素数
bool isprimer(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void dfs()
{
    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        if (countone(i) == k)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    sum += a[j];
            }
            if (isprimer(sum))
                ans++;
        }
    }
    cout << ans << endl;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs();

    return 0;
}