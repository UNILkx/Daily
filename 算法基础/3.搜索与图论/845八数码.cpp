#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

int bfs(string start)
{
    string tar = "12345678x";

    // 存放当前状态
    queue<string> q;
    // 存放该状态和对应步数
    unordered_map<string, int> d;

    q.push(start);
    d[start] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int step = d[t];
        // 匹配
        if (t == tar)
            return step;
        // 返回t中x所在下标
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            // 没有出界
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
            {
                // 交换位置
                swap(t[k], t[nx * 3 + ny]);
                // 交换后的状态没有出现过
                if (!d.count(t))
                {
                    // 新的
                    d[t] = step + 1;
                    // 新的t放入队列
                    q.push(t);
                }
                // 恢复状态
                swap(t[k], t[nx * 3 + ny]);
            }
        }
    }
    // 如果上述循环没有输出结果，说明不存在
    return -1;
}

int main()
{
    string s;
    // 输入带有空格，必须单个读入
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        s += c;
    }

    cout << bfs(s) << endl;
    return 0;
}