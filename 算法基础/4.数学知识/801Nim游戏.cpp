#include <iostream>

using namespace std;

int n, m, res;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> m;
        res = res ^ m;
    }
    if (res)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}