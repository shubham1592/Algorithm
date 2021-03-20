#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[10000];

int ways(int a){

    //base case
    if(a==0){
        return -1;
    }
    if(a==1 || a==2){
        dp[a] = a;
        return a;
    }
    //look up
    if(dp[a] != 0){
        return dp[a];
    }

    //rec case
    return ways(a - 1) + (ways(a - 2) * (a - 1));
}

int main(){
    //driver code
    int n;
    cin >> n;
    cout << ways(n) << endl;
    return 0;
}