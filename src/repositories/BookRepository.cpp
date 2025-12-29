#include "repositories\Bookrepository.h"
BookRepository::BookRepository(const string& filename) {
    this->filename = filename;
}

vector<Book> BookRepository::getAll() {
    vector<Book> books;
    ifstream file(filename);
    string line;
    while(getline(file, line)) {
        stringstream ss(line);
        string id, title, author, quantity;
        getline(ss, id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, quantity, ',');

        books.emplace_back(Book(stoi(id), title, author, stoi(quantity)));
    }
    return books;
}

void BookRepository::save(const vector<Book>& books) {
    ofstream file(filename);
    for(auto& book : books) {
        file << book.getId() << ','
                << book.getTitle() << ','
                << book.getAuthor() << ','
                << book.getQuantity() << '\n';
    }
}
