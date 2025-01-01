#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
    friend class StudentBst;

private:
    int id;
    string name;
    float fee;
    Student* left;
    Student* right;

public:
    Student(int a, string b, float c) : id(a), name(b), fee(c), left(nullptr), right(nullptr) {}

    ~Student() {
        delete left;
        delete right;
    }
};

class StudentBst {
private:
    Student* root;

    void inorder(Student* stree) {
        if (stree) {
            inorder(stree->left);
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
            inorder(stree->right);
        }
    }

    void preorder(Student* stree) {
        if (stree) {
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
            preorder(stree->left);
            preorder(stree->right);
        }
    }

    void postorder(Student* stree) {
        if (stree) {
            postorder(stree->left);
            postorder(stree->right);
            cout << "ID: " << stree->id << ", Name: " << stree->name << ", Fee: " << stree->fee << endl;
        }
    }

    void destroy(Student* stree) {
        if (stree) {
            destroy(stree->left);
            destroy(stree->right);
            delete stree;
        }
    }

    Student* search_help(int id, Student* root) {
        if (!root || root->id == id) {
            return root;
        }
        if (id < root->id) {
            return search_help(id, root->left);
        } else {
            return search_help(id, root->right);
        }
    }

public:
    StudentBst() : root(nullptr) {}

    ~StudentBst() {
        destroy(root);
    }

    void insert(int id, string name, float fee) {
        if (!insert_help(id, name, fee)) {
            cout << "Duplicate ID; insertion failed." << endl;
        } else {
            cout << "Insertion successful." << endl;
        }
    }

    bool insert_help(int id, string name, float fee) {
        Student* n = new Student(id, name, fee);
        if (!root) {
            root = n;
            return true;
        }
        Student* current = root;
        Student* parent = nullptr;
        while (current) {
            parent = current;
            if (id < current->id) {
                current = current->left;
            } else if (id > current->id) {
                current = current->right;
            } else {
                delete n;
                return false;
            }
        }
        if (id < parent->id) {
            parent->left = n;
        } else {
            parent->right = n;
        }
        return true;
    }

    void search(int id) {
        Student* result = search_help(id, root);
        if (result) {
            cout << "ID: " << result->id << ", Name: " << result->name << ", Fee: " << result->fee << endl;
        } else {
            cout << "Student not found." << endl;
        }
    }

    void inorder() {
        inorder(root);
    }

    void preorder() {
        preorder(root);
    }

    void postorder() {
        postorder(root);
    }

    void deleteNode(int id) {
        Student* current = root;
        Student* parent = nullptr;

        while (current && current->id != id) {
            parent = current;
            if (id < current->id) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (!current) {
            cout << "Node not found." << endl;
            return;
        }

        if (!current->left && !current->right) {
            if (!parent) {
                root = nullptr;
            } else if (parent->left == current) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        } else if (!current->left || !current->right) {
            Student* child = current->left ? current->left : current->right;
            if (!parent) {
                root = child;
            } else if (parent->left == current) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            Student* successorParent = current;
            Student* successor = current->right;

            while (successor->left) {
                successorParent = successor;
                successor = successor->left;
            }

            current->id = successor->id;
            current->name = successor->name;
            current->fee = successor->fee;

            if (successorParent->left == successor) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }

            current = successor;
        }

        delete current;
    }
};

int main() {
    StudentBst list;
    ifstream inputFile("inputa.txt");

    if (!inputFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    int id;
    string name;
    float fee;

    while (inputFile >> id >> name >> fee) {
        list.insert(id, name, fee);
    }

    inputFile.close();

    cout << "\nSearching..." << endl;
    list.search(28);

    cout << "\nInorder Traversal:" << endl;
    list.inorder();

    cout << "\nPreorder Traversal:" << endl;
    list.preorder();

    cout << "\nDeleting Node with ID 27..." << endl;
    list.deleteNode(27);

    cout << "\nInorder Traversal after Deletion:" << endl;
    list.inorder();

    return 0;
}
