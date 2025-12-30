#ifndef _BOOKREPOSITORY_H
#define _BOOKREPOSITORY_H

#include "repositories/IBookRepository.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class BookRepository : public IBookRepository {
    private:
    string filename;

    public:

    BookRepository(const string& filename);

    vector<Book> getAll() override;
    void save(const vector<Book>& books) override;
};

#endif