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

void Book::setAuthor(string author) {
    this->author = author;
}

void Book::setTitle(string title) {
    this->title = title;
}

string Book::toCSV() const {
    stringstream ss;
    ss << this->id << "," << this->title << "," << this->author << "," << this->quantity;
    return ss.str();
}

Book Book::readFromCSV(const string& line) {
    stringstream ss(line);
    string item;
    int id, quantity;
    string title, author;

    getline(ss, item, ','); id = std::stoi(item);
    getline(ss, title, ',');
    getline(ss, author, ',');
    getline(ss, item, ','); quantity = std::stoi(item);
    return Book(id, title, author, quantity);
}

void Book::display() {
    cout << this->id << " - " << this->title << " - " << this->author << " - " << this->quantity << '\n'; 
}