#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

template<typename T>
class node{
    public:
        string key;
        T value;
        node<T> *next;

        node(string key, T val){
            this->key = key;
            value = val;
            next = NULL;
        }

        ~node(){
            if(next!=NULL){
                delete next;
            }
        }
};

template<typename T>
class hashtable{
    node<T> **table;
    int current_size;
    int table_size;

    int hashfn(string key){
        int idx = 0;
        int p = 1;
        for (int j = 0; j < key.length(); j++){
            idx = idx + (key[j] * p) % table_size;
            idx = idx % table_size;
            p = (p * 27) % table_size;
        }
        return idx;
    }

    public:
    hashtable(int ts=7){
        table_size = ts;
        table = new node<T> *[table_size];
        current_size = 0;
        for(int i = 0; i < table_size; i++){
            table[i] = NULL;
        }
    }

    void insert(string key, T value){
        int idx = hashfn(key);
        node<T> *n = new node<T>(key, value);
        n->next = table[idx];
        table[idx] = n;
        current_size++;
    }

    void print(){
        for (int i = 0; i < table_size; i++){
            cout << "Bucket " << i << " -> ";
            node<T> *temp = table[i];
            while(temp!=NULL){
                cout << temp->key << " -> ";
                temp = temp->next; 
            }
            cout << endl;
        }
    }

    // T search(string key){

    // }

    // void erase(string key){
        
    // }
};

int main(){
    hashtable<int> price_menu;
    price_menu.insert("Burger", 60);
    price_menu.insert("Noodles", 80);
    price_menu.insert("Sandwich", 45);
    price_menu.insert("Momos", 50);
    price_menu.insert("Coke", 30);
    price_menu.insert("Coffee", 100);
    price_menu.insert("Pizza", 150);

    price_menu.print();

    return 0;
}