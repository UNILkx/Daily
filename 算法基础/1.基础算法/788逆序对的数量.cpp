#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n;
int op[N];
int temp[N];
long long ans;

void merge_sort(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (op[i] <= op[j])
            temp[k++] = op[i++];
        else // 此时op顺序，那么i后面的都比j大
        {
            temp[k++] = op[j++];
            ans += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        temp[k++] = op[i++];
    }

    while (j <= r)
        temp[k++] = op[j++];
    for (i = l, k = 0; i <= r; i++, k++)
        op[i] = temp[k];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> op[i];
    merge_sort(0, n - 1);
    cout << ans << endl;
    return 0;
}