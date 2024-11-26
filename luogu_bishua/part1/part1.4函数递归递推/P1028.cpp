#include <iostream>

using namespace std;

int n;
long long ans = 0;

void dfs(int x)
{
    // 放这里是因为，进来之后有到他截止的情况
    ans++;
    for (int i = x / 2; i >= 1; i--)
    {
        dfs(i);
    }
    return;
}

int main()
{
    cin >> n;
    dfs(n);
    cout << ans;
    return 0;
}