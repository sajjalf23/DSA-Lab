#include<iostream>
using namespace std;

double power( double a , int n ){
    if(n == 0)
        return 1;
    if(n == 1)
        return a;
    return  a * power(a , n-1); 
}

int arraysum( int a[] , int n ){
    if( n == 0 )
        return a[0];
    return a[ n ] + arraysum( a , n-1 ); 
}

void reversestring ( int a[] , int start , int end){
    if( start > end )
        return;
    swap( a[start] , a[end] );
    reversestring( a, start + 1 , end - 1 );
}

bool checksum( int a[], int start ,int end , int k){
    if(start == end+1 )
        return 0;
    for(int i =0 ; i < end ; i++){
        if(i == start ) 
            continue;
        if( a[i] + a[start] == k ){
            cout << " sum of these two elements is " << k << " : ";
            cout << a[start] << " , 0" << a[i] << endl;
            return 1;
        }
    }
    checksum( a, start+1 , end , k);
}


int main(){
    // int x , pow;
    // cout << " enter the number " ;
    // cin >> x ;
    // cout << " enter the power to be found " ;
    // cin >> pow;
    // if( pow < 0)
    //     cout << " invalid input ";
    
    // else 
    //    cout  << "ans is : " << power(x,pow) << endl;



    // int asize ;
    // cout << " enter size " ;
    // cin >> asize;
    // int a[asize];
    // cout << " enter elements of array " ;
    // for( int i = 0 ; i < asize ; i++ ){
    //     cin >> a[i];
    // }
    // cout << "array sum  is " << arraysum(a,asize-1) << endl;




    // int bsize ;
    // cout << " enter size " ;
    // cin >> bsize;
    // int b[bsize];
    // cout << " enter elements of array " ;
    // for( int i = 0 ; i < bsize ; i++ ){
    //     cin >> b[i];
    // }
    // reversestring(b,0,bsize-1);
    // cout << " reverse array is displayed : ";
    // for( int i = 0 ; i < bsize ; i++ ){
    //     cout << b[i];
    // }
    // cout << endl;



    int run = 1;
    do{
        int csize ;
        cout << " enter size " ;
        cin >> csize;
        int c[csize];
        cout << " enter elements of array " ;
        for( int i = 0 ; i < csize ; i++ ){
            cin >> c[i];
        }
        int k ;
        cout << " enter key to be found  " ;
        cin >> k;
        if( checksum( c, 0 , csize-1 , k)== 1)
            cout << "element found " << endl;
        else
            cout << " elements not found "<< endl;
        cout << " do u want to run this function again ";
        cin >> run; 
    }while( run == 1);



// if(start >= end)
    //     return 0;
    // if(a[start] + a[end] == k){
    //     cout << start << " " << end;
    //     return 1;
    // }
    // if(a[start] + a[end] < k)
    //     return checksum(a , start+1 , end , k);
    // return checksum(a , start , end-1 , k );
}