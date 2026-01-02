#ifndef _BOOKREPOSITORY_H_
#define _BOOKREPOSITORY_H_

#include "repositories/IBookRepository.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class BookRepository : public IBookRepository {
    private:
    vector<Book> books;

    public:
    void load() override;
    void save() override;
    vector<Book>& getAll() override;
    Book* findById(int id) override;
    void add(const Book& b) override;
    void remove(int id) override;
};

#endif