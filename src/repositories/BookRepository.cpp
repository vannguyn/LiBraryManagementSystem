#include "repositories/BookRepository.h"

void BookRepository::load() {
    books.clear();
    ifstream file("data/books.csv");
    string line;
    while(getline(file, line)) {
        books.push_back(Book::readFromCSV(line));
    }
}

void BookRepository::save() {
    ofstream file("data/books.csv");
    for(auto& book : books) {
        file << book.toCSV() << '\n';
    }
}

vector<Book>& BookRepository::getAll() {
    return books;
}

void BookRepository::add(const Book& b) {
    books.push_back(b);
}

void BookRepository::remove(int id) {
    books.erase(std::remove_if(books.begin(), books.end(), [&](Book& b) {return b.getId() == id;}), books.end());
}

