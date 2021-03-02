#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n = 8;
    int a[] = {100, 5, 2, 3, 4, 9, 6, 10};
    int dp[1000] = {0};
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[i]>a[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int lis = 0;
    for (int i = 0; i < n; i++){
        //cout << dp[i] << " ";
        lis = max(lis, dp[i]);
    }
    cout << lis;
}