#ifndef _IBOOKREPOSITORY_H_
#define _IBOOKREPOSITORY_H_
#include <vector>
#include "models/Book.h"

class IBookRepository {
    public:
    virtual vector<Book> getAll() = 0;
    virtual void save(const vector<Book>& books) = 0;
    virtual ~IBookRepository() = default;
};
#endif