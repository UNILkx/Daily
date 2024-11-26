#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], p[N][N];
// a是p矩阵的二维差分前缀和

// 二维差分数组

int main()
{
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            p[i][j] = a[i][j] - a[i - 1][j] - a[i][j - 1] + a[i - 1][j - 1];
        }
    while (q--)
    {
        int x1, x2, y1, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        p[x1][y1] += c;
        p[x1][y2 + 1] -= c;
        p[x2 + 1][y1] -= c;
        p[x2 + 1][y2 + 1] += c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = p[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}

// 每行差分
// int main()
// {
//     cin >> n >> m >> q;
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= m; j++)
//         {
//             cin >> a[i][j];
//             p[i][j] = a[i][j] - a[i][j - 1];
//         }
//     while (q--)
//     {
//         int x1, x2, y1, y2, c;
//         cin >> x1 >> y1 >> x2 >> y2 >> c;
//         for (int i = x1; i <= x2; i++)
//         {
//             p[i][y1] += c;
//             p[i][y2 + 1] -= c;
//         }
//     }
//     // int res = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             a[i][j] = a[i][j - 1] + p[i][j];
//             cout << a[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }