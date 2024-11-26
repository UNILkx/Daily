#include<bits/stdc++.h>
using namespace std;

string str,tar;
int len_str,len_tar;
int incount=0,local=-1;
int check(int n){
    int now=n,flag_start=0,flag_end=0;
    if(now!=0&&str[now-1]!=' ') return n+1;   
    for(int i=0;i!=len_tar;i++){
        if(str[now]==tar[i]||(str[now]+32)==tar[i]||(str[now]-32)==tar[i]) now++;
        else return n+1;
    }
    if(str[now]!=' ') return n+1;
    incount++;
    if(local==-1){
        local=n;
    }
    return n+len_tar;
}

int main(){
    getline(cin,tar);
    getline(cin,str);
    len_tar=tar.size(),len_str=str.size();
    for(int i=0;i!=len_str;){
        if(str[i]==tar[0]||(str[i]+32)==tar[0]||(str[i]-32)==tar[0]) i=check(i);
        else i++;
    }
    if(!incount) cout<<"-1"<<endl;
    else {
        cout<<incount<<" "<<local<<endl;
    }
    return 0;
}

