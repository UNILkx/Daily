#include <iostream>
using namespace std;

int n, m, q;
int martix[1010][1010];
int sub[1010][1010];
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> martix[i][j];
            sub[i][j] = martix[i][j] - martix[i][j - 1];
        }

    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        for (int i = x1; i <= x2; i++)
        {
            sub[i][y1] += c;
            sub[i][y2 + 1] -= c;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        for (int j = 1; j <= m; j++)
        {
            ans += sub[i][j];
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}