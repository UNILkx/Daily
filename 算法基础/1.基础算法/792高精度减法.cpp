// 当前代码没有进行优化，后面用vector写一份。这个题坑有点多，主要的坑点在于：
// 1.两个数的大小比较，根据长度可以快速比较，当长度相等则需要逐个比较
// 2.两个数相减的借位问题，这是高精度问题都要处理的
// 3.当结果全为0或者高位多个连续0时，需要处理！！！
// 4.

#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];
int ans[N];
int len_a, len_b, len_ans;
int mask;
void sub(int A[], int B[], int lena, int lenb) // a长度，b长度，当a<b时会转换成b-a
{
    int i = 0, t = 0, c = 0;
    for (i = 0; i < lena; i++)
    {
        if (i < lenb) // 两个数位数相同的部分
            t = A[i] - B[i] - c;
        else // A的高位部分
            t = A[i] - c;
        if (t < 0)
        {
            t += 10;
            c = 1;
        }
        else
            c = 0;
        // cout<<i<<' '<<t<<endl;
        ans[len_ans++] = t;
    }

    // cout<<len_ans<<endl;
    return;
}

int main()
{
    string A, B;
    cin >> A >> B;
    len_a = A.size(), len_b = B.size();
    // cout<<len_a<<' '<<len_b<<endl;
    //  逆序存储，数字低位放数组低位
    for (int i = 0; i < len_a; i++)
        a[i] = A[len_a - 1 - i] - '0';
    for (int j = 0; j < len_b; j++)
        b[j] = B[len_b - 1 - j] - '0';
    //         cout<<a[0]<<endl;
    // cout<<b[0]<<endl;
    if (len_a == 1 && a[0] == 0)
    {
        cout << '-' << B;
        return 0;
    }

    if (len_b == 1 && b[0] == 0)
    {
        cout << A;
        return 0;
    }
    if (len_a > len_b)
        mask = 1;

    else if (len_a == len_b)
    {
        for (int i = len_a - 1; i >= 0; i--)
        {
            if (a[i] > b[i])
            {
                mask = 1;
                break;
            }
            else if (a[i] < b[i])
            {
                mask = 0;
                break;
            }
        }
    }
    else if (len_a < len_b)
        mask = 0;
    if (mask)
    {
        sub(a, b, len_a, len_b);
    }
    else
    {
        sub(b, a, len_b, len_a);
        cout << '-';
    }
    int flag = 1;
    for (int i = len_ans - 1; i >= 0; i--)
    {
        if (flag && !ans[i])
        {
            if (!i)
                cout << 0;
            continue;
        }
        else
        {
            flag = 0;
            cout << ans[i];
        }
    }

    return 0;
}