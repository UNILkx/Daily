#include <iostream>
#include <vector>
const int N = 16;

using namespace std;

int n;
int status[N] = {0}; // 记录数据状态,0还没到，1选它，2不选他
vector<vector<int>> ways;

void dfs(int now)
{
    if (now == n) // 分支到最后
    {
        vector<int> way;
        for (int i = 0; i < n; i++)
            if (status[i] == 1)
                way.push_back(i);

        ways.push_back(way);

        return;
    }
    status[now] = 2; // 不选他
    dfs(now + 1);
    // 注意恢复现场
    status[now] = 0;

    status[now] = 1; // 选他
    dfs(now + 1);
    // 注意恢复现场
    status[now] = 0;
}

int main()
{
    cin >> n;

    dfs(0);
    for (int i = 0; i < ways.size(); i++)
    {
        for (int j = 0; j < ways[i].size(); j++)
            printf("%d ", ways[i][j]);
        puts("");
    }
    return 0;
}