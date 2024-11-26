#include <bits/stdc++.h>

// #define inputtxt

using namespace std;

vector<string> input, output;

int len; // 字符串长度
int T;
long long cnt;

int compare(string a, string b)
{
    int len = min(a.size(), b.size());
    int num = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == b[i])
            num++;
    }
    // cout << num << endl;
    return num;
}

int main()
{
// freopen
#ifdef inputtxt
    freopen("input.txt", "r", stdin);
#endif
    // 输入
    string s;
    while (getline(cin, s))
    {
        string s1;
        if (s == "EOF")
            break;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '<' && s1.size())
                s1.pop_back();
            else if (s[i] == '<' && s1.size() == 0)
                continue;
            else
                s1.push_back(s[i]);
        }
        input.push_back(s1);
    }
    while (getline(cin, s))
    {
        string s1;
        if (s == "EOF")
            break;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '<' && s1.size())
                s1.pop_back();
            else if (s[i] == '<' && s1.size() == 0)
                continue;
            else
                s1.push_back(s[i]);
        }
        output.push_back(s1);
    }
    for (int i = 0; i < input.size(); i++)
    {
        // cout << i << " ";
        cnt += compare(input[i], output[i]);
    }
    cin >> T;
    cout << round((double)cnt / T * 60) << endl;
#ifdef inputtxt
    fclose(stdin);
#endif
    return 0;
}