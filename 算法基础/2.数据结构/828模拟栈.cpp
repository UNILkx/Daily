#include <iostream>
#include <string>

using namespace std;
const int N = 1e5 + 10;

int m;
int str[N];
int len;
int res;
void stack_push(int x)
{
    str[len++] = x;
}
void stack_pop()
{
    int ans = str[len - 1];
    len--;
}
bool stack_empty()
{
    if (!len)
        return 1;
    return 0;
}
// 查询栈顶
int stack_query()
{
    return str[len - 1];
}
int main()
{
    string a;
    cin >> m;
    while (m--)
    {
        cin >> a;
        if (a == "push")
        {
            int x;
            cin >> x;
            stack_push(x);
        }
        else if (a == "pop")
        {
            stack_pop();
        }
        else if (a == "empty")
        {
            if (stack_empty())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (a == "query")
        {
            cout << stack_query() << endl;
        }
    }
    return 0;
}
