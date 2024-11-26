#include<bits/stdc++.h>
using namespace std;

int n;
bool compare(string a,string b){
    return a+b>b+a;
}
int main(){
    string str[21];
    cin>>n;
    for(int i=0;i<n;i++) cin>>str[i];
    sort(str,str+n,compare);
    for(int i=0;i<n;i++) cout<<str[i];
    return 0;
}