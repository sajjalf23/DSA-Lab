#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Student {
    friend class StudentList;

private:
    int id;      
    string name;    
    float cgpa;    
    Student* next;  

public:
    Student(int id, string name, float cgpa, Student* next = nullptr)
        : id(id), name(name), cgpa(cgpa), next(next) {}

    void studentDetails() const {
        cout << "ID: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
    }
};

class StudentList {
private:
    Student* head;   
    Student* cursor; 

public:
    StudentList() : head(nullptr), cursor(nullptr) {}

    ~StudentList() {
        while (head) {
            Student* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const Student& newStd) {
        Student* newNode = new Student(newStd.id, newStd.name, newStd.cgpa);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = cursor->next;
            cursor->next = newNode;
        }
        cursor = newNode;
    }

    void remove(int id) {
        if (!head) return;

        Student* prev = nullptr;
        Student* current = head;

        while (current && current->id != id) {
            prev = current;
            current = current->next;
        }

        if (current) {
            if (prev) prev->next = current->next;
            else head = current->next;

            if (cursor == current) cursor = current->next ? current->next : head;
            delete current;
        }
    }

    void search(float cgpa) const {
        Student* current = head;
        bool found = false;

        while (current) {
            if (current->cgpa == cgpa) {
                current->studentDetails();
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << "No student found with CGPA: " << cgpa << endl;
        }
    }

    void replace(const Student& newStd) {
        Student* current = head;

        while (current && current->id != newStd.id) {
            current = current->next;
        }

        if (current) {
            current->name = newStd.name;
            current->cgpa = newStd.cgpa;
            cursor = current;
        } else {
            insert(newStd);
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void gotoBeginning() {
        cursor = head;
    }
    void gotoEnd() {
        if (head) {
            cursor = head;
            while (cursor->next) {
                cursor = cursor->next;
            }
        }
    }

    bool gotoNext() {
        if (cursor && cursor->next) {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    void showStructure() const {
        if (isEmpty()) {
            cout << "Empty list" << endl;
            return;
        }

        Student* current = head;
        while (current) {
            current->studentDetails();
            current = current->next;
        }
    }
};

int main() {


	
    StudentList list;

    ifstream inputFile("input123.txt");

    if (!inputFile) {
        cerr << " Unable to open input file 'input.txt'." << endl;
        return 1;
    }

    string line;


    while (getline(inputFile, line)) {

        if (line.empty()) continue;

        int id;
        string name;
        float cgpa;

        stringstream idStream(line);
        idStream >> id;
        getline(inputFile, name);    
        inputFile >> cgpa;          
        inputFile.ignore();         

        list.insert(Student(id, name, cgpa));
    }




    inputFile.close();

    cout << "Initial list structure:" << endl;



    list.showStructure();

    cout << "\nSearching for CGPA 3.22:" << endl;




    list.search(3.22);

    cout << "\nRemoving student with ID 1:" << endl;



    list.remove(1);




    list.showStructure();

    cout << "\nReplacing student with ID 2:" << endl;




    list.replace(Student(2, "lubna", 3.9));




    list.showStructure();




    cout << "\nTesting navigation:" << endl;





    list.gotoBeginning();



    cout << "Cursor at beginning:" << endl;




    list.showStructure();




    list.gotoEnd();



    cout << "Cursor at end:" << endl;


    list.showStructure();

    cout << "\nMoving cursor to next:" << endl;

    if (list.gotoNext()) {
        
		
		cout << "Cursor moved to the next student. List structure:" << endl;
        
	    list.showStructure();

    } 
	else {
        
		cout << "Cursor cannot move next." << endl;
    }

    cout << "\nFinal list structure:" << endl;
   
    list.showStructure();

    return 0;
}