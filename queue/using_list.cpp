#include<iostream>
#include <list>
using namespace std;

class queue{
    int cs = 0;
    list<int> l;

public:
    queue(){
        cs = 0;
    }

    bool isempty(){
        return cs == 0;
    }
    
    void push(int data){
        l.push_back(data);
        cs = cs + 1;
    }

    void pop(){
        if(!isempty()){
            l.pop_front();
            cs = cs - 1;
        }
    }

    int front(){
        return l.front();
    }

    int size(){
        return cs;
    }
};

int main(){
    queue q;
    for (int i = 0; i < 10; i++){
        q.push(i);
    }
    cout << q.size() << endl;
    while(!q.isempty()){
        cout << q.front()<<" ";
        q.pop();
    }
    cout << q.size() << endl;
    q.pop();
    cout << q.front();
    cout << q.size() << endl;
}