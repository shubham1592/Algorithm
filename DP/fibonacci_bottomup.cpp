#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int fiboBU(int n, int dp[]){

    //space : O(N)
    //time : O(N)

    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibo_SpaceOptimized(int n){

    //space : O(1)
    //time : O(N)

    if(n==0 || n==1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    int dp[100] = {0};
    //commment one of these out according to the need
    cout << fiboBU(n, dp) << endl;
    cout << fibo_SpaceOptimized(n) << endl;
    return 0;
}