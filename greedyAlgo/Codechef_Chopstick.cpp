#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int pairup(vector<int> sticks, int n, int d){
    int ans=0;
    sort(sticks.begin(), sticks.end());
    for(int i=0; i<n;){
        if(abs(sticks[i]-sticks[i+1])<=d){
            ans++;
            i=i+2;
        }
        else{
            i=i+1;
        }
    }
    return ans;
}


int main() {
	int n, d;
	cin>>n>>d;
    vector<int> sticks(n,0);
	for(int i=0; i<n; i++){
	    cin>>sticks[i];
	}
	cout<<pairup(sticks, n, d);
	return 0;
}
