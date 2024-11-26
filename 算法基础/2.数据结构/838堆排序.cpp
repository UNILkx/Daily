// 关于堆的讲解。https://zhuanlan.zhihu.com/p/124885051
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int n, m;
int a[N];
int cnt;

// 实现小根堆
void heap_down(int x)
{
    int t = x;
    // 有两点要注意，右孩子可能比左孩子大，此时只需要将父节点和左孩子交换，所以比较时用a[t]
    // 在pop顶端时，最后一个元素放到了顶端，此时堆大小减小，所以为cnt
    //  看左孩子
    if ((2 * x) <= cnt && a[2 * x] < a[t])
        t = 2 * x;
    // 看右孩子
    if ((2 * x + 1) <= cnt && a[2 * x + 1] < a[t])
        t = 2 * x + 1;
    if (x != t)
    {
        swap(a[x], a[t]);
        // 交换后需要重新检查 交换下去的节点
        heap_down(t);
    }
}

int main()
{
    cin >> n >> m;
    // 下标0不使用，方便节点i左右子节点和父节点的计算，分别为2i，2i+1,i/2
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 小tips，初始化大根堆，从n/2开始即可
    // 首先，所有元素是可以被访问到的，其次，这样的访问不会重复
    cnt = n;
    for (int i = n / 2; i > 0; i--)
        heap_down(i);
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << ' ';
    // cout << endl;
    while (m--)
    {
        // 最上方的最小
        cout << a[1] << ' ';
        // 输出后，将最后一个元素放到堆顶
        a[1] = a[cnt--];

        // 随后重新排序
        heap_down(1);
    }
    return 0;
}