#include<iostream>
#include<set>
using namespace std;

int intersection(int *a,int *b,set<int> &c,int n){

     
    for(int i = 0 ; i < n; i++){

        int start = 0 , end = n-1 , mid = 0;
        while(start <= end){

            mid = start +((end-start)/2);

            if(a[i] == b[mid]){
                c.insert(a[i]);
                break;
            }

            else if(a[i] > b[mid]){
                start = mid + 1;
            }

            else{
                end = mid - 1;
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

    cout<<"enter elements of array A : {"<<endl;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    cout<<" } "<<endl;

    cout<<"enter elements of array B : {"<<endl;
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