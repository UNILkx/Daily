#include <bits/stdc++.h>
using namespace std;

int start_t, end_t, temp, data0 = 0, sum;

int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    cin >> start_t >> end_t;
    for (int i = 1; i <= 12; i++)
    { // 月
        for (int j = 1; j <= month[i]; j++)
        { // 日
            temp = j % 10 * 1000 + j / 10 * 100 +
                   i % 10 * 10 + i / 10;        // 月日倒置
            data0 = temp * 10000 + i * 100 + j; // 假定回文
            if (data0 > end_t || data0 < start_t)
                continue;
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}