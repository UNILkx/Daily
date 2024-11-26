#include <iostream>

typedef long long ll;

using namespace std;

int n;
int a, b, p;

ll qmi(int a, int b, int p)
{
    // p=1的时候，结果为0。这个要注意一下
    ll ans = 1 % p;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = (ll)a * a % p;
        b >>= 1;
    }
    return ans;
}

int main()
{
    cin >> n;

    while (n--)
    {
        long long ans = 1;
        cin >> a >> b >> p;
        // 显然超时
        // for (int i = 1; i <= b; i++)
        // {
        //     ans = (ans * a) % p;
        // }

        ans = qmi(a, b, p);
        cout << ans << endl;
    }
    return 0;
}