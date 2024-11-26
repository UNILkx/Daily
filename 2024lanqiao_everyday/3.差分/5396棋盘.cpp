#include <bits/stdc++.h>

using namespace std;

int n, m;
// 白色为0，黑色为1
int martix[2005][2005];

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 二维差分矩阵实现
        martix[x1][y1]++;
        martix[x1][y2 + 1]--;
        martix[x2 + 1][y1]--;
        martix[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            martix[i][j] += martix[i - 1][j] + martix[i][j - 1] - martix[i - 1][j - 1];
            if (martix[i][j] % 2)
                martix[i][j] = 1;
            else
                martix[i][j] = 0;
            cout << martix[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // 二维差分数组，实际上n范围不大，所以可以试试一行一行计算
        for (int i = x1; i <= x2; i++)
        {
            martix[i][y1] = !martix[i][y1];
            martix[i][y2 + 1] = !martix[i][y2 + 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (martix[i][j])
                martix[i][j] = !martix[i][j - 1];
            else
                martix[i][j] = martix[i][j - 1];
            cout << martix[i][j];
        }
        cout << endl;
    }

    return 0;
}