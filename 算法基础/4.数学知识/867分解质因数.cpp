#include <iostream>

using namespace std;

int n, x;

int main()
{
    cin >> n;
    int flag = 0;
    while (n--)
    {
        cin >> x;

        int cnt = 0;
        for (int i = 2; i <= x / i; i++)
        {
            flag = cnt = 0;
            while (!(x % i))
            {
                flag = 1;
                cnt++;
                x /= i;
            }
            if (flag)
                cout << i << ' ' << cnt << endl;
        }
        // 上面处理完的x值可能小于i，导致退出循环，这个时候判断剩余的x值，如果大于1说明也是他的因数
        // 要注意这一行
        if (x > 1)
            cout << x << ' ' << '1' << endl;
        cout << endl;
    }
    return 0;
}