#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 1e5 + 10;

int n, len;
// int l[N], s[N];
int l, s;
vector<pair<int, int>> p;

// 返回是否满了，已经满了往左边找返回1
bool check(ll mid)
{
    vector<pair<int, int>> mp;
    for (int i = 0; i < n; i++)
    {
        // 已经升序排列，一旦某个管道的开启时间大于mid，后面都大于，不用考虑了
        if (p[i].first > mid)
            break;
        int l = p[i].first, s = p[i].second;
        int left, right;
        left = max(1ll, s - (mid - l)), right = min((ll)len, s + (mid - l));
        mp.push_back({left, right});
    }

    // 如果出来之后，mp是空的，直接返回
    if (mp.empty())
        return false;

    // 随后mp按照left进行排序，最后合并出右区间的最大值
    sort(mp.begin(), mp.end());
    // ！！！如果排序后，最小的left还没到第一个
    if (mp[0].first > 1)
        return false;
    int cnt = mp[0].second;
    int size = mp.size();
    // 下面是合并右边区间查看是否全包
    for (int i = 1; i < size; i++)
    {
        // ！！！如果，不连续，比如mp[0].right<mp[1].left,说明没连上
        if (mp[i].first > cnt + 1)
            return false;
        cnt = max(cnt, mp[i].second);
    }

    return cnt == len;
}

int main()
{
    cin >> n >> len;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> s;
        // p[i]={l[i],s[i]}也可以赋值
        p.push_back({s, l});
    }

    sort(p.begin(), p.end());
    ll l = 1, r = 2e9; // 可能只有一个开，且在最边缘最晚
    // 找到时刻恰好是满和没满的分界线
    while (l < r)
    {
        ll mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;

    return 0;
}