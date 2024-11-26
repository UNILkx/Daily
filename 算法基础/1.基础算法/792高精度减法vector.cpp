#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> a, b;
vector<int> ans;
// 参考了y总的代码优化了cmp函数，简洁很多
//  a>=b,1;a<b,0
int cmp(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}

void sub(vector<int> a, vector<int> b)
{
    int t = 0, c = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t = a[i] - c;
        if (i < b.size())
            t -= b[i];
        if (t < 0)
        {
            t += 10, c = 1;
        }
        else
            c = 0;
        ans.push_back(t);
    }
    while (ans.size() > 1 && !ans.back())
        ans.pop_back();
    return;
}

int main()
{
    string A, B;
    cin >> A >> B;
    // 将元素低位放在数组低位
    for (int i = A.size() - 1; i >= 0; i--)
        a.push_back(A[i] - '0');
    for (int i = B.size() - 1; i >= 0; i--)
        b.push_back(B[i] - '0');
    if (cmp(a, b))
        sub(a, b);
    else
        sub(b, a), cout << '-';

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    return 0;
}