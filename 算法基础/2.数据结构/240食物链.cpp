#include <iostream>

using namespace std;

const int N = 5e5 + 10;

int n, k;
int p[N], d[N];
// d相互关系，mod3，0表示同一营养级，1表示x吃y，2表示y吃z
int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        // 更新x到根节点的距离
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0;

    while (k--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        // xy不规范
        if (x > n || y > n) // 假话
            res++;
        else
        {
            int px = find(x), py = find(y);
            if (t == 1) // 同营养级
            {
                // 同一集合但是距离不同，显然有捕食关系，不可能为同一营养级
                if (px == py && ((d[x] - d[y]) % 3))
                    res++;
                // 不同集合,合并
                else if (px != py)
                {
                    p[px] = py;
                    // 记录x所在根节点到y的差值
                    d[px] = d[y] - d[x];
                }
            }
            else // 捕食关系,x吃y
            {
                if (x == y) // 同一物种
                {
                    res++;
                    continue;
                }
                if (px == py && (d[x] - d[y] - 1) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}