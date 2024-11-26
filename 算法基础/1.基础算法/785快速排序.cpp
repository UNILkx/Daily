#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

void quick_sort(int l, int r)
{
    if (l >= r)
        return;
    // 考虑2,1两个数的快排
    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        // 找到
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    // 递归处理左边
    quick_sort(l, j);
    // 递归处理右边
    quick_sort(j + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}