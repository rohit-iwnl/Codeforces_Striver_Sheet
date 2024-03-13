//https://codeforces.com/contest/514/problem/A
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(i==0 && ch>='5' && ch<'9') s[i]='9'-ch+'0';
        else if(i>0 && ch>='5') s[i] = '9'-ch+'0';
    }
    cout<<s;
}