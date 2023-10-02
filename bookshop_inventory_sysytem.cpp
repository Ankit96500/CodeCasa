/*
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class book
{
    unsigned int id;
    string book_name;
    string bk_name;
    string bk_author;
    int quantity;

public:
    void bk_add();
    void bk_display();
};

// -----------------
// Global Variables
// -----------------

vector <book> books;

void book::bk_add()
{
    cout << "Enter unique id for the book: \n";
    cin >> id;

    getline(cin, book_name);
    cout << "Enter the name of the book: \n";
    getline(cin, bk_name); 
    cout << "Enter the author of the book: \n";
    getline(cin, bk_author);
    quantity = 1;
    cout << "\n" << "\n" << "Book Recorded Successfully" << "\n" << "\n";
}

void book::bk_display()
{
    for(auto b: books)
    {

        cout << "Name of book: " << b.bk_name << "\n";
        cout << "Author of book: " << b.bk_author << "\n";
        cout << "Quantity available: " << b.quantity << "\n";
        cout << "\n" << "\n" << "\n";
    }
}


// -------------------
// FUNCTIONS
// -------------------

void book_menu();

void main_menu()
{
    int c;
    cout << "--------------------------------------------------------" << "\n";
    cout << "              BOOKSHOP MANAGEMENT SYSTEM" << "\n";
    cout << "--------------------------------------------------------" << "\n";
    cout << "      1.  BOOKS" << "\n";
    cout << "      2.  EXIT" << "\n" << "\n" << "\n";
    cout << "Enter your choice" << "\n";
    cin >> c;
    switch (c)
    {
    case 1:
        book_menu();
        break;
    
    case 2:
        exit(1);
        break;
    
    default:
        cout << "Wrong Input" << "\n" << "\n" << "Please try again";
        break;
    }
    return;
}

void book_menu()
{
    int c;
    book b;
    cout << "-----------------------------------------------" << "\n";
    cout << "              BOOK MENU" << "\n";
    cout << "-----------------------------------------------" << "\n";
    cout << "      1.  ADD" << "\n";
    cout << "      2.  DISPLAY" << "\n";
    cout << "      3.  BUY BOOKS" << "\n" << "\n" << "\n";
    cin >> c;
    switch (c)
    {
    case 1:
        b.bk_add();
        books.push_back(b);
        break;
    case 2:
        b.bk_display();
        break;
    default:
        cout << "Wrong Input" << "\n" << "\n" << "Please try again";
        break;
    }
}

int main() 
{
    while(1)
    {
        main_menu();
    }
    return 0;
}




