#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
char mp[N][N];
bool st[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int ans;
// char q[N][N];
int flag = 0;

void dfs(int x, int y)
{
    // 旁边全是陆地，说明不会淹没
    if (flag && mp[x - 1][y] == '#' && mp[x + 1][y] == '#' && mp[x][y + 1] == '#' && mp[x][y - 1] == '#')
        flag = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (mp[nx][ny] == '#' && !st[nx][ny])
        {
            st[nx][ny] = true;
            dfs(nx, ny);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
        }
    }
    memset(st, 0, sizeof(st));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 是岛屿且没有访问
            if (mp[i][j] == '#' && !st[i][j])
            {
                flag = 1;
                st[i][j] = true;
                dfs(i, j);
                if (flag)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// 这个思路是，计算前后两个图的连通块，一减就是少的岛屿
// 但是并不对，有的岛屿会从一个变成多个，有的岛屿则是不变，有的岛屿消失
// void dfs(int x, int y)
// {
//     // 这个主要是标记连通块
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + dx[i], ny = y + dy[i];
//         if (mp[nx][ny] == '#' && !st[nx][ny])
//         {
//             st[nx][ny] = true;
//             dfs(nx, ny);
//         }
//     }
// }

// int main()
// {
//     cin >> n;
//     // 记录前后岛屿数量
//     int bg = 0, ed = 0;
//     // memset(mp, '.', sizeof(mp));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> mp[i][j];
//         }
//     }
//     memset(st, 0, sizeof(st));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (mp[i][j] == '#' && !st[i][j])
//             {
//                 st[i][j] = true;
//                 dfs(i, j);
//                 bg++;
//             }
//         }
//     }

//     // 处理被淹没的部分，形成新的map
//     memset(st, 0, sizeof(st));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (mp[i][j] == '#')
//             {
//                 int flag = 0;
//                 for (int z = 0; z < 4; z++)
//                 {
//                     int nx = i + dx[z], ny = j + dy[z];
//                     if (mp[nx][ny] == '.')
//                     {
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if (flag)
//                     st[i][j] = true;
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (st[i][j])
//                 mp[i][j] = '.';
//         }
//     }
//     memset(st, 0, sizeof(st));
//     // 计算新的岛屿
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (mp[i][j] == '#' && !st[i][j])
//             {
//                 st[i][j] = 1;
//                 dfs(i, j);
//                 ed++;
//             }
//         }
//     }
//     cout << bg - ed << endl;
//     return 0;
// }