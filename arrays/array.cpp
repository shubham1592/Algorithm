#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(int a, int b){
    return a>b;
}

void insertionsort(int a[], int n){
    for(int i=1; i<n; i++){
        int e=a[i];
        int j=i-1;
        while(j>=0 and a[j]>e){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=e;
    }
}

//void selectionsort(int a[], int n){
//    for(int i=0; i<n-1; i++){
//        int minindex=i;
//        for(int j=i; j<=n-1; j++){
//                if(a[j]<a[minindex]){
//                    minindex=j;
//                }
//        }
//        swap(a[i],a[minindex]);
//    }
//}

//void bubblesort(int a[], int n){
//    for(int itr=1; itr<n; itr++){
//        for(int j=0; j<=n-itr-1; j++){
//            if(a[j]>a[j+1]){
//                swap(a[j],a[j+1]);
//            }
//        }
//    }
//}
//
//int binary(int a[], int n, int key){
//        int start=0;
//        int endd=n-1;
//        while(start<=endd){
//            int mid=(start+endd)/2;
//            if(a[mid]==key){
//                cout<<mid;
//                break;
//            }
//            else if(a[mid]>key){
//                endd=mid-1;
//            }
//            else {
//                start=mid+1;
//            }
//        }
//        if(start>endd){
//            cout<<"Not found";
//        }
//    }
//

int main(){
//    int key,n,a[1000];
//    cout<<"Enter the size of the array: ";
//    cin>>n;
//    for (int j=0; j<n; j++){
//        cin>>a[j];
//    }
//
//    cout<<"\n"<<"Enter the number you want to search: ";
//    cin>>key;
//    cout<<"\n"<<endl;
////  selectionsort(a,n);
//    bubblesort(a,n);
//    binary(a,n,key);
int n, key;
cin>>n;
int a[1000];
for(int i=0; i<n; i++){
    cin>>a[i];
}
sort(a,a+n,comparator);
for(int i=0; i<n; i++){
    cout<<a[i]<<" ,";
}


return 0;
}
