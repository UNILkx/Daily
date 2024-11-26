#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1E5 + 10;
// a[0]最高位
// char a[N];
// char b[N];
// a[0]最低位
long long ans[N];
int len_a, len_b, len;

int main()
{
    string a, b;
    cin >> a >> b;
    len_a = a.size();
    len_b = b.size();
    // cout << a << ' ' << b << endl;
    int i = len_a - 1, j = len_b - 1;
    // cout << i << ' ' << j << endl;
    int sum, c;
    for (; i >= 0 && j >= 0; i--, j--)
    {
        // cout << a[i] << ' ' << b[j] << endl;
        sum = a[i] - '0' + b[j] - '0';
        // cout << sum << endl;
        ans[len] += sum;
        if (ans[len] / 10)
        {
            ans[len + 1]++;
            ans[len] %= 10;
        }

        len++;
    }
    // 说明a长
    while (i >= 0)
    {
        sum = a[i--] - '0';
        ans[len] += sum;
        if (ans[len] / 10)
        {
            ans[len + 1]++;
            ans[len] %= 10;
        }

        len++;
    }
    // 说明b长
    while (j >= 0)
    {
        int sum = b[j--] - '0';
        ans[len] += sum;
        if (ans[len] / 10)
        {
            ans[len + 1]++;
            ans[len] %= 10;
        }
        len++;
    }
    if (!ans[len])
        len--;
    for (int i = len; i >= 0; i--)
        cout << ans[i];

    return 0;
}