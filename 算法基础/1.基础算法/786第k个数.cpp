#include <iostream>

using namespace std;
const int N = 1e5 + 10;

int n, k;
int a[N];

// 需要升序
void quick_sort(int l, int r)
{
    if (l >= r)
        return;
    int t = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (t > a[i]);
        do
            j--;
        while (t < a[j]);
        if (i < j)
            swap(a[i], a[j]);
    }
    // 循环出来后，下标mid左边都是小于值t的，右边都是大于t的

    cout << i << ' ' << j << endl;
    quick_sort(l, j);

    quick_sort(j + 1, r);
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // 升序
    quick_sort(0, n - 1);

    cout << a[k - 1] << endl;
    return 0;
}