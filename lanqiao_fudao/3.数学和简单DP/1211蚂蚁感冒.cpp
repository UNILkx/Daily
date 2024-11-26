#include <iostream>
#include <cmath>
using namespace std;

const int N = 55;
int n;
int x[N];
int l, r;
int main()
{
    cin >> n;

    // x[i]>0,朝右边，x[i]<0，朝左边
    for (int i = 0; i < n; i++)
        cin >> x[i];
    // 相撞即视为蚂蚁穿过对方，由于都被感染了，所以更无所谓掉头
    // abs(x[i])表示距离左边的距离
    // 循环中考虑的是一定有其他蚂蚁感染，
    // 也就是x[0]<0时，一定有x[i]>0,且在x[0]左边,或者x[0]>0时，一定有x[i]<0,且在x[0]右边
    // 所以有特殊情况需要处理
    for (int i = 1; i < n; i++)
    {
        // 感染蚂蚁左边的蚂蚁朝右边走
        if (x[i] > 0 && abs(x[i]) < abs(x[0]))
            l++;
        // 感染蚂蚁右边的蚂蚁朝左边走
        if (x[i] < 0 && abs(x[i]) > abs(x[0]))
            r++;
    }
    // 当朝右，右边没有被感染的蚂蚁(此时l=0)，或者朝左，左边没有被感染的蚂蚁时(r=0)，只有他自己感染
    if (x[0] > 0 && r == 0 || x[0] < 0 && l == 0)
        cout << 1 << endl;
    else
        cout << l + r + 1 << endl;
    return 0;
}