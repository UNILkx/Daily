/*
费解的开关：第一行的确定后下面操作固定，此时枚举第一行所有情况再分别分析即可
飞行员：数据规模较少，且由于开关关联较多所以直接暴力枚举
翻硬币：（注意，此题每一步操作是翻转相邻的两个硬币，而不是翻转它以及相邻的两个硬币共三个）
此题类似费解的开关，但是只有唯一解（重复操作不算），所以直接遍历即可*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;
char str[N];
char tar[N];
int step;

void turn(int now)
{
    if (str[now] == '*')
        str[now] = 'o';
    else
        str[now] = '*';
    if (str[now + 1] == '*')
        str[now + 1] = 'o';
    else
        str[now + 1] = '*';
}

int main()
{
    cin >> str >> tar;
    int length = strlen(str);
    // cout << length;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == tar[i])
            continue;
        else
        {
            turn(i);
            step++;
        }
    }
    cout << step;
    return 0;
}