#include <iostream>

using namespace std;

#include <deque>
// 尝试用双端队列完成
int n, k;

const int N = 1e6 + 10;
int a[N];
deque<int> q;
// 这个是直接存放元素的deque写法
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        // 队列非空且当前最小值将出去
        if (i > k && q.size() && q.front() == a[i - k])
            q.pop_front();
        // 即将进来的比队尾小，队尾出去
        while (q.size() && a[i] < q.back())
            q.pop_back();
        // 新来的元素加入
        q.push_back(a[i]);
        if (i >= k)
            cout << q.front() << ' ';
    }
    cout << endl;
    q.clear();
    for (int i = 1; i <= n; i++)
    {
        // 队列非空且当前最小值将出去
        if (i >= k && q.size() && q.front() == a[i - k])
            q.pop_front();
        // 即将进来的比队尾大，队尾出去
        while (q.size() && a[i] > q.back())
            q.pop_back();
        // 新来的元素加入
        q.push_back(a[i]);
        if (i >= k)
            cout << q.front() << ' ';
    }
    return 0;
}

// 下面是deque存放编号的写法

int main()
{
    cin >> n >> k;
    // 循环最好还是从1开始，因为当i第一次等于k之后，每次循环都要输出。而k是从1开始的
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // 先处理最小值
    for (int i = 0; i < n; i++)
    {
        // 队列非空且最小值元素移出窗口，弹出队首元素（我们的队列中只记录了当前最小以及可能的最小）
        if (!q.empty() && i - q.front() >= k)
            q.pop_front();
        // 一旦即将进入的元素比队尾小，则队尾出去
        while (q.size() && a[q.back()] > a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k - 1)
            cout << a[q.front()] << ' ';
    }
    cout << endl;
    q.clear();
    // 处理最大值
    for (int i = 0; i < n; i++)
    {
        if (q.size() && i - q.front() >= k)
            q.pop_front();
        while (q.size() && a[i] > a[q.back()])
            q.pop_back();
        q.push_back(i);
        if (i >= k - 1)
            cout << a[q.front()] << ' ';
    }
    return 0;
}