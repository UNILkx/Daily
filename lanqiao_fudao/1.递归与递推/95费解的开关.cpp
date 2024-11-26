#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10;
int n;
int cnt;
char martix[N][N];
char temp[N][N];
int step;
int ans;
int flag;
// 翻转（x,y）及上下左右的数字
// 由于数组下标是[1,5]，所以边界不用考虑
void turn(int x, int y)
{
    if (y < 1)
    {
        temp[x][y] ^= 1;
        temp[x - 1][y] ^= 1;
        temp[x + 1][y] ^= 1;
        temp[x][y + 1] ^= 1;
    }
    else
    {
        temp[x][y] ^= 1;
        temp[x - 1][y] ^= 1;
        temp[x + 1][y] ^= 1;
        temp[x][y - 1] ^= 1;
        temp[x][y + 1] ^= 1;
    }
}

int main()
{
    cin >> n;
    while (n--)
    {
        // 输入的是字符串。。。

        for (int i = 1; i <= 5; i++)
            cin >> martix[i];
        ans = 10;
        // 这里参考题解，对与第一行五个数的翻转情况有个很好的表示
        // 由于每个位置只有翻和不翻两种情况，故可以用2进制表示
        // 如00000都不翻，01010表示第二和第四个翻
        // 0b11111 = 31
        for (int method = 0; method < 32; method++)
        {
            // 记录翻转的次数
            step = 0;

            memcpy(temp, martix, sizeof(martix));

            // 按当前情况翻转第一行
            for (int i = 0; i < 5; i++)
            {
                if (method >> i & 1) // 取出是否翻转
                {
                    step++;
                    // 翻转第一行第i个(其实不用考虑从左向右还是从右向左对应，只毕竟都能循环到)
                    turn(1, i);
                }
            }
            // 再依次决定是否翻转2345行，此时需要根据上一行的位置是否不满足决定翻转不翻转
            for (int i = 1; i <= 4; i++)
            {
                for (int j = 0; j <= 4; j++)
                {
                    if (temp[i][j] == '0')
                    {
                        step++; // 操作数加1
                        turn(i + 1, j);
                    }
                }
            }
            // 最后检查是否满足
            flag = 0; // 为1表示不满足
            for (int i = 0; i <= 4; i++)
            {
                if (temp[5][i] == '0')
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                ans = min(ans, step);
        }
        if (ans > 6)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}