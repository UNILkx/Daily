#include <iostream>

using namespace std;

const int N = 50;

int n;
int fab[N];

int main()
{
    cin >> n;
    fab[0] = 0;
    fab[1] = 1;
    for (int i = 2; i < n; i++) // 递归？哪里有递推简单！
    {
        fab[i] = fab[i - 1] + fab[i - 2];
    }
    for (int i = 0; i < n; i++)
    {
        cout << fab[i] << " ";
    }
    return 0;
}