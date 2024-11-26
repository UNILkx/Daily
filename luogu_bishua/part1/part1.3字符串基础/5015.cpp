#include<bits/stdc++.h>
using namespace std;

string str;
int ans;
int main(){
    getline(cin,str);
    for(int i=0;i<=str.size();i++){
            if(str[i]>='a' && str[i]<='z') {ans++;continue;}
            if(str[i]>='A' && str[i]<='Z') {ans++;continue;}
            if(str[i]>='0' && str[i]<='9') ans++;
    }
    cout<<ans<<endl;
    return 0;
}