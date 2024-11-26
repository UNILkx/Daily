#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return pow(2, 20);
    if (a < b && b < c)
        return pow(2, a);
    return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
    ll x, y, z;
    while (cin >> x >> y >> z)
    {
        if (x == -1 && y == -1 && z == -1)
            break;

        cout << "w(" << x << ", " << y << ", " << z << ")"
             << " = " << w(x, y, z) << endl;
    }

    return 0;
}