#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

// 数列长度n，和为s，后一项比前一项多a或少b
int n, s, a, b;
// f[n][s]表示长度为n，和为s的结果数
// f[n][s]=f[n-1][s-a]+f[n-1][s+b];
// 由此转化为 f[s]=f[s-a]+f[s+b],f[i]表示值为i的数量
vector<int> f;

int main()
{
    cin >> n >> s >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        }
    return 0;
}