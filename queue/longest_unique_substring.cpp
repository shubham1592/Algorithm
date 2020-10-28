#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[] = "abccdcdefghjklo";
    int n = strlen(a);
    int cur_len = 1;
    int max_len = 1;
    int visited[256];
    for (int i = 0; i < 256; i++){
        visited[i] = -1;
    }
    visited[a[0]] = 0;
    for (int i = 1; i < n; i++){
        int last_occ = visited[a[i]];

        if(last_occ == -1 || i-cur_len>last_occ){
            cur_len += 1;
            max_len = max(cur_len, max_len);
        }   
        else{
            if(cur_len>max_len){
                max_len = cur_len;
            }
            cur_len = i - last_occ;
        }
        visited[a[i]] = i;
    }
    if(cur_len>max_len){
        max_len > cur_len;
    }
    cout << max_len << endl;
    return 0;
}