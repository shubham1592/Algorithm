#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class graph{
    list<int> *l;
    int V;

public:
    graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        //Directed unweighted graph
        l[x].push_back(y);
    }
    
    void topological_Sort(){
        int *indegree = new int[V];
        for (int i = 0; i < V; i++){
            indegree[i] = 0;
        }
        //Update indegree by traversing each edge now
        for (int i = 0; i < V; i++)
        {
            for(auto y:l[i]){
                indegree[y]++;
            }
        }

        queue<int> q;
        //1. BFS
        //2. Find the nodes with 0 indegree and traverse
        for (int i = 0; i < V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            cout << node << " ";
            q.pop();

            for(auto nbr : l[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
};

int main(){
    graph g(6);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(3, 5);
    g.topological_Sort();
    return 0;
}