#include<iostream>
#include<stack>
#include<fstream>
using namespace std;

bool checkvalidation(string s){
    stack<char> stack;
    for(char ch: s){
        if(ch == '(' || ch == '[' ){
            stack.push(ch);
        }
        else if(ch == ')' ||ch == ']' ){
            char a = stack.top();
            if( ch == ')' &&  a != '('){
                return 0;
            }
            else if( ch == ']' &&  a != '[' ){
                return 0;
            }
            else{
                stack.pop();
            }
        }
    }
    return stack.empty();
}
int main(){
    ifstream in("input.txt");
    if( in ){
        cout << "unable to open input .txt " << endl;
    }
    int n = 0;
    in >> n;
    cout << n <<endl;
    in.ignore();
    for(int i = 0 ; i < n ; i++){
        string dummy = "";
        getline(in , dummy);
        if( checkvalidation(dummy) == 1 )
            cout << dummy <<  "            is valid " <<endl;
        else{
            cout << dummy <<  "            is invalid " <<endl;
        }
        in.ignore();
    }
    in.close();
}