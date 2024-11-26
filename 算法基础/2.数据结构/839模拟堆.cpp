#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1 << 31 - 1;
int n;
int h[N], ph[N], hp[N], cnt, idx;
// heap，point to heap,heap to point
//  h[]存放堆，ph[]存放指向第k个插入的数在堆中位置，hp[]可以获得堆中数是第几个插入的

void heap_swap(int p, int s) // 交换父子节点
{
    swap(h[p], h[s]);
    // hp[p]得到p是第p个插入的，ph[hp[p]]得到第p个插入的在堆中的位置
    swap(ph[hp[p]], ph[hp[s]]);
    swap(hp[p], hp[s]);
}
// 进行堆排序
void heap_down(int x)
{
    int t = x;
    if (2 * x <= cnt && h[2 * x] < h[t])
        t = 2 * x;
    if (2 * x + 1 <= cnt && h[2 * x + 1] < h[t])
        t = 2 * x + 1;
    if (t != x)
    {
        heap_swap(x, t);
        heap_down(t);
    }
}
// 插入值之后，更新堆h，注意为小根堆
void up(int x)
{
    // 另一个儿子节点显然比父节点大
    while (x / 2 && h[x] < h[x / 2])
    {
        heap_swap(x / 2, x);
        x /= 2;
    }
}
int main()
{
    cin >> n;
    while (n--)
    {
        string c;
        int k, x;
        cin >> c;
        if (c == "I")
        {
            cin >> x;
            cnt++;
            idx++;
            // 堆尾插入x
            h[cnt] = x;
            // ph记录第k插入数在堆中插入的位置
            ph[idx] = cnt;
            // hp反应堆中插入的数是第几个插入的
            hp[cnt] = idx;
            // 更新堆
            up(cnt);
        }
        else if (c == "PM")
        {
            cout << h[1] << endl;
        }
        else if (c == "DM")
        {
            heap_swap(1, cnt);
            cnt--;
            heap_down(1);
        }
        else if (c == "D")
        {
            cin >> k;
            // 获得第k个插入的是在heap数组的下标
            k = ph[k];
            heap_swap(k, cnt);
            cnt--;
            // 该位置可能上升或下沉
            heap_down(k), up(k);
        }
        else if (c == "C")
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            // 该位置可能上升或下沉
            heap_down(k), up(k);
        }
    }

    return 0;
}