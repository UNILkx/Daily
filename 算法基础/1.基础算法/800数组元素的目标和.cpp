#include <iostream>

using namespace std;
const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

// 二分做法，时间复杂度O(nlogm);
void binary_search()
{
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = m;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (a[i] + b[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (a[i] + b[l] == x)
        {
            cout << i << ' ' << l << endl;
            return;
        }
    }
}

// 双指针，左右指针
// 因为两个数组都是升序，所以在查找的时候可以左右夹逼，一旦和小于目标值，说明是左边小了
void two_pointers()
{
    int j = m - 1;
    for (int i = 0; i < n; i++)
        for (;;)
        {
            if (a[i] + b[j] == x)
            {
                cout << i << ' ' << j << endl;
                return;
            }
            else if (a[i] + b[j] < x)
                break;
            else
                j--;
        }

    // 也可以进一步修改
    //      int i=0,j=m-1;
    // while(i<n&&j>=0)
    //     {
    //         if (a[i] + b[j] == x)
    //         {
    //             cout << i << ' ' << j << endl;
    //             return;
    //         }
    //         else if (a[i] + b[j] < x)
    //            i++;
    //         else
    //             j--;
    //     }
}
int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // 二分
    //  binary_search();

    // 双指针,左右指针
    two_pointers();
    return 0;
}