#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int n;
// 需要longlong ，1e6会导致后面很大
long long H[N];
long long temp[N];
int ans;

// // 判断是否向左搜索，1左，0右
// int check(int mid)
// {
//     memcpy(temp, H, sizeof H);
//     int dir;
//     // H[0]已经被设置为mid
//     for (int i = 0; i < n; i++)
//     {
//         dir = temp[i + 1] - temp[i];
//         temp[i + 1] = temp[i] - dir;
//         if (temp[i + 1] < 0)
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
//     cin >> n;
//     long long Max = -1;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> H[i];
//         //Max = max(Max, H[i]);
//     }
//     int l = 0, r = 1e6;
//     while (l < r)
//     {
//         int mid = l + r >> 1;
//         H[0] = mid;
//         if (check(mid)) // 向左找
//             r = mid;
//         else
//             l = mid + 1;
//     }
//     cout << l << endl;
//     return 0;
// }

// 这一题有一个推导公式，设能量为E，高度为H
// 第i，i+1表示为 E[i+1]=E[i]+E[i]-H[i+1]-->E[i]=E[i+1]+H[i+1]>>1;
//  这一题也可以反过来推导
int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> H[i];
    int sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum = (sum + H[i]) / 2;
    }
    cout << sum;
    return 0;
}