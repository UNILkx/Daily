// 一个是暴力枚举，一个是深搜（y总讲的）
// 前面枚举不难，关键思想是分块给abc
// 深搜说一下注意点
// 1.注意搜索到某一步时，函数参数是什么意思
// 2.边界处理的时候可以加上一部分剪枝操作
// 3.a确定好后，开始找c时，不要深度+1，这是因为这一步并没有选择任何一个数！
// 4.当n在1e5,c在1e5时，c*n超出int范围，需要c转换成long long。比如输入为908时，会出现多的一组就是因为溢出导致的
// 5.check时一定要开临时数组，哪怕用length记录剩余数字也不行，因为b可能出现重复数字！

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 20;

int n;
int state[N]; // 记录是否选择
int que[N];   // 存放排列结果
int cnt;
// 先试试暴力全排列

// int calc(int start, int end) // 下标开始和结束位置
// {
//     int sum = 0;
//     for (int i = start; i <= end; i++)
//     {
//         sum = sum * 10 + que[i];
//     }
//     return sum;
// }

// void dfs(int now)
// {
//     // 排列完毕
//     if (now == 10)
//     {
//         int a, b, c;
//         for (int i = 1; i <= 7; i++)
//         {
//             for (int j = i + 1; j <= 8; j++)
//             {
//                 a = calc(1, i); //
//                 b = calc(i + 1, j);
//                 c = calc(j + 1, 9);
//                 if (b == n * c - a * c)
//                 {
//                     cnt++;
//                 }
//             }
//         }
//         return;
//     }

//     // 深搜，确定当前位置
//     for (int i = 1; i <= 9; i++)
//     {
//         if (!state[i]) // 当前位置还没有选
//         {
//             que[now] = i;
//             state[i] = 1;
//             dfs(now + 1);

//             // 还原现场
//             que[now] = 0;
//             state[i] = 0; // 这个其实可以不用，最后会覆写
//         }
//     }
//     return;
// }

// int main()
// {
//     cin >> n;
//     dfs(1);
//     cout << cnt << endl;
//     return 0;
// }

// 求 b=cn-ca;

// 另一种方法

int check(int now, int a, int c)
{
    // 当n=[1,1e6]，当n在1e5,c在1e5时，超出int范围，需要c转换成long long
    long long b = n * (long long)c - a * c;
    // if (!a || !b || !c)
    //     return 0;
    int length = 9 - now;
    int temp[N];
    memcpy(temp, state, sizeof(state));
    while (b) // 遍历每一位，如果该位为0或者已经被使用过，返回false
    {
        int x = b % 10; // 求出个位
        if (!x || temp[x])
            return 0;
        else
        {
            temp[x] = 1;
            length--;
            b /= 10;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!temp[i])
            return 0;
    }
    return 1;
    if (length)
        return 0;
    else
        return 1;
}

void dfs_c(int now, int a, int c)
{
    if (now > 9) // 9个数全排完,这里处理递归结束，是因为c确定b也确定了
        return;
    if (check(now, a, c))
        cnt++;
    for (int i = 1; i <= 9; i++)
    {
        if (!state[i])
        {
            state[i] = 1;
            dfs_c(now + 1, a, c * 10 + i);
            state[i] = 0;
        }
    }
}

void dfs_a(int now, int a)
{
    // 9个数全排完，以及剪枝——a占了8位(bc至少有一位)
    if (a >= n || a >= 1e7)
        return;
    // a找好了找c
    if (a)
        dfs_c(now, a, 0);

    for (int i = 1; i <= 9; i++)
    {
        if (!state[i]) // 当前这个数还没选
        {
            state[i] = 1;
            // 选上这个数，a*10+i
            dfs_a(now + 1, a * 10 + i);
            state[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs_a(0, 0);
    cout << cnt << endl;
    return 0;
}