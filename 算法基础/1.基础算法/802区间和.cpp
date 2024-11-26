#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3e5 + 10;
int n, m, x, c, l, r;

pair<int, int> PII;

vector<int> local;                   // local记录输入修改位置
vector<pair<int, int>> input, query; // input原始输入,query查询输入
int a[N];                            // 离散后，存放值
int pre_add[N];                      // 前缀和

int find(int tar)
{
    int l = 0, r = local.size() - 1;
    while (l < r) // 需要找到第一个为tar的
    {
        int mid = l + r >> 1;
        if (local[mid] >= tar)
            r = mid;
        else
            l = mid + 1;
    }
    // 实际应当返回local中的下标，但是前缀和数组从1开始，所以这里返回值加1
    return l + 1;
}
int main()
{
    cin >> n >> m;
    while (n--)
    {
        cin >> x >> c; // 坐标，值
        input.push_back({x, c});
        local.push_back(x);
    }

    while (m--)
    {
        cin >> l >> r;
        query.push_back({l, r});
        local.push_back(l);
        local.push_back(r);
    }
    // 排序
    sort(local.begin(), local.end());
    // 去重
    // unique有去重的作用。其返回的是前j个不重复元素的下标，local剩下的部分需要删除掉
    local.erase(unique(local.begin(), local.end()), local.end());

    // 处理插入
    for (auto it : input)
    {
        int x = find(it.first);
        a[x] += it.second;
    }

    // 处理前缀和
    for (int i = 1; i <= local.size(); i++)
    {
        pre_add[i] += pre_add[i - 1] + a[i];
    }
    for (auto it : query)
    {
        int l = find(it.first);
        int r = find(it.second);
        cout << pre_add[r] - pre_add[l - 1] << endl;
    }

    return 0;
}