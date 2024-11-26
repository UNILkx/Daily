// 本题可以参看这篇文章https://blog.csdn.net/Yuki_fx/article/details/115103663
#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int n;
int a[N];
int primes[N];
int cnt = 0;

int is_prime(int x)
{
    for (int i = 2; i <= x; i++)
    {
        // 从2,3,4,5,6开始枚举，前面是质数，初始为0（记为质数），后续质数的倍数都为合数，标为1
        // 这是朴素筛法，很直觉得从低到高筛掉质数倍数，但是会重复（质数相乘）
        if (!a[i])
        {
            primes[cnt++] = i; // 存放质数
            for (int j = 2 * i; j <= x; j += i)
            {
                if (a[j])
                    continue;
                a[j] = 1;
            }
        }
        // 埃氏筛法：任何一个大于 1 的自然数 N, 如果 N 不为质数，那么 N 可以唯一分解成有限个质数的乘积
        //  这是线性筛法，一方面筛去质数倍数，一方面只筛去一次质数乘积
        if (!a[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            // i是质数，删除质数相互乘积
            a[i * primes[j]] = 1;

            // primes[j]是i的最小质因子时成立
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    cin >> n;

    is_prime(n);

    cout << cnt << endl;

    return 0;
}
