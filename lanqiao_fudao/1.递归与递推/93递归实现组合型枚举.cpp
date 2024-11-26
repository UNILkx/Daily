#include <iostream>
// n + n - m <= 25, N应该设置为25.。。
// 同时，要求输出字典序，只需要比较加入时该点和队列前一个点的大小关系。不满足则会取消这个输出 using namespace std;
using namespace std;

const int N = 25;
int n, m;
int length;
int state[N]; // 节点选没选,0没选，1选了
int que[N];   // 保存结果,0表明当前没有，1表示有

void dfs(int now)
{
    // 搜索完毕或找到了m个节点不必再寻找
    if (now > n || length == m)
    {
        // 加入的节点数目长度为length，不必到n
        for (int i = 1; i <= length; i++)
            printf("%d ", que[i]);
        puts("");
        return;
    }
    // 遍历n个节点
    // 显然在now之前的节点不满足，故i从now开始
    for (int i = now; i <= n; i++)
    {
        if (!state[i]) // 遍历选择当前数字
        {
            if (i < que[now - 1]) // 字典序
                continue;
            que[now] = i;
            state[i] = 1;
            length++;
            dfs(now + 1);
            // 恢复现场
            que[now] = 0;
            state[i] = 0;
            length--;
        }
    }
}

int main()
{
    cin >> n >> m;
    // 下标修改了记得dfs也要修改起始位置

    dfs(1);

    return 0;
}

// 另一种做法，也是讲解的
#include <iostream>

using namespace std;

const int N = 25;
int n, m;

int que[N]; // 保存结果,0表明当前没有，1表示有

void dfs(int now, int start) // 当前长度，当前可以选择最小的数
{
    // 剪枝
    if (now + n - start < m)
        return;

    // 搜索完毕或找到了m个节点不必再寻找
    if (now > m)
    {
        for (int i = 1; i <= m; i++)
        {
            printf("%d ", que[i]);
        }
        puts("");
        return;
    }
    // 遍历n个节点
    for (int i = start; i <= n; i++)
    {
        que[now] = i;        // 选择该节点
        dfs(now + 1, i + 1); // 长度+1，最小数+1
        que[now] = 0;        // 恢复状态
    }
}

int main()
{
    cin >> n >> m;

    // 下标修改了记得dfs也要修改起始位置
    dfs(1, 1); // 从

    return 0;
}