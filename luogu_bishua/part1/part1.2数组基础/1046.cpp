#include<bits/stdc++.h>
using namespace std;
int height[11]={0};
int ans=0,tall;
int main(){
    for(int i=0;i<10;i++) {
        cin>> height[i];
    }
    cin>>tall;
    for(int i=0;i<10;i++){
        if((tall+30)>=height[i] ) ans++;
    }
    cout<<ans<<endl;
    return 0;
}