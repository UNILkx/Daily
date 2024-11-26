//第一反应就是邻接矩阵，可惜忘记了folyd算法hhh
//后面就是对高精的一个处理了
#include<bits/stdc++.h>
using namespace std;
string n;       //n:0~10e30>>long long 
int k;
int num[11]={0},kind[11]={0};
int ans[1000]={0};
int g[11][11]={0};  //[0~9][1~9]
int sour,des;       //0~9  1~9


int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>sour>>des;
        g[sour][des]=1;
    }
    //folyd算法得到邻接矩阵
    for(int j=1;j<=9;j++)
        for(int i=0;i<=9;i++)
            for(int k=1;k<=9;k++){
                if(g[i][j]&&g[j][k]) g[i][k]=1;
            }
    for(int i=0;i<=9;i++){
        g[i][i]=1;
        for(int j=0;j<=9;j++){
            if(g[i][j])
                kind[i]++;   //该数字的变化种类
        }
        //cout<<kind[i]<<endl;
    }
    //下面统计每个数字出现次数
    ans[0]=1;
    int c=0;//进位
    for(int i=0;n[i];i++){
        int x=kind[n[i]-'0'];//数字变化种类
        c=0;
        for(int j=0;j<500;j++){
            ans[j]=ans[j]*x+c;
            c=ans[j]/10;
            ans[j]%=10;
        }
    }
    int len=500;
    while(ans[len]==0) len--;
    for(int i=len;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
