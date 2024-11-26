#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        int flag = 0;
        if (a == 1)
            flag = 1;
        for (int i = 2; i <= sqrt(a); i++)
        {
            if (!(a % i))
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

    return 0;
}