#include <iostream>

using namespace std;

const int N = 1010;
int n, v;
int V[N], W[N];
int f[N][N];

int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
        // 价格，体积
        cin >> V[i] >> W[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - V[i]] + W[i]);

            // 会TLE
            // //  第i个物品选k个
            // for (int k = 0; k * V[i] <= j; k++)
            // {
            //     f[i][j] = max(f[i][j], f[i - 1][j - k * V[i]] + k * W[i]);
            // }
        }
    }
    cout << f[n][v] << endl;
    return 0;
}