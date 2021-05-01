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

    void DFS_helper(T src, map<T, bool> &visited){
        cout << src << " ";
        visited[src] = true;
        for(T nbrs : l[src]){
            if(!visited[nbrs]){
                DFS_helper(nbrs, visited);
            }
        }
    }

    void DFS(T src){
        map<T, bool> visited;
        for(auto x: l){
            T node = x.first;
            visited[node] = false;
            
            //call helper function
            DFS_helper(src, visited);
        }
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
    g.DFS(0);
    return 0;
}