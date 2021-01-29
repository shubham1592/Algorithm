#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int maxSum(int a[], int n){
    int dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    int cmax = dp[0];
    for (int i = 1; i<n; i++){
        dp[i] = dp[i - 1] + a[i];
        if(dp[i]<0){
            dp[i] = 0;
        }
        cmax = max(dp[i], cmax);
    }
    return cmax;
}

int main(){
    int arr[] = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    int n = sizeof(arr) / sizeof(int);
    cout << maxSum(arr, n) << endl;
    return 0;
}