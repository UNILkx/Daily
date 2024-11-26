#include <iostream>

using namespace std;
const int N = 1e3 + 10;
int n, v;
int u[N], w[N];
int f[N];

int main()
{
    // 物品数量和背包溶剂
    cin >> n >> v;

    for (int i = 0; i < n; i++)
    {
        cin >> u[i] >> w[i];
    }
    // 转移方程f[i][j]=max(f[i-1][j],f[i-1][j-u[i]]+w[i]);
    // 优化空间后,f[i]=max(f[i-1],f[i-u[i]]+w[i]);
    for (int i = 0; i < n; i++)
        for (int j = v; j >= u[i]; j--)
            f[j] = max(f[j], f[j - u[i]] + w[i]);
    cout << f[v] << endl;
    return 0;
}