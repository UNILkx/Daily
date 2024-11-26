#include <iostream>

using namespace std;

int n;
int a[10], queue[10]; // 输出队列
void dfs(int x)
{
    if (x > n) // 全部选完
    {
        for (int i = 1; i <= n; i++)
            cout << queue[i] << ' ';
        cout << endl;
        return;
    }
    // 当前数字没选
    for (int i = 1; i <= n; i++)
    {
        if (!a[i])
        {
            a[i] = 1;
            queue[x] = i;
            // 递归
            dfs(x + 1);

            // 还原现场
            a[i] = 0;
            queue[x] = 0;
        }
    }
    return;
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
