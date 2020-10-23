#include <iostream>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int a[m][n], trans[100][100];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
//reversal
    for(int i=0; i<m; i++){
        int start=0;
        int end=n-1;
        while(start<end){
            swap(a[i][start],a[i][end]);
            start++;
            end--;
        }
    }
//transpose
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
                trans[j][i] = a[i][j];
        }
    }
//print final array
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
}
