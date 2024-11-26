#include <iostream>
#include <map>

using namespace std;
// map<string, int> mp;
// int n;
// // map实现
// int main()
// {
//     cin >> n;
//     while (n--)
//     {
//         char c;
//         cin >> c;
//         string s;
//         cin >> s;
//         if (c == 'I')
//         {
//             mp[s]++;
//         }
//         else if (c == 'Q')
//         {
//             cout << mp[s] << endl;
//         }
//     }
//     return 0;
// }
// trie树实现
int n;
const int N = 1e5 + 10;
int trie[N][26], cnt[N], idx; // 第一维代表字典树第几层（非线性），第二维代表是哪个字母

void insert(char s[])
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int u = s[i] - 'a';
        if (!trie[p][u])
            trie[p][u] = ++idx;
        p = trie[p][u]; // 保证下一层和上一层的连接
    }
    // 记录字符串出现次数
    cnt[p]++;
}

void query(char s[])
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int u = s[i] - 'a';
        // 找不到
        if (!trie[p][u])
        {
            cout << "0" << endl;
            return;
        }
        p = trie[p][u];
    }
    cout << cnt[p] << endl;
}

int main()
{
    cin >> n;
    while (n--)
    {
        char c;
        cin >> c;
        char s[N];
        cin >> s;
        if (c == 'I')
            insert(s);

        if (c == 'Q')
            query(s);
    }
    return 0;
}