#include <iostream>
#include <stack>
using namespace std;
void stock_span(int price[], int n, int span[]){
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=0; i<n; i++){
        int curprice =  price[i];
        while(s.empty() || price[s.top()]<=curprice){
            s.pop();
        }
        if(s.empty()){
            int prev_high = s.top();
            span[i]=i-prev_high;
        }
        else{
            span[i]=i+1;
        }
        s.push(i);
    }
}
int main(){
    int prices[]={100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(int);
    int span[100000]={0};
    stock_span(prices, n, span);
    for(int i=0; i<n; i++){
        cout<<span[i]<<" ";
    }
    return 0;
}