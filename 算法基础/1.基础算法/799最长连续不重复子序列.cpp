#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int n, len, l, r, res;
int str[N];

// 尝试用vector实现hash
#include <vector>
#include <algorithm>
vector<pair<int, int>> h;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> str[i];

    for (int l = 1, r = 1; r <= n; r++)
    {

        // auto it = find_if(h.begin(), h.end(), str[r]);
        // 这个是返回第一个找到的函数，所以需要删除
        //[](){}，这是个lambda表达式
        // 由于vector的查找是O(n)数量级，所以11e5的数量级会超时
        auto it = find_if(h.begin(), h.end(), [r](const pair<int, int> &p)
                          { return p.first == str[r]; });
        if (it != h.end()) // 找到相同的
        {                  // 更新左边
            l = max(l, it->second + 1);
            // 删除左边元素
            // erase删除范围是[l,r),我们需要删除与str[r]相同的第一个元素，所以+1
            h.erase(h.begin(), it + 1);
        }
        len = max(len, r - l + 1);
        // 右边写入
        h.push_back({str[r], r});
    }
    cout << len;
    return 0;
}

// // 尝试用hash表简化时间复杂度
// #include <unordered_map>

// unordered_map<int, int> h;
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> str[i];

//     for (int l = 1, r = 1; r <= n; r++)
//     {
//         // 这个find其实也可以用vector实现
//         if (h.find(str[r]) != h.end()) // 在当前的hash表中找到了重复元素，则将i更新为该元素的后一位
//             // 由于h[str[r]]覆写了重复的，所以不用担心重复的问题
//             l = max(l, h[str[r]] + 1);
//         // 更新最大长度
//         len = max(len, r - l + 1);
//         // 将{str[r],r}写入hash表
//         h[str[r]] = r;
//     }
//     cout << len;
//     return 0;
// }

// // 暴力求解，但是会超时
// int main()
// {
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//         cin >> str[i];

//     int flag = 0;
//     for (l = 1; l <= n;)
//     {
//         len = 1;
//         for (r = l + 1; r <= n; r++)
//         {
//             for (int i = l; i < r; i++)
//             {
//                 // 出现重复
//                 if (str[i] == str[r])
//                 {
//                     flag = i;
//                     break;
//                 }
//             }
//             if (!flag)
//                 len++;
//             res = max(res, len);
//             // cout << "l:" << l<<" r:"<<r <<" flag:"<<flag<< " len:" << len << endl;

//             if (flag) // 修改指针,从重复位置重新开始寻找
//             {
//                 l = flag;
//                 flag = 0;
//                 break;
//             }
//         }
//         if (r == n + 1)
//             break;
//     }
//     res = max(res, len);
//     cout << res;
//     return 0;
// }