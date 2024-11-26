#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> fp;
int n;

// 辗转相除法
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first * b.second < a.second * b.first;
}
int main()
{
    cin >> n;

    fp.push_back({0, 1});
    // i分子，j分母
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            if (gcd(i, j) == 1)
                fp.push_back({i, j});
        }
    }
    sort(fp.begin(), fp.end(), cmp);
    for (int i = 0; i < fp.size(); i++)
    {
        cout << fp[i].first << '/' << fp[i].second << endl;
    }
    return 0;
}