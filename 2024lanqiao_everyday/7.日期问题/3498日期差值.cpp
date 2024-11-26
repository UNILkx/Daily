#include <bits/stdc++.h>

using namespace std;

int num[205];
int len; // 测试数据组数
int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 检查是否是闰年
bool check(int y)
{
    if (y % 4 && y % 100 != 0 || y % 400 == 0)
        return true;
    return false;
}

// 当前年份对应的时间
int ynum(int y)
{
    // 不考虑闰年
    int sum = (y - 1) * 365;
    // 闰年对应次数
    for (int i = 1; i < y; i++)
    {
        if (check(i))
            sum++;
    }
    return sum;
}
// 当前月份对应的时间
int mnum(int y, int m)
{
    int sum = 0;
    for (int i = 1; i < m; i++)
    {
        sum += month[i];
    }
    if (check(y))
        sum += 1;
    return sum;
}

int main()
{
    char s[8];
    while (scanf("%s", &s))
    {
        for (int i = 0; i < 8; i++)
        {
            cout << s[i];
        }

        // for (int i = 0; i < 8; i++)
        //     s[i] -= '0';
        // 年月日
        int y, m, d;
        y = s[0] * 1000 + s[1] * 100 + s[2] * 10 + s[3];
        m = s[4] * 10 + s[5];
        d = s[6] * 10 + s[7];
        num[len++] = ynum(y) + mnum(y, m) + d;
    }
    for (int i = 0; i < len; i += 2)
    {
        cout << abs(num[i] - num[i + 1] + 1) << endl;
    }
    return 0;
}