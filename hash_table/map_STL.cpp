#include<iostream>
#include<map>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string, int> m;

    // 1. INSERT
    //method 1 to insert elements into the map
    m.insert(make_pair("Mango", 100));

    //method 2 to insert elements into the map
    m["Banana"] = 20;

    //method 3 to insert elements into the map
    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    // 2. SEARCH
    //Search for an element inside the map
    string fruit;
    cin >> fruit;
    auto it = m.find(fruit); //returns the iterator to the fruit if present
    if(it != m.end()){
        cout << endl
             << "Price of " << fruit << " is -> " << m[fruit] << endl;
    }
    else{
        cout << endl
             << fruit << " is not fount!";
    }
    
    //ERASE
    //m.erase(fruit);

    //DISPLAY
    //display/print the map keys or values
    for (auto it = m.begin(); it != m.end();it++){
        cout << it->first << " and " << it->second << endl;
    }
    cout << endl
         << endl;

    //Method 2 for displaying the elements
    for(auto p:m){
        cout << p.first << " and " << p.second << endl;
    }
}