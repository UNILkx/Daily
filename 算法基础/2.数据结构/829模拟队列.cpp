#include <iostream>
#include <string>

using namespace std;
const int N = 1e5 + 10;
int m;
int list[N], head = 0, tail = 0;

void list_push(int x)
{
    list[tail++] = x;
}

void list_pop()
{
    head++;
}

void list_empty()
{
    if (head == tail)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

void list_query()
{
    cout << list[head] << endl;
}

int main()
{
    cin >> m;
    string s;
    while (m--)
    {
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            list_push(x);
        }
        else if (s == "pop")
        {
            list_pop();
        }
        else if (s == "empty")
        {
            list_empty();
        }
        else if (s == "query")
        {
            list_query();
        }
    }

    return 0;
}