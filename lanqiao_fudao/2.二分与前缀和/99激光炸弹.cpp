/*
这题槽点有点多。。。
1.不能用单行前缀和。在后续求rxr值时会超时
2.根据1，应该改用二维前缀和。但是由于输入的左边可能为(0,0)，为了方便求前缀和，应当在输入时对坐标+1处理
3.求二维前缀和时，可以结合效果考虑哦，即(i,j)包括左上角（和他自己）的所有值的和。
4.输入问题。可能输入的r过大（大于5001），甚至大于后面的max_x,max_y，此时可以直接输出最右下角的值；
  但是如果r大于其中1个而小于另外一个，此时就会出现问题.
5.针对第四点后面一种情况，需要在初始时，将max_x,max_y设置为r。

此外，有一点比较怪，测试 10000 500的这一组数据，为什么初始化max_x,max_y=0也不行？
后续遍历时，进行了这样的处理，i = min(r, max_x)也行不通
*/

#include <iostream>

using namespace std;
const int N = 5e3 + 10;

int n, r;
int martix[N][N];

int main()
{
    cin >> n >> r;
    int max_x, max_y;
    r = min(r, 5001);
    max_x = max_y = r;
    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        // 下标+1方便计算前缀和
        x++, y++;
        martix[x][y] += w;
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    // 下面求每行的前缀和
    // for (int i = 1; i <= max_x; i++)
    // {
    //     for (int j = 1; j <= max_y; j++)
    //     {
    //         martix[i][j] += martix[i][j - 1];
    //     }
    // }

    // 应当改成求二维的矩阵和
    for (int i = 1; i <= max_x; i++)
    {
        for (int j = 1; j <= max_y; j++)
        {
            martix[i][j] += martix[i - 1][j] + martix[i][j - 1] - martix[i - 1][j - 1];
        }
    }
    // 查看二维前缀和数组
    // for (int i = 1; i <= max_x; i++)
    // {
    //     for (int j = 1; j <= max_y; j++)
    //     {
    //         cout << martix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int res = 0;
    if (r > 5001)
    {
        cout << martix[max_x][max_y] << endl;
        return 0;
    }

    // 此时以 r X r 矩阵的右下角进行遍历
    for (int i = min(r, max_x); i <= max_x; i++)
    {
        for (int j = min(r, max_y); j <= max_y; j++)
        {
            res = max(res, martix[i][j] - martix[i - r][j] - martix[i][j - r] + martix[i - r][j - r]);
        }
    }

    // 显然会超时
    // for (int i = 0; i <= max_x - r; i++)
    // {
    //     for (int j = 0; j <= max_y - r; j++)
    //     {
    //         int sum = 0;
    //         for (int k = i; k < i + r; k++)
    //         {
    //             sum = sum + martix[k][j + r - 1] - martix[k][j];
    //         }
    //         res = max(res, sum);
    //     }
    // }
    cout << res << endl;

    return 0;
}