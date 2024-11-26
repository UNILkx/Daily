#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int temp[N], op[N];

void merge_sort(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (op[i] <= op[j])
            temp[k++] = op[i++];
        else if (op[j] < op[i])
            temp[k++] = op[j++];
    }
    // 下面是可能出现分治的两个数组中有一个提前结束的处理
    while (i <= mid)
        temp[k++] = op[i++];
    while (j <= r)
        temp[k++] = op[j++];

    // 将当前完成[l,mid][mid,r]排序的数组赋值到op中，不然无法保证递归返回后的op是有序的
    for (i = l, j = 0; i <= r; i++, j++)
        op[i] = temp[j];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> op[i];

    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    return 0;
}