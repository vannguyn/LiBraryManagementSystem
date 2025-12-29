#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
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
};
#endif