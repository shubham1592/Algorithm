#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void kreverse(list<int> l, int k){
    if(l.size() != 0){
        for(auto it = l.begin(); it<l.begin()+k; it++)
    }
}

int main(){
	int d, n, k;
	cin>>n>>k;
	list <int> l;
    for(int i=0; i<n; i++){
        cin>>d;
        l.push_back(d);
    }
	for(auto it = l.begin(); it != l.end(); it++){
        cout<<*it<<" ";
    }
}