#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int l, r;
vector<pair<int, int>> input;

// y总方法
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> l >> r;
        input.push_back({l, r});
    }

    // 排序
    sort(input.begin(), input.end());

    vector<pair<int, int>> res;
    // 这是一个维护区间
    int st = -2e9, ed = -2e9;
    for (auto it : input)
    {
        // 维护区间右边小于当前左边，产生新的区间
        if (ed < it.first)
        {
            if (st != -2e9)
                res.push_back({st, ed});
            st = it.first, ed = it.second;
        }
        else
            ed = max(ed, it.second);
    }
    if (st != -2e9)
        res.push_back({st, ed});

    cout << res.size() << endl;
    return 0;
}

// 一般写法
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> l >> r;
        input.push_back({l, r});
    }
    sort(input.begin(), input.end());

    int st = input[0].first, ed = input[0].second;
    // 初始有一个区间
    int res = 1;
    for (auto it : input)
    {
        if (it == input[0])
            continue;
        if (ed < it.first)
        {
            res++;
            st = it.first, ed = it.second;
        }
        else
            ed = max(ed, it.second);
    }
    cout << res;

    return 0;
}