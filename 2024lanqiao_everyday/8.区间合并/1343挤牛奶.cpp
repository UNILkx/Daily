#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
vector<PII> t;
vector<PII> f;
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        t.push_back({l, r});
    }
    sort(t.begin(), t.end());
    int l = t[0].first, r = t[0].second;
    for (int i = 1; i < t.size(); i++)
    {
        // 加等于号
        if (t[i].first <= r)
            r = max(r, t[i].second);
        else
        {
            f.push_back({l, r});
            l = t[i].first, r = t[i].second;
        }
    }
    f.push_back({l, r});
    // sort(f.begin(), f.end());
    //   连续工作最长时间，连续没人工作最长时间
    int mx = f[0].second - f[0].first, mn = 0;
    for (int i = 1; i < f.size(); i++)
    {
        mx = max(mx, f[i].second - f[i].first);
        mn = max(mn, f[i].first - f[i - 1].second);
    }
    cout << mx << ' ' << mn << endl;
    return 0;
}