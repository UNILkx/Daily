#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1E5 + 10;
// a[0]最高位
// char a[N];
// char b[N];
// a[0]最低位

vector<int> x, y;

vector<int> imul(vector<int> &x, vector<int> &y)
{
    vector<int> z(x.size() + y.size() + 10, 0);
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < y.size(); j++)
        {
            z[i + j] += x[i] * y[j];
        }
    }
    int t = 0; // 进位处理中间值
    for (int i = 0; i < z.size(); i++)
    {
        t = t + z[i]; // 原先值+进位
        z[i] = t % 10;
        t /= 10;
    }
    // 这种处理前缀0的方式要记住
    while (z.size() > 1 && z.back() == 0)
        z.pop_back();
    return z;
}

int main()
{
    string a, b;
    cin >> a >> b;

    // 从数据的低位开始放到数组中
    for (int i = a.size() - 1; i >= 0; i--)
        x.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        y.push_back(b[i] - '0');

    auto z = imul(x, y);
    for (int i = z.size() - 1; i >= 0; i--)
        cout << z[i];

    return 0;
}