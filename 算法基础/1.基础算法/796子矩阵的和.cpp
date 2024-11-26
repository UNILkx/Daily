#include <iostream>

using namespace std;
const int N = 1e3 + 10;

int n, m, q;
int a, b, x, y;
int martix[N][N];
int sum[N][N];

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> martix[i][j];
            sum[i][j] = sum[i][j - 1] + martix[i][j];
        }
    }
    int ans = 0;
    while (q--)
    {
        ans = 0;
        cin >> a >> b >> x >> y;
        for (int i = a; i <= x; i++)
        {
            ans += sum[i][y] - sum[i][b - 1];
        }
        cout << ans << endl;
    }

    return 0;
}
