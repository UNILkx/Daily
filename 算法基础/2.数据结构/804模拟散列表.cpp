#include <iostream>
#include <unordered_map>
using namespace std;

// 偷个懒，顺便试一下unordered_map的使用
unordered_map<int, int> mp;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char c;
        cin >> c;
        if (c == 'I')
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        else if (c == 'Q')
        {
            int x;
            cin >> x;
            if (mp.count(x))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}