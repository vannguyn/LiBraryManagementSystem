#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Book {
    private:
    int id;
    string title;
    string author;
    int quantity;

    public:
    // Constructor
    Book();
    Book(int id, string title, string author, int quantity);

    // Getter
    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    int getQuantity() const;

    // Setter
    void setQuantity(int quantity);
    void setAuthor(string author);
    void setTitle(string title);

    string toCSV() const;
    static Book readFromCSV(const string& line);
    // Display
    void display();
};
#endif