#include <iostream>
#include <stack>

using namespace std;
const int N = 1e5 + 10;
stack<int> stk;
int n, m;
int ans[N]; // 存放答案
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        // 初始栈为空
        if (stk.empty())
        {
            // ans[i] = -1;
            cout << -1 << ' ';
        }
        else
        {
            // 如果大于栈顶元素，直接输出,并将m入栈
            if (m > stk.top())
            {
                // ans[i] = stk.top();

                cout << stk.top() << ' ';
            }
            // 新元素小于当前栈顶，则遍历栈,一边遍历一边将大于m的出栈
            else
            {
                while (!stk.empty() && stk.top() >= m)
                {
                    stk.pop();
                }
                // 如果遍历结束栈为空，输出-1
                if (stk.empty())
                    cout << -1 << ' ';
                else
                    cout << stk.top() << ' ';
            }
        }
        stk.push(m);
    }
    return 0;
}
