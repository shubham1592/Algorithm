#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class graph{
    unordered_map<string, list<pair<string, int>>> l;

public:
    void addEdge(string x, string y, bool bidirr, int wt){
        l[x].push_back(make_pair(y, wt));
        if(bidirr){
            l[y].push_back(make_pair(x, wt));
        }
    }
    void printGraph(){
        for(auto cl : l){
            string city = cl.first;
            list<pair<string, int>> nbrs = cl.second;
            cout << city << " -> ";
            for(auto nbr : nbrs){
                string dest = nbr.first;
                int dist = nbr.second;
                cout << dest << " " << dist << ", " ;
            }
            cout << endl;
        }
    }
};

int main(){
    graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("A", "C", true, 10);
    g.addEdge("A", "D", false, 50);
    g.addEdge("B", "D", true, 30);
    g.addEdge("C", "D", true, 40);
    g.printGraph();
}