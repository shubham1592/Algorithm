#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKsortedArray(vector<vector<int>> &arr){

    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;

    for (int i = 0; i < arr.size(); i++){
        pq.push({arr[i, 0], {i, 0}});
    }

    while(!pq.empty()){
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;
        int y = current.second.second;
        result.push_back(element);

        if(y+1<arr[x].size()){
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main(){
    vector<vector<int>> arr{{1, 2, 6, 7, 9},
    {3, 4, 5, 8},
    {12, 15},
    {9, 10, 11, 13, 14}};

    vector<int> output = mergeKsortedArray(arr);
    for(auto x:output){
        cout << x << " ";
    }
}