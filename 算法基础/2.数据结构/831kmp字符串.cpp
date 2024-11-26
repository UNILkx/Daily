// 可以参考这篇理解匹配+移动的过程
// https://zhuanlan.zhihu.com/p/145536254

#include <iostream>

using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
int n, m;
int ne[N];
char p[N], s[M];
int main()
{
    // p长度，p，s长度，s
    cin >> n >> p + 1 >> m >> s + 1;

    // 首先构造next数组
    for (int i = 2, j = 0; i <= n; i++)
    {
        // 如果当前i的位置和j+1不匹配，ne[i]应回退到当前j所在位置的ne[j]。这个是回退的设计
        // 这个回退设计以及j=0的初始值，非常的妙！
        while (j && p[i] != p[j + 1])
            j = ne[j];
        // 如果匹配，就继续
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    // 模板串一边移动匹配主串，一边根据next数组判断
    for (int i = 1, j = 0; i <= m; i++)
    {
        // 如果当前i的位置和j+1不匹配，ne[i]应回退到当前j所在位置的ne[j]
        while (j && s[i] != p[j + 1])
            j = ne[j];
        // 相等，j++
        if (s[i] == p[j + 1])
            j++;
        // 匹配完成
        if (j == n)
        {
            cout << i - n << ' ';
            j = ne[j];
        }
    }
    return 0;
}