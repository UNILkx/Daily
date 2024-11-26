#include<bits/stdc++.h>
using namespace std;

int n,m,k,day[1005][1005],vs[1005][1005];
int ans[1005]={0};
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>day[i][j];
        }
    }
    
   for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vs[j][day[i][j]])   {
                vs[j][day[i][j]]=1;
                ans[day[i][j]]++;
            }
        }  
   }
   
  for(int i=1;i<=k;i++){
    cout<<ans[i]<<" ";
  }
    return 0;
}