#include<iostream>
using namespace std;

int findkthsmallest(int *a,int n, int k){
                                                    // time complexity o(n^2)
    int min = 1000000,dummy = 0;

    while(k){
    for(int i = 0 ; i < n ;i++){
        if(a[i] < min){
            min = a[i];
            dummy= i;
        }
    }
        if(k == 1)  
           return min;
        k--;
        min = 1000000;
        a[dummy] = 1000000;
    }
    return -1;
}

int main(){

    int n;
    cout<<"enter size of array ";
    cin >> n;

    int k;
    cout<<" k th : ";
    cin >> k;

    int *a = new int [n];

    cout<<"enter elements of array A : "<<endl;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }

    cout<< findkthsmallest(a,n,k);    
}