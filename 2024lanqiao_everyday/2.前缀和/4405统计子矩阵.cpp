#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m, k;
int pre[N][N];

int main()
{

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> pre[i][j];
            // 只需要统计列的前缀和
            pre[i][j] += pre[i - 1][j];
        }

    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int l = 1, r = 1, sum = 0; r <= m; r++)
            {
                sum += pre[j][r] - pre[i - 1][r];
                while (sum > k)
                {
                    sum -= pre[j][l] - pre[i - 1][l];
                    l++;
                }
                res += r - l + 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}

// 超时做法
int check(int x, int y)
{
    int sum = 0;
    // 这里的优化目标应当是，
    // 一旦(i-x,j-y),(i,j)这个矩阵和大于k，那么以(i-x,j-y)开始的，x1>x||y1>y的都不成立
    for (int i = x; i <= n; i++)
    {
        for (int j = y; j <= m; j++)
        {
            int ans = pre[i][j] - pre[i - x][j] - pre[i][j - y] + pre[i - x][j - y];
            // 此时应当做标记
            if (ans > k)
            {
                continue;
            }

            sum++;
        }
    }
    return sum;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> pre[i][j];
            // 前缀和数组,开一个就好了
            pre[i][j] += pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
        }
    }
    long long res = 0;
    // 子矩阵为 i*j大小
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res += check(i, j);
        }
    }
    return 0;
}
