// p,q互质（可用辗转相除法gcd求互质），则最大不能组合的数为(p-1)(q-1)-1
// 如何打表找规律？
// 循环i[1,1e5],逐渐分别递归减去q,p，当最后i<q&&i<p且i!=0时，i就是不可组成的数

#include <iostream>

using namespace std;

int p, q;

int main()
{
    cin >> p >> q;
    cout << (p - 1) * (q - 1) - 1 << endl;
    return 0;
}