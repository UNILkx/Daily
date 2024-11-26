#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;

char a[N][N];
int martix[N][N];
int temp[N][N];
int now;

int check()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!martix[i][j])
            {
                // cout << "i:" << i << martix[i][j] << endl;
                return 0;
            }
        }
    }
    return 1;
}
void turn(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == x && j == y)
                martix[i][j] = !martix[i][j];
            else if (i == x)
                martix[i][j] = !martix[i][j];
            else if (j == y)
                martix[i][j] = !martix[i][j];
        }
    }
}
int main()
{

    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
        // cout << a[i] << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == '+') // 闭合
            {
                martix[i][j] = 0;
            }
            else
            {
                martix[i][j] = 1;
            }
            // cout << martix[i][j] << " ";
        }
    }

    // 暴力枚举所有情况
    for (now = 0; now < 1 << 16; now++)
    {

        memcpy(temp, martix, sizeof martix);
        for (int i = 0; i < 16; i++)
        {
            // 第i位为1，则翻转
            if (now >> i & 1)
            {
                turn(i / 4, i % 4);
            }
        }
        if (check())
            break;
        memcpy(martix, temp, sizeof martix);
    }
    int step = 0;
    for (int i = 0; i < 16; i++)
    {
        if (now >> i & 1)
        {
            step++;
        }
    }
    cout << step << endl;
    for (int i = 0; i < 16; i++)
    {
        if (now >> i & 1)
        {
            printf("%d %d\n", i / 4 + 1, i % 4 + 1);
        }
        }
    return 0;
}