//https://codeforces.com/problemset/problem/263/A
#include <bits/stdc++.h>

using namespace std;

int main(){
    int rows,cols,moves;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int x;
            cin>>x;
            if(x==1){
                rows = i+1;
                cols = j+1;
            }
        }
    }

    moves = abs(rows-3) + abs(cols-3);
    cout<<moves;
}