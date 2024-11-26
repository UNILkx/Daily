#include <iostream>
using namespace std;

int n, m, res;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        if (i % 2)
            res ^= m;
    }
    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}