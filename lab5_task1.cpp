#include<iostream>
using namespace std;

template<class T>
class stack{
    private:

        T* arr;
        int top;
        const int max_size;
        
    public:

        stack(int n):max_size(n){
            arr = new T[max_size];
            top = -1;
        }

        stack():max_size(10){
            arr = new T[max_size];
            top = -1;
        }

        ~stack(){
            delete []arr;
        }

        bool isempty(){
            if(top == -1){
                return 1;
            }
            return 0;
        }

        bool isfull(){
            if(top == max_size-1){
                return 1;
            }
            return 0;
        }

        void push(const T newitem){
            if( isfull() ){
                cout << " stack overflow " << endl;
            }
            else{
                top++;
                arr[top] = newitem;
            }
        }

        void pop(){
            if( isempty() ){
                cout << " stack is empty " << endl;
            }
            else{
                top--;
            }
        }

        void clear(){
            top = -1;
        }
  
        T togettop(){
            if(isempty()){
                cout << " stack is empty " << endl;
            }
            else{
                return arr[top];
            }
        }

        void showstructure(){
            if(isempty()){
                cout << " stack is empty " << endl;
            }
            else{
                cout << "max_size" << max_size << endl;
                for( int i = top ; i >=0 ; i--){
                    if(i == top){
                        cout <<  arr[i] << " <-  top element  " << endl;
                    }
                    else
                        cout << arr[i] << endl;
                }
            }
        }


};

int main(){
    // stack<int> s1;
    // s1.push(2);
    // s1.push(3);
    // s1.push(4);
    // s1.push(5);
    // s1.showstructure();
    // cout << "top element = " << s1.togettop() << endl;
    // s1.pop();
    // s1.showstructure();
    // s1.clear();
    // s1.showstructure();


    // stack<float> s1;
    // s1.push(2.3);
    // s1.push(3.5);
    // s1.push(4.7);
    // s1.push(5.2);
    // s1.showstructure();
    // cout << "top element = " << s1.togettop() << endl;
    // s1.pop();
    // s1.showstructure();
    // s1.clear();
    // s1.showstructure();


    stack<string> s1;
    s1.push("sajjal");
    s1.push("bahi");
    s1.push("mama");
    s1.push("papa");
    s1.showstructure();
    cout << "top element = " << s1.togettop() << endl;
    s1.pop();
    s1.showstructure();
    s1.clear();
    s1.showstructure();
}
