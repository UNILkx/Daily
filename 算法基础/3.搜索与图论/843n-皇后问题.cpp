#include <iostream>

using namespace std;

int n;
int chess[12][12]; // 1放皇后，2不可放，0还未选

void output()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (chess[i][j] == 1)
                cout << 'Q';
            //  else if(chess[i][j]==2)
            //      cout << 'x';
            else
                cout << '.';
        }
        cout << endl;
    }
    cout << endl;
    return;
}
//[x,y]放皇后之后,同行同列其他位置标记不可放,还有斜线。。
// 同时进行检查，如果可放，返回true，否则返回false
int turn(int x, int y)
{
    // 先标记行
    for (int j = 1; j <= n; j++)
    {
        if (j == y)
            continue;
        if (chess[x][j] == 1)
            return false;
        else if (!chess[x][j])
            chess[x][j] = 2;
    }
    // 标记列
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        if (chess[i][y] == 1)
            return false;
        else if (!chess[i][y])
            chess[i][y] = 2;
    }
    // 标记斜线
    for (int i = 1; i <= n - 1; i++)
    {
        if (x - i >= 1 && y - i >= 1)
        {
            if (chess[x - i][y - i] == 1)
                return false;
            else if (!chess[x - i][y - i])
                chess[x - i][y - i] = 2;
        }
        if (x - i >= 1 && y + i <= n)
        {
            if (chess[x - i][y + i] == 1)
                return false;
            else if (!chess[x - i][y + i])
                chess[x - i][y + i] = 2;
        }
        if (x + i <= n && y - i >= 1)
        {
            if (chess[x + i][y - i] == 1)
                return false;
            else if (!chess[x + i][y - i])
                chess[x + i][y - i] = 2;
        }
        if (x + i <= n && y + i <= n)
        {
            if (chess[x + i][y + i] == 1)
                return false;
            else if (!chess[x + i][y + i])
                chess[x + i][y + i] = 2;
        }
    }

    return true;
}
// 还原现场
void turn_back(int x, int y)
{
    // 先复原行
    for (int j = 1; j <= n; j++)
    {
        if (chess[x][j] == 2)
            chess[x][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (chess[i][y] == 2)
            chess[i][y] = 0;
    }
    // 还原斜线
    for (int i = 1; i <= n - 1; i++)
    {
        if (x - i >= 1 && y - i >= 1)
        {
            if (chess[x - i][y - i] == 2)
                chess[x - i][y - i] = 0;
        }
        if (x - i >= 1 && y + i <= n)
        {
            if (chess[x - i][y + i] == 2)
                chess[x - i][y + i] = 0;
        }
        if (x + i <= n && y - i >= 1)
        {
            if (chess[x + i][y - i] == 2)
                chess[x + i][y - i] = 0;
        }
        if (x + i <= n && y + i <= n)
        {
            if (chess[x + i][y + i] == 2)
                chess[x + i][y + i] = 0;
        }
    }
    return;
}

void dfs(int sum)
{
    if (sum > n) // 摆满了n个皇后
    {
        output();
        return;
    }
    int flag = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 还未处理
            if (!chess[i][j])
            {
                chess[i][j] = 1;
                // 可以放1，不可以0
                flag = turn(i, j);
                // cout << "i: " << i << " j: " << j << " flag:" << flag << endl;
                if (flag)
                {
                    // cout << "i: " << i << " j: " << j << " flag:" << flag << endl;
                    // output();
                    dfs(sum + 1);
                }
                chess[i][j] = 0;
                turn_back(i, j);

                // if (flag)
                // {
                //     // 继续深搜
                //     dfs(sum + 1);
                //     // 还原现场
                //     chess[i][j] = 0;
                //     turn_back(i, j);
                // }
                // // 当前位置不能放皇后，继续下一个位置
                // else
                // {
                //     // 还原现场
                //     chess[i][j] = 0;
                //     turn_back(i, j);
                // }
            }
            else if (chess[i][j] == 1)
                return;
            else if (chess[i][j] == 2)
                continue;
        }
    }
    return;
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}