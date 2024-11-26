#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int mp[105][105];  // 存迷宫地图
int vis[105][105]; // 存储距离
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y) // 广度优先遍历
{
    queue<pair<int, int>> q;
    q.push({x, y});
    pair<int, int> st;
    while (!q.empty())
    {
        st = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            // 可能可以走的下一个点
            int nx = st.first + dx[i];
            int ny = st.second + dy[i];
            // 这个点可以走且没走过
            if (mp[nx][ny] == 0)
            {
                // 先到先封锁
                mp[nx][ny] = 1;
                // 更新距离
                vis[nx][ny] = vis[st.first][st.second] + 1;
                // 将这个点加入队列
                q.push({nx, ny});
            }
        }
    }
    cout << vis[n][m] << endl;
}

int main()
{
    // 开始得设置墙，不然会越界
    memset(mp, 1, sizeof(mp));

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];

    bfs(1, 1);
    return 0;
}