#include<bits/stdc++.h>
#include<iostream>
using namespace std;


// M1 : Top Down approach

int minstepsTD(int n, int dp[]){
    //base case
    if(n==1){
        return 0;
    }

    //lookup
    if(dp[n]!=0){
        return dp[n];
    }
    
    //rec case
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;

    //div by 2
    if(n%2==0){
        op1 = minstepsTD(n / 2, dp);
    }

    //div by 3
    if(n%3==0){
        op2 = minstepsTD(n / 3, dp);
    }

    //div by niether 2 nor 3
    op3 = minstepsTD(n - 1, dp);

    int ans = min(op1, min(op2, op3)) + 1;
    return dp[n] = ans;
}

// M2 : Bottom Up approach

int minstepsBU(int n, int dp[]){
    if(dp[n]!=0){
        return dp[n];
    }
    for (int i = 2; i <= n; i++){
        int op1, op2, op3;
        op1 = op2 = op3 = INT_MAX;

        //div by 2
        if(i%2==0){
            op1 = dp[i / 2];
        }
        //div by 3
        if(i%3==0){
            op2 = dp[i / 3];
        }
        //div by neither 2 nor 3
        op3 = dp[i - 1];

        dp[i] = min(op1, min(op2, op3)) + 1;
    }
    return dp[n];
}

int main(){
    int dp[1000] = {0};
    int n;
    cin >> n;
    
    // comment out one of these
    cout << "bottom up : " << minstepsBU(n, dp) << endl;
    cout << "top down : " << minstepsTD(n, dp) << endl;

    return 0;
}