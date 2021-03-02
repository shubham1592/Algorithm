#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int cell_mitosis( int x, int y, int z, int n){
    int dp[1000] = {0};
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++){
        if(i%2 == 0){
            dp[i] = min((dp[i / 2] + x), dp[i-1]+y);
        }
        else{
            dp[i] = min((dp[i - 1] + y), dp[(i + 1) / 2] + x + z);
        }
    }
    return dp[n];
}

int main(){
    int x, y, z, n;
    cout << "Enter the element: " << endl;
    cin >> n;
    cout << "Enter the cost of doubling, increment and decrement: " << endl;
    cin >> x >> y >> z;
    cout << "The min cost is : "<< cell_mitosis(x, y, z, n) << endl;
}