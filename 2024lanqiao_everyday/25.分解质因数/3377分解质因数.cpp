#include <bits/stdc++.h>

using namespace std;

int n;

int check(int x)
{
    int sum = 0;
    if (x == 1)
        sum = 1;
    else
    {
        for (int i = 1; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                if (x / i != i)
                    sum += 2;
                else
                    sum += 1;
            }
        }
    }
    return sum;
}
int main()
{
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        cout << check(a) << endl;
    }
    return 0;
}