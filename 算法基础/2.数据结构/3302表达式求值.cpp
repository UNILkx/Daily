#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

stack<char> op; // 操作符号

stack<int> va; // 操作数

void eval()
{
    int b = va.top();
    va.pop();
    int a = va.top();
    va.pop();
    char c = op.top();
    op.pop();
    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else if (c == '/')
        x = a / b;
    va.push(x);
}
int main()
{
    unordered_map<char, int> pr =
        {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; // 优先级
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        auto c = s[i];
        // isdigit检查字符是否是十进制数字字符
        if (isdigit(c)) // 是数字字符，可能多位
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j] - '0';
                j++;
            }
            i = j - 1;
            va.push(x);
        }
        else if (c == '(')
            op.push(c);
        else if (c == ')') // 此时收束？应该执行前面所有的到(的符号
        {
            while (op.top() != '(')
                eval();
            op.pop(); // 弹出op栈顶的'('
        }
        else // 除了数字和括号外的操作符
        {
            // 每次进来，应该判断当前位置需不需要进行计算
            // 如果栈顶操作符的优先级大于当前符号，就计算栈顶的，随后将该符号入栈
            while (!op.empty() && op.top() != '(' && pr[op.top()] >= pr[c])
                eval();
            op.push(c);
        }
    }
    while (op.size())
        eval();
    cout << va.top() << endl;
    return 0;
}