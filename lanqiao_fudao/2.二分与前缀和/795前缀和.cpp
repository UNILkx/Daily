// 差分和前缀很很类似哦
// 差分数组是统计相邻元素的关系，通过顺序遍历最后得到原始数组
// 前缀和则是统计前面所有元素的和，通过顺序遍历前缀和数组，相邻两项相减得到原始数组

#include <iostream>

using namespace std;

const int N = 1E5 + 10;
int n, m;
int a[N];
int pre[N]; // 前缀和

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // 到i为止前面元素和，包括i
        pre[i] = pre[i - 1] + a[i];
    }
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}