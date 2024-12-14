#include<iostream>
using namespace std;

struct point3d{

    float x , y , z;

    point3d() : x(-1) , y(-1) , z(-1) {}

    point3d(float a,float b,float c) : x(a) , y(b) , z(c) {}

};

class pointlist{

private:

    point3d* list;
    int maxsize;
    int currsize;
    int cursor;

public :

    pointlist(int s) : maxsize(s) , currsize(0) , cursor(-1) {

        list = new point3d [s];

    }

    ~pointlist(){

        delete []list;

    }
    
    bool isempty(){

        if( currsize == 0){
            return true;
        }

        return false;

    }

    bool isfull(){

        if( (currsize) == (maxsize-1)){
            return true;
        }

        return false;

    }

    void insert(point3d newpoint){

        if( isfull() ){
            cout << "list is full no new point can be inserted " << endl;
        }

        else if( !isempty() ){
            list[currsize] = newpoint;
            currsize++;
            cursor = currsize - 1;
        }

        else{    
            list[0] = newpoint;
            cursor = 0;
            currsize++;
        }

    }
    
    void showstructure(){

        if(isempty()){
           cout << "list is empty " << endl; 
        }

        cout << "--------------------------------------------------" << endl;
        cout << "list items : " << endl;
        cout << "    max size : " << this->maxsize << endl;  
        cout << "    current size : "<< this->currsize << endl;
        cout << "    cursor " << this->cursor << endl;

        for(int i = 0; i < currsize ; i++){

            cout << "list element # " << i << "    { " ;
            cout << " x :" << list[i].x  << " , ";
            cout << " y :" << list[i].y  << " , ";
            cout << " z :" << list[i].z  << " } "  << endl;

        }
        cout << "--------------------------------------------------" << endl;

    }

    point3d getcursor(){

        if(isempty()){
            cout <<" no element is in the list "<< endl;
            point3d a (-1,-1,-1);
            return a;
        }
        
        point3d copy = list[cursor];
        return copy;

    }

    void gotobegining(){

        if(!isempty()){
            cursor = 0;
        }

    }

    void gotoend(){

        if(!isempty()){
            cursor = currsize - 1;
        }

    }

    bool gotonext(){

        if(cursor != (currsize - 1 )){
            cursor ++;
            return true;
        }

        cout << "cursor is at the currsize & unable to move " << endl;
        return false;
    }

    bool gotoprior(){

        if(cursor != 0){
            cursor --;
            return true;
        }

        cout << "cursor is at the begining & unable to move " << endl;
        return false;
    }

    void clear(){

        currsize = 0;
        cursor = -1;

    }

    bool replace(point3d newpoint){

        if( cursor < 0 || cursor >= maxsize){
            return false;
        }

        list[cursor] = newpoint;
        return true;
    }

    void remove(){
  
        if(isempty()){
            cout << " list is empty cannot be removed " << endl;
        }

        list[cursor].x = -1;
        list[cursor].y = -1;
        list[cursor].z = -1;

        if(cursor == (currsize -1)){
            cursor = 0;
        } 

        if( cursor == 0){
            cursor = -1;
        }

    }
};

int main(){

    point3d a (9.8,7.8,5.6);
    point3d b (0.9,8.9,7.6);
    point3d c (3.4,5.6,7.8);
    point3d d (1.2,3.4,5.6);

    pointlist p1 (7);
    p1.insert(a);
    p1.insert(b);
    p1.insert(c);
    p1.insert(d);

    cout << endl;
    p1.showstructure();

    cout << endl;
    cout << " let^s check if list is empty or not  = " ;

    if(p1.isempty())
        cout << " list is empty " <<endl;
    else
        cout << " list is not empty " <<endl;


    cout << endl;
    cout << " let^s check if list is full or not  = " << endl;

    if(p1.isfull())
        cout << " list is full " <<endl;
    else
        cout << " list is not full " <<endl;

    cout << endl;

    point3d dummy = p1.getcursor();
    cout << " element  of list at cursor : " << endl;
    cout << "    { " ;
    cout << " x :" << dummy.x  << " , ";
    cout << " y :" << dummy.y  << " , ";
    cout << " z :" << dummy.z  << " } "  << endl;

    cout << endl;
    p1.gotobegining();
    p1.showstructure();

    
    cout << endl;
    p1.gotoend();
    p1.showstructure();

    cout << endl;
    p1.gotonext();
    p1.showstructure();

    cout << endl;
    p1.gotoprior();
    p1.showstructure();

    cout << endl;
    p1.replace(a);
    p1.showstructure();


    cout << endl;
    p1.remove();
    p1.showstructure();

    p1.clear();
}