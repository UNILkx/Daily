#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 两重循环大概n/2的空间
const int N = 1.6e7;

int num, n; // n是5e6
typedef struct Item
{
    int sum;
    int x;
    int y;
    Item(){};
    Item(int x, int y) : sum(x * x + y * y), x(x), y(y) {}
};
Item item[N];

bool cmp(Item a, Item b)
{
    if (a.sum != b.sum)
        return a.sum < b.sum;
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int main()
{
    cin >> n;

    // 枚举cd，并存放到数组中
    for (int c = 0; c * c < n; c++)
    {
        for (int d = c; c * c + d * d <= n; d++)
        {
            item[num++] = Item(c, d);
        }
    }

    // 按照升序排列
    sort(item, item + num, cmp);

    for (int a = 0; a * a < n; a++)
        for (int b = a; a * a + b * b < n; b++)
        {
            int res = n - a * a - b * b;
            // 下面二分找到满足c*c+d*d=res的最小字典的item[mid]
            int l = 0, r = num - 1;
            while (l < r)
            {
                int mid = l + r >> 1;
                if (item[mid].sum >= res)
                    r = mid;
                else
                    l = mid + 1;
            }
            // 一旦找到就可以退出
            if (item[l].sum == res)
            {
                cout << a << " " << b << " " << item[l].x << " " << item[l].y << endl;
                return 0;
            }
        }
    return 0;
}
