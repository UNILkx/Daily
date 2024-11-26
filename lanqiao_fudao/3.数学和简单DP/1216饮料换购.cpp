#include <iostream>

using namespace std;

int n;
int ans;
int main()
{
    cin >> n;
    ans = n;
    // 小于3的时候一瓶也换不了
    while (n >= 3)
    {
        ans += n / 3;
        n = n / 3 + n % 3;
    }
    cout << ans;
    return 0;
}