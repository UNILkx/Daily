#include <iostream>

const int N = 10;
using namespace std;

int n; //
int que[N];
int status[N]; // 0未使用，1使用

void dfs(int now)
{
    if (now == n) // 结束
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", que[i]);
        }
        puts("");
    }
    for (int i = 0; i < n; i++)
    {
        if (!status[i]) // 没选择
        {
            // 由于字典序升序排序，所以需要从左边开始递归
            que[now] = i + 1;
            status[i] = 1;
            dfs(now + 1);

            // 还原现场
            // 一方面，该点被使用过，一方面，该点加入了队列
            status[i] = 0;
            que[now] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0);
    return 0;
}