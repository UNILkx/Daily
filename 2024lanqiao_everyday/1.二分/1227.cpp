#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int n, k; // n块，k人
int h[N], w[N];

bool check(int mid)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] / mid > 0 && w[i] / mid > 0)
            cnt += h[i] / mid * w[i] / mid;
    }
    if (cnt >= k) // 一旦大于k，说明小了，往右找
        return true;
    return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i] >> w[i];
    int l = 1, r = N;
    int mid = 0;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}