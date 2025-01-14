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
            head = cursor = newNode;
        } else {
            newNode->next = cursor->next;
            cursor->next = newNode;
            cursor = newNode;
        }
    }

    void remove(int id) {
        if (!head) {
            cout << "List is empty. Cannot remove student." << endl;
            return;
        }

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
            cout << "Student with ID " << id << " removed successfully." << endl;
        } else {
            cout << "Student with ID " << id << " not found." << endl;
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
            cout << "Student with ID " << newStd.id << " replaced successfully." << endl;
        } else {
            insert(newStd);
            cout << "Student with ID " << newStd.id << " added as it did not exist." << endl;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void gotoBeginning() {
        cursor = head;
        if (!cursor) {
            cout << "List is empty. Cursor cannot be moved." << endl;
        }
    }

    void gotoEnd() {
        cursor = head;
        if (!cursor) {
            cout << "List is empty. Cursor cannot be moved." << endl;
            return;
        }
        while (cursor->next) {
            cursor = cursor->next;
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
            cout << "List is empty." << endl;
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
        cerr << "Error: Unable to open input file 'input123.txt'." << endl;
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
    list.replace(Student(2, "Lubna", 3.9));
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
        cout << "Cursor moved to the next student." << endl;
    } else {
        cout << "Cursor cannot move next." << endl;
    }
    list.showStructure();

    cout << "\nFinal list structure:" << endl;
    list.showStructure();

    return 0;
}
