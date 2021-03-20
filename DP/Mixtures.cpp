#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[1000];
int dp[1000][1000];

int sum(int s, int e){
    int ans = 0;
    for (int i = s; i <= e; i++){
        ans += a[i];
        ans %= 100;
    }
    return ans;
}

int mixtures(int start, int end){
    //BASE CASE
    if(start >= end){
        return 0;
    }

    //DP LOOKUP
    if(dp[start][end] != -1){
        return dp[start][end];
    }

    //REC CASE
    dp[start][end] = INT_MAX;
    for (int k = start; k <= end; k++){
        dp[start][end] = min(dp[start][end], mixtures(start, k) + mixtures(k + 1, end) + (sum(start, k) * sum(k + 1, end)));
    }
    return dp[start][end];
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j] = -1;
        }
    }
    cout << mixtures(0, n - 1) << endl;
    return 0;
}