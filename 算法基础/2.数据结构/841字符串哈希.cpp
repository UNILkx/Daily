#include <iostream>

using namespace std;
// 经验表示，哈希函数取值为P=131或13331,模Q=2^64时，冲突概率较低
// 但是在实际应用中，P=131和P=13331的冲突概率是一样的
const int N = 1e5 + 10, P = 131;

int n, m;
char s[N];

unsigned long long h[N], p[N];

bool check(int l1, int r1, int l2, int r2)
{
    if (r2 - l2 != r1 - l1)
        return false;
    return (h[r2] - h[l2 - 1] * p[r2 - (l2 - 1)]) == (h[r1] - h[l1 - 1] * p[r1 - (l1 - 1)]);
}
int main()
{
    cin >> n >> m;
    cin >> s + 1;
    p[0] = 1;
    // 初始化哈希函数
    for (int i = 1; i <= n; i++)
    {
        // h[i]表示前i个字符的哈希值
        h[i] = h[i - 1] * P + s[i];
        // p[i]表示P的i次方
        p[i] = p[i - 1] * P;
    }
    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int flag = check(l1, r1, l2, r2);
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
