#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Book
{
    friend class BookList;

private:

    int id;
    string title;
    float price;
    Book *next;
    Book *prev;
    

public:



    Book(int id, string title, float price, Book *next = nullptr, Book *prev = nullptr)
        : id(id), title(title), price(price), next(next), prev(prev) {}




    void bookDetails() const
    {
        cout << "ID: " << id << "    , Title: " << title << "      , Price: " << price << endl;
    }
};

class BookList
{
private:
    Book *head;
    Book *cursor;

public:
    BookList() : head(nullptr), cursor(nullptr) {}

    ~BookList()
    {
        while (head)
        {
            Book *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const Book &newItem)
    {
        Book *newBook = new Book(newItem.id, newItem.title, newItem.price);
        if (!head)
        {
            head = newBook;
            cursor = head;
        }
        else
        {
            newBook->next = cursor->next;
            newBook->prev = cursor;


            if (cursor->next)
                cursor->next->prev = newBook;



            cursor->next = newBook;
            cursor = newBook;
        }
    }

    void remove()
    {
        if (!cursor)
            return;

        Book *temp = cursor;


        if (cursor->prev)
            cursor->prev->next = cursor->next;


        if (cursor->next)
            cursor->next->prev = cursor->prev;


        if (cursor == head)
            head = cursor->next;


        cursor = (cursor->next) ? cursor->next : head;


        delete temp;
    }

    void search(string title)
    {
        Book *temp = head;
        bool found = false;
        while (temp)
        {
            if (temp->title == title)
            {
                temp->bookDetails();
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "No book with the title " << title << "  found." << endl;
        }
    }

    void replace(const Book &newItem)
    {
        if (cursor)
        {
            cursor->id = newItem.id;
            cursor->title = newItem.title;
            cursor->price = newItem.price;

        }
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void gotoBeginning()
    {
        cursor = head;
    }

    void gotoEnd()
    {
        if (!head)
            return;
        while (cursor->next)
        {
            cursor = cursor->next;
        }
    }

    bool gotoNext()
    {
        if (cursor && cursor->next)
        {
            cursor = cursor->next;
            return true;
        }
        return false;
    }

    bool gotoPrior()
    {
        if (cursor && cursor->prev)
        {
            cursor = cursor->prev;
            return true;
        }
        return false;
    }

    Book getCursor() const
    {
        if (cursor)
        {
            return *cursor;
        }
        throw runtime_error("Cursor is null.");
    }

    void showStructureForward() const
    {
        if (!head)
        {
            cout << "Empty list" << endl;
            return;
        }
        Book *temp = head;
        while (temp)
        {
            temp->bookDetails();
            temp = temp->next;
        }
    }

    void showStructureReverse() const
    {
        if (!head)
        {
            cout << "Empty list" << endl;
            return;
        }
        Book *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        while (temp)
        {
            temp->bookDetails();
            temp = temp->prev;
        }
    }
};

int main()
{
    BookList list;
    ifstream inputFile("input.txt");

    if (!inputFile)
    {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    int id;
    string title;
    float price;

    while (inputFile >> id)
    {
        inputFile.ignore();
        getline(inputFile, title);

        inputFile >> price;
        inputFile.ignore();


        Book book(id, title, price);
        list.insert(book);
    }

    inputFile.close();

    cout << "Books in forward order:" << endl;
    list.showStructureForward();

    cout << "\nBooks in reverse order:" << endl;
    list.showStructureReverse();

    return 0;
}