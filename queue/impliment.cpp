#include<iostream>
using namespace std;

class queue{
    
//declaring basic static variables and a dynamic array
    int *arr;
    int f, r, cs, ms;

public:

//creating a constructor for the queue
    queue(int ds = 5){
        arr = new int(ds);
        cs = 0;
        ms = ds;
        f = 0;
        r = ms-1;
    }

//to check if the queue is full
    bool full(){
        return cs==ms;
    }

//to push the element in the queue starting from rear
    void push(int data){
        if(!full()){
            r = (r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }

//to check if the queue is empty
    bool empty(){
        return cs==0;
    }

//to delete the entry at front, maintaining FIFO
    void pop(){
        if(!empty()){
            f = (f+1)%ms;
            cs--;
        }
    }

//to view the front most element in the queue
    int front(){
        return arr[f];
    }

//deconstructor to release memory
    ~queue(){
        if(arr != NULL){
            delete [] arr;
            arr = NULL;
        }
    }
};

int main(){
    queue q;
    for(int i=1; i<8; i++){
        q.push(i);
    }
    q.pop();
    q.pop();
    q.push(10);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }cout<<endl;
}