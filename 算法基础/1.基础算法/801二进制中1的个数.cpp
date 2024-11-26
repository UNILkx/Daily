#include <iostream>

using namespace std;

int n;

int bit_count(int a)
{
    int sum = 0;
    while (a)
    {
        if (a & 1)
            sum++;
        a >>= 1;
    }
    return sum;
}

int main()
{
    cin >> n;
    int a;
    while (n--)
    {
        cin >> a;
        cout << bit_count(a) << ' ';
    }
    return 0;
}