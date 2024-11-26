#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int list[N] = {0};
int dir[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> list[i];
        // 差分
        dir[i] = list[i] - list[i - 1];
    }
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        dir[l] += c;
        dir[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++)
    {
        list[i] = list[i - 1] + dir[i];
        cout << list[i] << " ";
    }
    return 0;
}
