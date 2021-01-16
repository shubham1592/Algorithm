#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int minCoins(int n, int coins[], int t, int dp[]){
    
    //base case
    if(n == 0){
        return 0;
    }
    
    //lookup
    if(dp[n] != 0){
        return dp[n];
    }

    //iterative case
    
    for (int i = 1; i <= n; i++){
        dp[i] = INT_MAX;
        for (int x = 0; x < t; x++){
            if (i - coins[x] >= 0){
                int subprob = dp[i - coins[x]];
                dp[i] = min(dp[i], subprob + 1);
            }
        }
    }
    return dp[n];
}

    int main()
{
    int n = 15;
    int coins[] = {1, 7, 10};
    int t = sizeof(coins) / sizeof(int);    
    int dp[100] = {0};
    cout << minCoins(n, coins, t, dp) << endl;
    return 0;
}