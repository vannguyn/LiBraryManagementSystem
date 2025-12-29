#include "models/Book.h"

Book::Book() {
    this->id = 0;
    this->title = "";
    this->author = "";
    this->quantity = 0;
}

Book::Book(int id, string title, string author, int quantity) {
    this->id = id;
    this->title = title;
    this->author = author;
    this->quantity = quantity;
}

int Book::getId() const {
    return this->id;
}

string Book::getTitle() const {
    return this->title;
}

string Book::getAuthor() const {
    return this->author;
}

int Book::getQuantity() const {
    return this->quantity;
}

void Book::setQuantity(int quantity) {
    this->quantity = quantity;
}