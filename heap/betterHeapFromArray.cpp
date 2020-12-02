#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class heap{
    vector<int> v;
    bool minheap;
    
    bool compare(int a, int b){
        if(minheap){
            return a < b;
        }
        else{
            return a > b;
        }
    }

    void heapify(int idx){
        int left = 2 * idx;
        int right = left + 1;
        int min_idx = idx;
        int last = v.size() - 1;
        if(left <= last && compare(v[left],v[idx])){
            min_idx = left;
        }
        if(right <= last && compare(v[right],v[min_idx])){
            min_idx = right;
        }
        if(min_idx != idx){
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

    public:
        heap(int default_size = 10, bool type = true){
            v.reserve(default_size);
            v.push_back(-1);
            minheap = type;
        }

        void push(int d){
            v.push_back(d);
            int idx = v.size() - 1;
            int parent = idx / 2;
            while(idx > 1 and compare(v[idx],v[parent])){
                swap(v[idx], v[parent]);
                idx = parent;
                parent = parent / 2;
            }
        }

        int top(){
            return v[1];
        }

        void pop(){
            int last = v.size() - 1;
            swap(v[1], v[last]);
            v.pop_back();
            heapify(1);
        }

        bool empty(){
            return v.size() == 1;
        }
};

bool compare(int a, int b){
    return a > b;
    }

void heapify2(vector<int> &v, int idx){
    int left = 2 * idx;
    int right = left + 1;
    int min_idx = idx;
    int last = v.size() - 1;
    if(left <= last && compare(v[left],v[idx])){
        min_idx = left;
    }
    if(right <= last && compare(v[right],v[min_idx])){
        min_idx = right;
    }
    if(min_idx != idx){
        swap(v[idx], v[min_idx]);
        heapify2(v, min_idx);
    }
}

void buildHeap(vector<int> &v){
    int n = v.size();
    for (int i = 2; i < n; i++){
        int idx = i;
        int parent = i / 2;
        while(idx>1 && v[idx]>v[parent]){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

void buildHeapOptimised(vector<int> &v){
    int n = v.size();
    for (int i = (n - 1) / 2; i >= 1; i--){
        heapify2(v,i);
    }
}

void print(vector<int> v){
    int n = v.size();
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}

int main(){
    // //take input the elements of the heap
    // heap h(10,false);
    // //h(10,false) is meant to initialize a max_heap of size 10
    // //to make min_heap, remove false. i.e. h(10) or simple heap h;
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++){
    //     int no;
    //     cin >> no;
    //     h.push(no);
    // }

    // //remove all the elements from the heap and show output
    // while(!h.empty()){
    //     cout << h.top() << " ";
    //     h.pop();
    // }

    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    buildHeapOptimised(v);
    cout << endl;
    print(v);

    return 0; 
}