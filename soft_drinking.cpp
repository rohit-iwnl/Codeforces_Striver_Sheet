//https://codeforces.com/problemset/problem/151/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //3 4 5 10 8 100 3 1
    //n, k, l, c, d, p, nl, np
    int n, k, l, c, d, p, nl, np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;


    int total_drinks = (k*l)/nl;
    int total_limes = c * d;
    int total_salt = p/np;

    int rounds = min(total_drinks,min(total_limes,total_salt))/n;

    cout<<rounds;


}