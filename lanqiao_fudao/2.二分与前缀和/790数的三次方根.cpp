#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

double num;

// 这个是正经的二分搜索

int main()
{

    cin >> num;
    double l = -10000.0, r = 10000.0;
    while (r - l > 1e-7)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= num) // 在左边
            r = mid;
        else
            l = mid;
    }
    printf("%.6lf", l);

    return 0;
}

/*下面是使用自带的方法，cbrt(三次开根)cube，二次是sqrt，多次是pow
int main()
{
    double num;
    cin >> num;
    //方法1，使用pow+.6lf
    //注意到，c++中pow函数对于负底数，结果都是未知的，此时需要转化成绝对值
    //但是pow可以使用非整数的指数，
    if(num>0)
        printf("%.6lf",pow(num,1.0/3));
    else {
        printf("%.6lf",-pow(-num,1.0/3));
    }
    //方法2，使用cbrt+.6lf
    printf("%.6lf", cbrt(num));
    //方法3,使用c++中fixed和setprecision（设置精确度）+cbrt实现
    cout << fixed << setprecision(6) << cbrt(num) << endl;

    return 0;
}
*/
