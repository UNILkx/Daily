#include <iostream>

using namespace std;

const int MOD = 1000000007;
const int N = 55;
const int M = 15;

int n, m, k;
int martix[N][N];

int ans;

// 用f[i][j][k][c]表示转移方程的状态。
// 表示当前在(i,j)处，持有k个宝物，宝物最大价值为c的方案数目
int f[N][N][M][M];
/*
转移的基本思路。
1.当前从左往右：
    选择这个数：需要cij>c,f[i][j][k][c]+=f[i][j-1][k-1][c]
    不选这个数：f[i][j][k][c]+=f[i-1][j][k][c]
2.当前从上往下：
    选择这个数：需要cij>c,f[i][j][k][c]+=f[i-1][j][k-1][c]
    不选这个数：f[i][j][k][c]+=f[i][j-1][k][c]
*/

int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        // 价格从0到12,开始不选价格为-1,所以全部加1处理
        {
            cin >> martix[i][j];
            martix[i][j]++;
        }

    // 第一个不选
    f[1][1][0][0] = 1;
    // 第一个选
    f[1][1][1][martix[1][1]] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            // 个数
            for (int u = 0; u <= k; u++)
            {
                // 价值
                for (int v = 0; v <= 13; v++)
                {

                    // 从左向右不选
                    f[i][j][u][v] = (f[i][j][u][v] + f[i][j - 1][u][v]) % MOD;
                    // 从上到下不选
                    f[i][j][u][v] = (f[i][j][u][v] + f[i - 1][j][u][v]) % MOD;
                    // 选择有价值且是当前最大价值
                    if (u > 0 && v == martix[i][j])
                    {
                        for (int c = 0; c < v; c++)
                        {
                            // 从左往右
                            f[i][j][u][v] = (f[i][j][u][v] + f[i][j - 1][u - 1][c]) % MOD;
                            // 从上往下
                            f[i][j][u][v] = (f[i][j][u][v] + f[i - 1][j][u - 1][c]) % MOD;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i <= 13; i++)
    {
        ans = (ans + f[n][m][k][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}