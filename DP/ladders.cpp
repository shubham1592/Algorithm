#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int ladders_top_down(int n, int k, int dp[]){
    //base case
    if(n==0){
        return 1;
    }

    //look up
    if(dp[n]!=0){
        return dp[n];
    }

    //recursive case
    int ways = 0;
    for (int i = 1; i <= k; i++){
        if(n-i>=0){
            ways += ladders_top_down(n - i, k, dp);
        }
    }
    return dp[n] = ways;
}

int ladders_bottom_up(int n, int k){
    int dp[100] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        dp[i] = 0;
        for (int j = 1; j <= k; j++){
            if(i-j>=0){
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}

int main(){
    int n, k;
    int dp[100] = {0};
    cin >> n >> k;
    cout << "Top down ways: " << ladders_top_down(n, k, dp) << endl;
    cout << "Bottom up ways: " << ladders_bottom_up(n, k) << endl;
    return 0;
}