#include <bits/stdc++.h>

using namespace std;

int n;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// ababbaba的回文日期，b只能为0或者1，a<=8
int ab[20] = {
    10100101,
    20200202,
    21211212,
    30300303,
    40400404,
    50500505,
    60600606,
    70700707,
    80800808,
    90900909,
};
bool check(int y, int m, int d)
{
    if (m > 12 || m < 1 || d > 31 || d < 1)
        return false;
    if (m == 2 && d == 29)
    {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            return true;
        return false;
    }
    else if (month[m] >= d)
        return true;
    return false;
}

int main()
{
    cin >> n;
    int fir, sec;
    for (int i = n + 1; i <= 99991231; i++)
    {
        int l, r; // 左右两边记录,
        l = i / 10000;
        r = i % 10 * 1000 + (i / 10) % 10 * 100 +
            (i / 100) % 10 * 10 + (i / 1000) % 10;
        if (l != r)
            continue;
        // 判断是否合法
        else
        {
            int y = i / 10000;
            int m = (i / 100) % 100;
            int d = i % 100;
            if (check(y, m, d))
            {
                fir = i;
                break;
            }
            else
                continue;
        }
    }
    for (int i = 0; i < 11; i++)
        if (ab[i] > n)
        {
            sec = ab[i];
            break;
        }
    cout << fir << endl
         << sec << endl;

    return 0;
}