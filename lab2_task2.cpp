#include<iostream>
#include<set>
using namespace std;

int intersection(int *a,int *b,set<int> &c,int n){

    
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n ;j++){
            if(a[i] == b[j]){
                c.insert(a[i]);
            }
        }
    }

    return c.size();
}

int main(){

    int n;
    cout<<"enter size of array ";
    cin >> n;

    int *a = new int [n];
    int *b = new int [n];
    set<int> c;

    cout<<"enter elements of array A : { ";
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    cout<<" } "<<endl;

    cout<<"enter elements of array B : { ";
    for(int i = 0 ; i < n; i++){
        cin >> b[i];
    }
    cout<<" } "<<endl;

    cout<<"intersected elements are : ";
    cout << intersection(a,b,c,n);

    cout<<" ";
    for(auto i:c){
        cout<<i<<" ";
    }
}