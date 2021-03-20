#include<bits/stdc++.h>
#include<iostream>
using namespace std;

template <typename T>
class graph{
    map<T, list<T>> l;
public:
    void addEdge(T x, T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void BFS(T src){
        map<T, int> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout << node << " ";
            for(auto nbr : l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    //mark it true as it is already pushed
                    visited[nbr] = true;
                }
            }
        }
    }
};
int main(){
    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.BFS(0);
    return 0;
}