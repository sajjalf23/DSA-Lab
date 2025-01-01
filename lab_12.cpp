#include <iostream>
#include <string>

using namespace std;

class Student
{
    friend class StudentMaxHeap;

private:
    int rollNo;
    double cgpa;

public:
    Student(){
    }
    Student(int a, double b)
    {
        rollNo = a;
        cgpa = b;
    }
};

class StudentMaxHeap
{
private:
    Student *arr;
    int curSize;
    int maxSize;

public:
    StudentMaxHeap(){
        maxSize = 0;
        curSize = 0;
        arr = new Student[0];
    }
    StudentMaxHeap(int size)
    {
        maxSize = size;
        curSize = 0;
        arr = new Student[maxSize];
    }
    ~StudentMaxHeap()
    {
        delete arr;
    }
    bool isfull()
    {
        if (curSize == maxSize)
        {
            return true;
        }
        return false;
    }
    bool isempty()
    {
        if (curSize == 0)
        {
            return true;
        }
        return false;
    }
    void swap(int a, int b){
        Student temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    void heapifyup(int index){
        if(index > 0){
            int parent = (index-1)/2;
            if((arr[parent]).cgpa < (arr[index]).cgpa){
                swap(index,parent);
            }
            else if(((arr[parent]).cgpa == (arr[index]).cgpa) || ((arr[parent]).rollNo > (arr[index]).rollNo)){
                swap(index,parent);
            }
            index = parent;
            heapifyup(index);
        }
    }
    bool insert(int rollno, double cgpa)
    {
        if(curSize < maxSize){
        int index = curSize;
        arr[index] = Student(rollno, cgpa);
        curSize++;
        heapifyup(index);
        return true;
        }
        return false;
    }
     void heapifydown(int index){
        if(index < curSize){
        int big = index;
        int left = (index*2)+1;
        int right = (index*2)+2;
            if(left < curSize && (arr[big]).cgpa < (arr[left]).cgpa){
                big = left;
            }
            if(left < curSize &&  (((arr[big]).cgpa == (arr[left]).cgpa) || ((arr[big]).rollNo > (arr[left]).rollNo))){
                big = left;
            }
            if(right < curSize && (arr[big]).cgpa < (arr[right]).cgpa){
                big = right;
            }
            if(right < curSize && (((arr[big]).cgpa == (arr[right]).cgpa) || ((arr[big]).rollNo > (arr[right]).rollNo))){
                big = right;
            }
            if(big != index){
                swap(big , index);
                heapifydown(big);
            }
        }
    }
    bool levelorder(){
        bool flag = false;
        for(int i=0 ; i < curSize ; i++){
            cout << "RollNo : " << arr[i].rollNo << " Cgpa : " << arr[i].cgpa << endl;
            flag = true;
        }
        return flag;
    }
    bool remove(){
        if(!isempty()){
            arr[0] = arr[curSize-1];
            curSize--;
            heapifydown(0);
            return true;
        }
        return false;
    }
    
    bool display(){
        bool flag = false;
        for(int i=0 ; i < curSize ; i++){
            cout << "RollNo : " << arr[i].rollNo << " Cgpa : " << arr[i].cgpa << endl;
            flag = true;
        }
         return flag;
    }
    void max(){
         cout << "RollNo : " << arr[0].rollNo << " Cgpa : " << arr[0].cgpa << endl;
    }
};
void menu(){
    StudentMaxHeap h1(5);
    h1.insert(101,3.9);
    h1.insert(102,3.8);
    h1.insert(103,3.9);
    h1.insert(104,4.0);
    while(true){
    int x;
    cout << "enter which functionality u want ";
    cin >> x;
    if(x == 0){
        break;
    }
    if(x == 2){
        h1.max();
        if(h1.remove())
        cout << "successfully removed " <<endl;
    }
    if(x == 3){
        cout << "descending Order " <<endl;
        if(!h1.display()){
           cout << "empty " <<endl;
        }
    }
    if(x == 4){
        cout << "Level Order " <<endl;
        if(!h1.levelorder()){
           cout << "empty " <<endl;
        }
    }
    }
}
int main(){
    menu();
}








// StudentMaxHeap* temp = new StudentMaxHeap;
//         temp->maxSize =  this->maxSize;
//         temp->curSize = this ->curSize;
//         temp->arr = new Student[maxSize];
//         for(int i=0 ; i < this->curSize ; i++){
//             temp->arr[i] = (arr[i].rollNo, arr[i].cgpa);
//             cout<<"j"<<endl;
//         }
        
//         temp->levelorder();

//         while(curSize > 0){
//         temp->arr[0] = temp->arr[curSize-1];
//         cout << "RollNo : " << temp->arr[0].rollNo << " Cgpa : " << temp->arr[0].cgpa << endl;
//         heapifydown(0);
//         }
//         cout << "RollNo : " << this->arr[curSize-1].rollNo << " Cgpa : " << this->arr[curSize-1].cgpa << endl;
//         delete []temp->arr;
//         delete temp;