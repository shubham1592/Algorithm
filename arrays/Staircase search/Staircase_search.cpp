#include <iostream>
using namespace std;
int main() {
    int m,n,k;
    int a[1000][1000]={0};

// taking input
    cin>>m>>n>>k;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }

//staircase search
    int i=0;
    int j=n-1;
    int ans=0;
    while(i<n && j>=0){
        if(k>a[i][j]){
            i=i+1;
        }
        else if(k<a[i][j]){
            j=j-1;
        }
        else if(k==a[i][j]){
            ans=1;
            break;
        }
    }

//final check condition
    if(ans==1){
        cout<<"ELEMENT FOUND at a["<<i<<"]["<<j<<"]"<<endl;
    }
    else{
        cout<<"ELEMENT NOT FOUND"<<endl;
    }
}
